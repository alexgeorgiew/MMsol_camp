#include <string.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>

sem_t mutex;

void* print(void *args)
{
	sem_wait(&mutex);

	char sym;
	for(int i=0;i<10;i++)
	{
          sym=65+rand()%26;
	  printf("%c",sym);
	}
        printf("\n");

	sem_post(&mutex);
}




int main(int argc,char** argv)
{
	if(argc!=2)
	{
		fprintf(stderr,"Wrong number of arguments\n");
		return -1;
	}
	int num=atoi(argv[1]);
	if(num<1)
	{
		fprintf(stderr,"Input number must be positive integer\n");
		return -1;
	}
	
	sem_init(&mutex,0,1);
	pthread_t *arr=(pthread_t *)malloc(sizeof(pthread_t)*num);
        if(arr==NULL)
	{
		fprintf(stderr,"Can not allocate memory for thread\n");
                return -1;
	}
         
	srand(time(NULL));
	for(int i=0;i<num;i++)
	{
		if(pthread_create(arr+i,NULL,print,NULL))
		{
			fprintf(stderr,"Can not create thread\n");
			sem_destroy(&mutex);
			return -1;
		}
	}
         

	for(int i=0;i<num;i++)
	{
		if(pthread_join(arr[i],NULL))
		{
			fprintf(stderr,"Error with join pthread\n");
			sem_destroy(&mutex);
			return -1;
		}
	}


	sem_destroy(&mutex);
	free(arr);
	return 0;
}
