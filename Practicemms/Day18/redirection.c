#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>




int main(int argc,char **argv)
{	
	char opt;
	int cn=0,co=0,ce=0;
	int nums=10;
	char *out,*err;
	while( (opt=getopt(argc,argv,"n:o:e:")) != -1 )
	{
		switch(opt)
		{
			case 'n':
			 	cn++;
			 	if(cn>1)break;
			 	char* str=(char*)malloc(sizeof(char)*(strlen(optarg)+1) );
				//we should check  for null
			 	strcpy(str,optarg);
			 	nums=atoi(str);
			 	break;
			case 'o':
				co++;
				if(co>1)break;
				out=(char*)malloc(sizeof(char)* (strlen(optarg)+1) );
				//we should check  for null
				strcpy(out,optarg);
				break;
			case 'e':
				ce++;
				if(ce>1)break;
				err=(char*)malloc(sizeof(char)*(strlen(optarg)+1) );
				//we should check  for null
				strcpy(err,optarg);
				break;


		}
	}

	if(co>1)
	{
		free(out);
		if(ce)free(err);
		fprintf(stderr,"To many output files\n");
		return -1;
	}
	if(ce>1)
	{
		free(err);
		if(co)free(out);
		fprintf(stderr,"To many error files\n");
		return -1;
	}

	if(co==0)
	{
		if(ce)free(err);
		fprintf(stderr,"There is no output file\n");
		return -1;
	}
	if(ce==0)
	{
		if(co)free(out);
		fprintf(stderr,"There is no error file\n");
		return -1;
	}

        int o=open(out,O_WRONLY|O_CREAT|O_TRUNC,0777);
	if(o==-1)
	{
		fprintf(stderr,"Can not create file for stdout\n");
		return -1;
	}
	int  e=open(err,O_WRONLY|O_CREAT|O_TRUNC,0777);
	if(e==-1)
	{	
	close(o);
		fprintf(stderr,"Can not open file for stderr\n");
		return -1;
	}
	
	dup2(o,STDOUT_FILENO);
	dup2(e,STDERR_FILENO);
	for(int i=0;i<nums;i++)
	{
		char num=1+rand()%10;
		write(o,&num,sizeof(char));
		write(e,&num,sizeof(char));
	}

         
	close(o);
	close(e);
	return 0;
}
