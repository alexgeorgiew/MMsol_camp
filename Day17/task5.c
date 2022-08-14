#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
void handler(int sig)
{
 
}


int main()
{
	struct sigaction sa;
	sa.sa_handler=handler;
        sa.sa_flags=SA_RESTART;
        sigaction(SIGINT,&sa,NULL); // ctrl c
	sigaction(SIGTSTP,&sa,NULL); // ctrl z

	char msg[]={"MMS C CAMP\n"};
	while(1)
	{
		usleep(500000);
		write(1,msg,strlen(msg));
	}
	return 0;
}

