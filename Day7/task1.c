#include <stdio.h>
#include <limits.h>

int secondMax(const int* arr,size_t n,int* secondMax)
{
	if(n==0)
	{
		return -1;
	}
	if(n==1)
	{
		return -2;
	}

        int max=INT_MIN;
	int second=INT_MIN;
        
	int equality=0;
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]!=arr[i+1])
		{
			equality=1;
			i=n;
		}

	}
	if(equality==0)return -3;
        
        for(int i=0;i<n;i++)
	{
		if(max<arr[i])
		{
                       second=max;
			max=arr[i];
		}

	}

        *secondMax=second;
	return 1;

}

int main()
{
	return 0;
}
