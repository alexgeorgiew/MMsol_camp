#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/wait.h>

sem_t mutex;
char* msg;
void* print(void* args)
{
     int thread_num=*(int*)args;
     sem_wait(&mutex);
     printf("MSG:%s PID:%d Thread num:%d\n",msg,getpid(),thread_num);
     sem_post(&mutex);     
}    				
     				
int main(int argc,char **argv)
{    				
    	  if(argc!=4)
          {
     	     fprintf(stderr,"Program needs exactly 3 arguments\n");
     	     return -1;
          }
     	  sem_init(&mutex,0,1);			
          int p=atoi(argv[1]);
     	  int t=atoi(argv[2]);
          msg=argv[3];

	 for(int k=0;k<p;k++) 
	 {
		 int pid=fork();
		 if(pid==-1)
		 {
			 fprintf(stderr,"Can not fork\n");
		 }
		 else if(pid==0)
		 {
                      pthread_t *arr=(pthread_t*)malloc(t*sizeof(pthread_t));
		      int *numbers=(int*)malloc(sizeof(int)*t);
                      for(int i=0;i<t;i++)
                      {
			 numbers[i]=i;
     	                 if(pthread_create(arr+i,NULL,print,(void*)(numbers+i) ))
     	                 {
                               fprintf(stderr,"Can not craete pthread\n");
			       free(arr);
			       free(numbers);
     	                       return -1;
	                 }
	              }

	              for(int i=0;i<t;i++)
	              {
		         if(pthread_join(arr[i],NULL))
		         {
				 free(arr);
				 free(numbers);
			         fprintf(stderr,"Can not join thread\n");
			         return -1;
		         }
	              }

		      free(arr);
		      free(numbers);
		      return 0;
		 }
	 }
         

	 for(int k=0;k<p;k++)
	 {
		 wait(NULL);
	 }

	 sem_destroy(&mutex);
	 return 0;
}
