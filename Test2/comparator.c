#include <stdlib.h>
#include <math.h>
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
double myrandom(int Min,int Max)
{
	double d=(double)rand()/RAND_MAX;
	return Min+d*(Max-Min);
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

