#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>



int main(int argc,char **argv)
{
	if(argc!=2)
	{
		char msg[]={"Program needs only one argument\n"};
		write(2,msg,strlen(msg));
		return -1;
	}
        
	int num=atoi(argv[1]);

        for(int i=0;i<num;i++)
	{
		srand(i+time(NULL));
		int pid=fork();
		if(pid==-1)
		{
			char msg[]={"Can not fork\n"};
			write(2,msg,strlen(msg));
			return -1;
		}
		else if(pid == 0)
		{
	            char symbol;
		    for(int k=0;k<10;k++)
		    {
			    symbol=65+rand()%26;
			    write(1,&symbol,1);
		    }
		    symbol='\n';
		    write(1,&symbol,1);
		    return 0;
		}
		else
		{
			wait(NULL);
		}
	}


	return 0;
}
