#include <stdio.h>
#include <unistd.h>
#include <signal.h>


void handler(int sig)
{
	printf("%d\n",sig);
}

int main()
{
	struct sigaction sa;
	sa.sa_handler=handler;
	sa.sa_flags=SA_RESTART;
	sigaction(SIGUSR1,&sa,NULL);

	 while(1);
	return 0;
}
