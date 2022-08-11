#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>













int main()
{
	char  symbol;

	while( read(0,&symbol,1) )
	{
		printf("%d\n",symbol);
              //write(1,&symbol,1);
	}
	return 0;
}
