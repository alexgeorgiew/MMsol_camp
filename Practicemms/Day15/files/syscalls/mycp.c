#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>



int main(int argc,char** argv)
{
        int fdread=open(argv[1],O_RDONLY);
	if(fdread==-1)
	{
		perror("Could not open file to read\n");
		return -1;
	}

	

	int fdwrite=open(argv[2],O_WRONLY|O_CREAT|O_EXCL,00777);
	if(fdwrite==-1)
	{
		perror("Could not open file to write\n");
		return -1;
	}
	
 	char buffer;
	int countrd,writerd;
	while( (countrd=read(fdread,&buffer,sizeof(char)*1)) )
	{
		if(countrd==-1)
		{
			perror("Could not read byte from file\n");
			return -1;
		}
		writerd=write(fdwrite,&buffer,sizeof(char)*1);
		if(writerd==-1)
		{
			perror("Could not write to file\n");
			return -1;
		}

	}
	close(fdread);
	close(fdwrite);
	return 0;
}
