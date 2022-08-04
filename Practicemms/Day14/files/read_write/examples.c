#include <stdio.h>
#include <stdlib.h>


int main()
{
	FILE* f=fopen("information","w+");
	
	if(f==NULL)
	{
		fprintf(stderr,"Can not open file for writing\n");
		return 1;
	}

	char* arr="HEllo";

	fwrite(arr,1,5,f);

	int ints[4]={48,49,50,51};
	fwrite(ints,sizeof(int),4,f);

	fclose(f);
	return 0;
}
