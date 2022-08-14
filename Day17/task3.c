#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>








int main(int argc,char ** argv)
{
        if(argc!=3)
	{
		char msg[]={"Program needs only two arguments\n"};
		write(2,msg,strlen(msg));
		return -1;
	}

	int pid=fork();
        if(pid==-1)
	{
		char msg[]={"Can not fork\n"};
		write(2,msg,strlen(msg));
		return -1;
	}
	else if(pid==0)
	{
		execlp(argv[1],argv[1],NULL);
		return -1;		
	}
	else
	{
           int status;
	   wait(&status);
	   
	   if( WEXITSTATUS(status)==0 )
	   {
		int pid2=fork();
		if(pid2==-1)
		{
			char msg[]={"Can not fork for second comand\n"};
			write(2,msg,strlen(msg));
			return -1;
		}
		else if(pid2 == 0)
		{
			execlp(argv[2],argv[2],NULL);
			return -1;
		}
		else
		{
			int status2;
			wait(&status2);
			if( WEXITSTATUS(status2) == 0)
			{
				return 0;
			}	
			else
			{
				char msg[]={"Second command failed\n"};
				write(1,msg,strlen(msg));
				return -1;
			}
		}
	   }
	   else
	   {
		 char msg[]={"First comand failed\n"};
		 write(1,msg,strlen(msg));
		return -1;
	   }
	   
	}

	return 0;
}
