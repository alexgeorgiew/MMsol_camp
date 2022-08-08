#include <sys/stat.h>
#include <stdio.h>



int main(int argc,char **argv)
{
	for(int i=1;i<argc;i++)
	{
		if( mkdir(argv[i],0777) != 0 )
		{
			fprintf(stderr,"There is error with craeting direcotry with name:%s\n",argv[i]);
			return -1;
		}
	}
	return 0;
}
