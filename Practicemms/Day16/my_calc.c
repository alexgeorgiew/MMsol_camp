#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <float.h>


int main(int argc,char **argv)
{
	if(argc<2)
	{
		fprintf(stderr,"There is no arguments for this program\n");
		return -1;
	}
	char sum[]="-s";
	char min[]="-m";
	char max[]="-M";

	if( strcmp(argv[1],sum) == 0 )
	{
		if(argc==2)
		{
			fprintf(stderr,"There is no number\n");
			return -2;
		}
		double sum=0.0;
		for(int i=2;i<argc;i++)
		{
			double cur=atof(argv[i]);
			sum+=cur;
		}
		printf("Sum of all numbers is :%lf\n",sum);
	}
	else if( strcmp(argv[1],min) == 0)
	{
		
		if(argc==2)
		{
			fprintf(stderr,"There is numbers \n");
			return -2;
		}
		double temp=DBL_MAX;
		for(int i=2;i<argc;i++)
		{
			double cur=atof(argv[i]);
			if(temp>cur)temp=cur;
		}

		printf("Minimal number is:%lf\n",temp);
	}
	else if( strcmp(argv[1],max) == 0)
	{
		if(argc==2)
		{
			fprintf(stderr,"There is no numbers\n");
			return -2;
		}
		double temp=DBL_MIN;
		for(int i=2;i<argc;i++)
		{
			double cur=atof(argv[i]);
			if(temp<cur)temp=cur;
		}

		printf("Maximal number is:%lf\n",temp);
	}
	else // here we will print all numbers
	{
	     for(int i=2;i<argc;i++)
	     {
		double cur=atof(argv[i]);
		printf("%lf ",cur);
	     }
       }
	return 0;
}
