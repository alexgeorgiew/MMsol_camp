#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int sumdigits(int num)
{
	if(num<=10)return num;

	int result=0;
	while(num!=0)
	{
		result+=num%10;
		num=num/10;
	}
	return result;
}
int compare1(const void* a,const void* b)
{
         double first=*(double*)a;
	 double second=*(double*)b;

	 if(first-second>0.01)return 1;
	 if(first-second>=-0.01 && first-second <=0.01)return 0;
	 return -1;
}

int compare2(const void* a,const void*b)
{
	return compare1(&b,&a);
}

int compare3(const void*a,const void*b)
{
	double first=*(double*)a;
	double second=*(double*)b;
	int num1=(int)first;
	int num2=(int)second;

	int sum1=sumdigits(num1);
	int sum2=sumdigits(num2);

	return sum1-sum2;
}

int compare4(const void*a,const void*b)
{
	double first=fabs(*(double *)a);
	double second=fabs(*(double*)b);

	if(first -second > 0.01)return 1;
	if(first-second >= -0.01 && first-second <= 0.01)return 0;
	return -1;
}

double myrandom(int Min,int Max)
{
  
  double d=(double)rand()/RAND_MAX;
  return Min + d*(Max-Min);
}
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
