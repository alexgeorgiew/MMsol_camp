#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

int total=0;
sem_t mutex;
char **names;
int *indext;

int ones(int mask)
{
	int res=0;
	for(int i=0;i<32;i++)
	{
		if(mask&(1<<i))
		{
			res++;
		}
	}
	return res;
}
void*  handler(void *arg)
{
	int ind=*(int*)arg;
	char *file=names[ind+1];

	int f=open(file,O_RDONLY);
	if(f==-1)
	{
		fprintf(stderr,"file%d - Can not open file\n",ind+1);
		return 	NULL;
	}
	int num,local=0;
	while(read(f,&num,sizeof(int)))
	{
		sem_wait(&mutex);
		total+=ones(num);
		sem_post(&mutex);
		local+=ones(num);
	}
	fprintf(stdout,"file%d - %d\n",ind+1,local);
}


int main(int argc,char **argv)
{
	names=argv;
	if(argc<2)
	{
		char msg[]="Program needs arguments\n";
		write(2,msg,strlen(msg));
		return -1;
        }

	pthread_t *arr=(pthread_t*)malloc(sizeof(pthread_t)*(argc-1));
	sem_init(&mutex,0,1);

	indext=(int *)malloc(sizeof(int)*(argc-1));
	for(int i=0;i<argc-1;i++)
	{
		indext[i]=i;
		if(pthread_create(arr+i,NULL,handler,(void*)(indext+i)))
		{
			char msg[]="Can not create thread\n";
			write(2,msg,strlen(msg));
			free(arr);
			free(indext);
			return -1;
		}
	}


	for(int i=0;i<argc-1;i++)
	{
		if(pthread_join(arr[i],NULL))
		{
			char msg[]="Can not join thread\n";
			write(2,msg,strlen(msg));
			free(arr);
			free(indext);
			return -1;
		}
	}

        fprintf(stdout,"Total - %d\n",total);
	free(arr);
	free(indext);
	sem_destroy(&mutex);

	return 0;
}
