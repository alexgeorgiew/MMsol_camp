#include <fcntl.h>
#include <unistd.h>


int main()
{
	int file=open("nums",O_WRONLY|O_CREAT|O_TRUNC ,0777);
	for(int i=0;i<10;i++)
	{
		write(file,&i,sizeof(int));
	}
	close(file);
	return 0;
}


