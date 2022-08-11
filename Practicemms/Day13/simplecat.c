#include <stdio.h>



int main(int argc,char** argv)
{
	FILE* f=fopen(argv[1],"r");

	if(f==NULL)
	{
		printf("Error when opening file");
	}
	 
	char c;
	while( ( c=fgetc(f) ) != EOF)
	{
		printf("%c",c);
	}
	fclose(f);
	return 0;
}
