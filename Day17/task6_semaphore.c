#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>


int count=0;
sem_t mutex;
void* fun1(void* arg)
{
      for(int i=0;i<10000;i++)
      {
	sem_wait(&mutex);
	count++;
	sem_post(&mutex);
      }
}








int main()
{	
	pthread_t th1,th2;
        sem_init(&mutex,0,1);
	if( pthread_create(&th1,NULL,fun1,NULL))
	{
           return -1;
	}

	if( pthread_create(&th2,NULL,fun1,NULL))
	{
		return -1;
	}
	
	if(pthread_join(th1,NULL))
	{
		return -1;
	}
	if(pthread_join(th2,NULL))
	{
		return -1;
	}

	sem_destroy(&mutex);

	printf("count=%d\n",count);

}
