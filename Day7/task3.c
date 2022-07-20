#include <stdio.h>

int sum(int* arr,int n)
{
	int result=0;
	for(int i=0;i<n;i++)
	{
		result+=arr[i];
	}
	return result;
}
void arrayEvaluate(int* arr,size_t n,int(*f)(int*,int))
{
	printf("%d\n",f(arr,n));
}

int main()
{
	int arr[5]={10,10,10,10,10};
	arrayEvaluate(arr,5,sum);
	return 0;
}
