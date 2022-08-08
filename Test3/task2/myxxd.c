#include <string.h>
#include <stdio.h>


int main(int argc,char** argv)
{
	if(argc!=3)
	{
		fprintf(stderr,"Wrong number of arguments\n");
		return -1;
	}
       
	char h[3]="-H";
	char b[3]="-B";
	if(strcmp(argv[2],h) == 0)
	{
		FILE* f=fopen(argv[1],"rb");
                if(f==NULL)
                {
                        fprintf(stderr,"Can not open file to read\n");
                        return -1;
                }
                unsigned char c[2];
                while(  fread(c,1,sizeof(unsigned char),f) > 0)
                {
                        int hex=(int)c[0];

			int left=hex/16;
			if(left>9)left='a'+(left-10);
			else left='0'+left;

			int right=hex%16;
			if(right>9)right='a'+ (right-10);
			else right='0'+right;

                        printf("%c%c ",left,right);
                }
                fclose(f);


	}
	else if(strcmp(argv[2],b) == 0)
	{
		FILE* f=fopen(argv[1],"rb");
		if(f==NULL)
		{
			fprintf(stderr,"Can not open file to read\n");
			return -1;
		}
		unsigned char c[2];
		while(  fread(c,1,sizeof(unsigned char),f) > 0)
		{
			int dec=(int)c[0];
                        int start=128;
			for(int i=0;i<8;i++)
			{
				if(dec>=start)
				{
					int bit=1;
					printf("%d",bit);
					dec=dec-start;
					start/=2;
				}
				else
				{
					int bit=0;
					printf("%d",bit);
					start/=2;
				}
			}
			printf(" ");
		}
		fclose(f);

	}
	else
	{

		fprintf(stderr,"Unknown second argument\n");
		return -1;
	}
	return 0;
}
