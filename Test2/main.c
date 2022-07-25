#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "comparator.h"

int main()
{
	int(*arr[4])(const void*,const void* b)={compare1,compare2,compare3,compare4};
        double numbers[COUNT];
         srand(time(NULL));
	for(int i=0;i<COUNT;i++)
	{
		numbers[i]=myrandom(MIN,MAX);
		printf("%.2lf ",numbers[i]);
	}
       printf("\n");
	int option;
	scanf("%d",&option);

	if(option>=1 && option<=4)
	{
	}
	else
	{
		fprintf(stdout,"Wrong choice for comparator\n");
		return 0;
	}
         qsort(numbers,COUNT,sizeof(double),arr[option-1]);
        for(int i=0;i<COUNT;i++)
	{
		printf("%.2lf ",numbers[i]);
	}
	printf("\n");
	return 0;
}
