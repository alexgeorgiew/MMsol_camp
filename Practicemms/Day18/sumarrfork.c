#include<stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include<sys/stat.h>
#include <unistd.h>


int main()
{
	int start=0;
	int *sum=&start;
	*sum=0;
	int arr[6]={10,10,10,20,20,20};
         printf("%p\n",sum);
	int pid=fork();

	if(pid==0)
	{
		printf("%p\n",sum);
	  int cur=0;
	  for(int i=3;i<6;i++)
	  {
		  cur+=arr[i];
	  }
	  *sum+=cur;
	}
	else
	{
		printf("%p\n",sum);
           wait(NULL);
	   int cur=0;
	   for(int i=0;i<3;i++)
	   {
		   cur+=arr[i];
	   }
	   *sum+=cur;
	}

      

	return 0;
}
