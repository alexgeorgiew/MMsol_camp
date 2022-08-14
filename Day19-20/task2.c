#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>

sem_t mutex;

int comparator(const void* a,const void* b)
{
	int left=*(int*)a;
	int  right=*(int*)b;
	return left-right;
}

void* sort(void *args)
{
      char *file=(char*)args;
      int fd=open(file,O_RDONLY);
      if(fd==-1)
      {
          sem_wait(&mutex);
	  fprintf(stderr,"Can not open file to read");
	  sem_post(&mutex);
	  return NULL;
      }
      

      int lastpos=lseek(fd,0,SEEK_END);
      if(lastpos%4!=0 || lastpos==0)
      {
	      sem_wait(&mutex);
	      fprintf(stderr,"File is not in correct format\n");
              sem_wait(&mutex);
	      close(fd);
	      return NULL;
      }
      lseek(fd,0,SEEK_SET);
      int *nums=(int*)malloc(lastpos);
      
      if(read(fd,nums,lastpos)!=lastpos)
      {
	      sem_wait(&mutex);
	      fprintf(stderr,"Can not read whole file\n");
	      sem_post(&mutex);
	      close(fd);
	      free(nums);
	      return NULL;
      }
      
      qsort(nums,lastpos/4,sizeof(int),comparator);

      close(fd);

      int fd_write=open(file,O_WRONLY|O_TRUNC);
      if(fd_write==-1)
      {
	      sem_wait(&mutex);
	      fprintf(stderr,"Can not open file to write\n");
	      free(nums);
              sem_wait(&mutex);
	      return NULL;
      }
       
     
      if(write(fd_write,nums,lastpos) !=lastpos)
      {
	      sem_wait(&mutex);
	      fprintf(stderr,"Can not write all numbers to file\n");
	      sem_post(&mutex);
	      close(fd_write);
	      free(nums);
      }
      free(nums);
      close(fd_write);


}





int main(int argc,char **argv)
{
   if(argc==1)
   {
	   fprintf(stderr,"Profram need at least 1 argument\n");
	   return -1;
   }

    pthread_t *arr=(pthread_t*)malloc(sizeof(pthread_t)*(argc-1));
    
    sem_init(&mutex,0,1);
    for(int i=0;i<argc-1;i++)
    {
	if(pthread_create(arr+i,NULL,sort,(void*)argv[i+1]))
	{
	    fprintf(stderr,"Can not create thread\n");
	    sem_destroy(&mutex);
	    return -1;
	}
    }

    for(int i=0;i<argc-1;i++)
    {
	    if(pthread_join(arr[i],NULL))
	    {
		    fprintf(stderr,"Can not join thread\n");
		    sem_destroy(&mutex);
		    return -1;
	    }
    }

     sem_destroy(&mutex);
     free(arr);
   return 0;
}
