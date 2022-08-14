#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
	int tube[2];
	if( pipe(tube)== -1 )
	{
		char msg[]="Error when creating pipe\n";
		write(2,msg,strlen(msg));
	}

	int pid=fork();
	if(pid==-1)
	{
		close(tube[0]);
		close(tube[1]);
		char msg[]="Can not fork\n";
		write(2,msg,strlen(msg));
		return -1;
	}
	if(pid==0)
	{
		close(tube[0]);
		int num=10;

		write(tube[1],&num,sizeof(int));

		close(tube[1]);
	}
	else
	{
		close(tube[1]);
		int num_child;
		read(tube[0],&num_child,sizeof(int));
		if(num_child==10)
		{
			char msg[]={"Successful comunication through pipes\n"};
			write(1,msg,strlen(msg));
		}
		close(tube[0]);
		wait(NULL);
	}

	return 0;
}
