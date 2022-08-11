#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <fcntl.h>




int main(int argc,char **argv)
{

	if(argc<2)
	{
		char msg[]={"Program need argument\n"};
		write(2,msg,strlen(msg));
		return -1;
	}

	for(int i=1;i<argc;i++)
	{
		int f=open(argv[i],O_RDONLY);
		if(f==-1)
		{
			char msg[]={"Error when open file\n"};
			write(2,msg,strlen(msg));
			return -1;
		}

		char buffer[100];
		int symbols;
		while( (symbols=read(f,buffer,100)) > 0 )
		{
			if(write(1,buffer,symbols) != symbols)
			{
				char msg[]={"Error when write to stdout\n"};
				write(2,msg,strlen(msg));
				close(f);
				return -1;
			}
		}
		close(f);
	}

	return 0;
}
