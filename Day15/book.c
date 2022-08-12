#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 15

struct Book{
	char title[151];
	char author[101];
	int pages;
	double price;
};


int main(int argc,char **argv)
{

	if(argc!=2)
	{
		fprintf(stderr,"Program needs only one argument\n");
		return -1;
	}
	
	struct Book arr[COUNT];
	srand(time(NULL));
	for(int i=0;i<15;i++)
	{
	    int symbols=10 + rand()%11;
	    for(int j=0;j<symbols;j++)
	    {
		    arr[i].title[j]=('A'+rand()%26) + 32*(rand()%2);
	    }
	    arr[i].title[symbols]='\0';

	    symbols=10+rand()%11;
	    for(int j=0;j<symbols;j++)
	    {
		    arr[i].author[j]=('A' + rand()%26 ) + 32*(rand()%2);
	    }
	    arr[i].title[symbols]='\0';

	    arr[i].pages=5+rand()%2001;
	    arr[i].price=(1+rand()%1000)/1. ;
	}

        FILE *f=fopen(argv[1],"wb");
        if(f==NULL)
	{
		fprintf(stderr,"Can not open file\n");
	}

	fwrite(arr,15,sizeof(struct Book),f);
	fclose(f);
        
	return 0;
}
