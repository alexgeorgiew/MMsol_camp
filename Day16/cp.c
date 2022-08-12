#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char **argv)
{
        if(argc<3)
	{
		char msg[]={"Need at lest 2 arguments\n"};
		write(2,msg,strlen(msg));
		return -1;
	}

	int source=open(argv[1],O_RDONLY);
	 
	if(source == -1)
	{
              char msg[]={"Can not open source file\n"};
              write(2,msg,strlen(msg));
              return -1;	      
	}

	int dest=open(argv[2] , O_WRONLY|O_CREAT|O_TRUNC ,0777);
        if(dest==-1)
	{
		char msg[]={"Error when opening or creating destination file\n"};
		write(2,msg,strlen(msg));
		close(source);
		return -1;
	}

	char buf[200];
	int  read_symbols;
	while( (read_symbols=read(source,buf,200)) > 0 )
	{
		write(dest,buf,read_symbols);
	}

        close(dest);
	close(source);

	return 0;
}
