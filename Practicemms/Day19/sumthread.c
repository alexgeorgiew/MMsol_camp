#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <unistd.h>

void *sum(void *input)
{
	
	FILE *f=fopen((char *)input,"r");
	
	if( f == NULL)
	{
		printf("Error whit opening of %s\n",(char*)input);
		return NULL;
	}

        double num,sum=0.0;
	while( fscanf(f,"%lf",&num) != EOF)
	{
	        printf("%lf\n",num);	
		sum+=num;
	}

	double *result=(double*)malloc(sizeof(double)*1);
	*result=sum;

	fclose(f);
	return (void*)result;
}





int main(int argc,char **argv)
{
	if(argc<2)
	{
		printf("Program need files\n");
		return -1;
	}

	pthread_t *arr=(pthread_t*)malloc(sizeof(pthread_t)*(argc-1));

	for(int i=1;i<argc;i++)
	{
		if( pthread_create( arr+(i-1) , NULL , sum , (void *)(argv[i]) )  )
		{
			perror("create thread");
			return -1;
		}
	
	}
        
	double **sums=(double**)calloc(argc-1,sizeof(double*));
	
	for(int i=0;i<argc-1;i++)
	{

		pthread_join(arr[i],(void**) (sums+i) );
	}

	double result=0.0;

	for(int i=0;i<argc-1;i++)
	{
		result+= *sums[i];
		free(sums[i]);
	}
	free(sums);
	printf("Total sum is %lf\n",result);
         
	free(arr);

	return 0;

}
