#include <unistd.h>
#include <fcntl.h>



int main()
{
	
	int count_new_lines=0;
 	char symbol;
	while( read(0,&symbol,1)!=0 && count_new_lines<10)
	{
		if(symbol=='\n')count_new_lines++;
		write(1,&symbol,1);
	}

	return 0;
}
