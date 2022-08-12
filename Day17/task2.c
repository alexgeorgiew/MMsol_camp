#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>


void write_error(char* msg)
{
	write(2,msg,strlen(msg));
}

void print_num(int num)
{
	char digits[20];
	int i=0;
	do
	{
		digits[i++]=num%10;
		num/=10;
	}while(num>0);

	for(int index=i-1;index>-1;index--)
	{
		write(1,digits+index,sizeof(char));
	}
}


int main(int argc,char **argv)
{
	if(argc==1)
	{
		write_error("Program needs arguments\n");
		return -1;
	}
        
	int tube[2];
	if(pipe(tube)==-1)
	{
		write_error("Can not pipe\n");
		return -1;
	}

	int pid=fork();
	if(pid==-1)
	{
	  write_error("Cano not fork\n");
	  return -1;
	}
	else if(pid==0)
	{
		close(tube[0]);
		int sum=0;
		for(int i=1;i<argc/2;i++)
		{
			sum+=atoi(argv[i]);
		}
		write(tube[1],&sum,sizeof(int));
		close(tube[1]);
		return 1;
	}
        
	close(tube[1]);
	
	int parent_sum=0;
	for(int i=argc/2;i<argc;i++)
	{
		parent_sum+=atoi(argv[i]);
	}

	int child_sum;
	wait(NULL);
	read(tube[0],&child_sum,sizeof(int));
	parent_sum+=child_sum;
         
        printf("%d\n",parent_sum);
        
        print_num(parent_sum);	
	close(tube[0]);
	return 0;
}
