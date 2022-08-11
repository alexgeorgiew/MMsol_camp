#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>



int main(int argc,char **argv)
{
	for(int i=1;i<argc;i++)
	{
		int pid=fork();
		if(pid<0)
		{
			perror("Can not fork");
			exit(-1);
		}
		if(pid==0)
		{
			if(execlp(argv[i],argv[i],NULL) ==-1)
			{
				perror(argv[i]);
				exit(-1);
			}
		}
		else
		{
		 	wait(NULL);
			
		}
	}

	return 0;
}
