#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <getopt.h>
int reverse=1;

int comparator(const void* a,const void* b)
{
	double *l=(double*)a;
	double *r=(double*)b;
	if (fabs(*l-*r) < 0.1)
	{
		return 0;
	}
	else if( (*l -*r) > 0)return 1*reverse;
	else return -1*reverse;
	
}

int main(int argc,char **argv)
{
       char res;
       int ic=0,oc=0,rc=0;
       char *finput, *foutput;

	while( ( res = getopt(argc,argv,"i:o:r") )  != -1 ) 
	{
		switch(res)
		{
		   case 'i':
		      ic++;
		      int len=strlen(optarg);
		      finput=(char*)malloc(sizeof(char)*(len+1));
		      strcpy(finput,optarg);
		      if(ic>1)
		      {
		      free(finput);
		   	fprintf(stderr,"To many files for input\n");
			return -1;
		      }
		      break;
		    case 'o':

		        oc++;
			int len2=strlen(optarg);
			foutput=(char*)malloc(sizeof(char)*(len2+1));
			strcpy(foutput,optarg);

			if(oc>1)
			{
				free(foutput);
			 fprintf(stderr,"To may files for output\n");
			 return -1;
			}
		        break;
		    case 'r':
			rc++;
			if(rc>1)
			{
			   fprintf(stderr,"To may reverse arguments \n");
			   return -1;
			}
		    break;
		}
	}
        
	
	if(ic!=1 || oc!=1)
	{
		if(ic==0)free(finput);
		if(ic==0)free(foutput);
		fprintf(stderr,"Input or output file is missing\n");
		return -1;
	}
	if(rc==1)reverse=-1;
	else if(rc>1)
	{
		free(finput);
		free(foutput);
		fprintf(stderr,"To many reverse arguments\n");
		return -1;
	}

        printf("%s\n",finput); 
	FILE *fi=fopen(finput,"r");
	if(fi==NULL)
	{
		fprintf(stderr,"Can not open input file\n");
		return -1;
	}

	FILE *fo=fopen(foutput,"w");
	
	if(fo==NULL)
	{
		fclose(fi);
		fprintf(stderr,"Can not open output file\n");
		return -1;
		
	}
        
	
	double *arr=malloc(sizeof(double)*10);

	double cur;
	int index=0,size=10;
	while( fscanf(fi,"%lf",&cur) != EOF)
	{	
  		if(index==size)
		{
		      arr=(double*)realloc(arr,size*2*sizeof(double));
		      arr[index]=cur;
		}
		else
		{
			arr[index]=cur;
		}
		index++;
	}
	
	
	
	qsort(arr,index,sizeof(double),comparator);
	
	for(int i=0;i<index;i++)
	{
		double num=arr[i];
		fprintf(fo,"%lf\n",arr[i]);
	}

	free(arr);
	free(finput);
	free(foutput);
	fclose(fi);
	fclose(fo);
	return 0;
}
