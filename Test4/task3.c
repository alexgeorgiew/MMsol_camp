#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>
#define THREAD_COUNT 5

int n,m;
double *results;
double **arr;
int *indexes;

void freeall()
{
	for(int i=0;i<n;i++)
	{
		free(arr[i]);
	}
	free(arr);
	free(results);
	free(indexes);
}

double vector(double* nums)
{
	double result=0.0;
	for(int i=0;i<m;i++)
	{
		result+=nums[i]*nums[i];
	}
	return sqrt(result);
}

void* handler(void* arg)
{
	int index=*(int*)arg;
	while(1)
	{
		if(index>=n)return NULL;

                results[index]=vector(arr[index]);
		index+=THREAD_COUNT;
	}
      
}

int main(int argc,char **argv)
{

	if(argc!=3)
	{
		fprintf(stderr,"Program needs exactly 2 arguments\n");
		return -1;
	}

	n=atoi(argv[1]);
	m=atoi(argv[2]);
	arr=(double**)malloc(sizeof(double*)*n);

	for(int i=0;i<n;i++)
	{
		arr[i]=(double*)malloc(sizeof(double)*m);
	}


	for(int i=0;i<n;i++)
	{
          for(int j=0;j<m;j++)
	  {
             scanf("%lf",arr[i]+j);
	  }
	}

	char name[100];
	scanf("%s",name);
         
	pthread_t* th=(pthread_t*)malloc(sizeof(pthread_t)*THREAD_COUNT);
	results=(double*)malloc(sizeof(double)*n);
	indexes=(int*)malloc(sizeof(int)*THREAD_COUNT);
	for(int i=0;i<THREAD_COUNT;i++)indexes[i]=i;

	for(int i=0;i<THREAD_COUNT;i++)
	{
		if(pthread_create(th+i,NULL,handler,(void*)(indexes+i)))
		{
			fprintf(stderr,"Error with creating thread\n");
			freeall();
			free(th);
			return -1;
		}
	}

	for(int i=0;i<THREAD_COUNT;i++)
	{
		if(pthread_join(th[i],NULL))
		{
			fprintf(stderr,"CAn not join thread\n");
			freeall();
			free(th);
			return -1;
		}
	}

	

	FILE *f=fopen(name,"w");
	if(f==NULL)
	{
		fprintf(stderr,"CAn not open file\n");
		freeall();
		free(th);
		return -1;
	}

	for(int i=0;i<n;i++)
	{
		fprintf(f,"%lf\n",results[i]);
        }

	freeall();
	free(th);
         fclose(f);
	return 0;


}
