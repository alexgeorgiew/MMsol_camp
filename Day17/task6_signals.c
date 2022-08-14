#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void handler(int sig)
{
      char msg[]={"SIGINT received\n"};
      write(1,msg,strlen(msg));
}



int main()
{
	struct sigaction sa;
	sa.sa_handler=handler;
	sa.sa_flags=SA_RESTART;
	sigaction(SIGINT,&sa,NULL);
	int pid=fork();
        if(pid==-1)
	{
		char msg[]={"Can not fork\n"};
		write(2,msg,strlen(msg));
		return -1;
	}
	else if(pid==0)
	{
            int ppid=getppid();
	    kill(ppid,SIGINT);
	    return 0;
	}
	else
	{	
	  wait(NULL);
	}
}
