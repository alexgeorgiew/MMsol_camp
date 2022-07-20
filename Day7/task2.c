#include <stdio.h>

unsigned sumArrayDigits(const int* arr,size_t n)
{ 
	unsigned result=0;

	for(int i=0;i<n;i++)
	{
             if(arr[i]!=0)
	     {
		     int cur=arr[i];
		     while(cur!=0)
		     {
			     result+=cur%10;
			     cur=cur/10;
		     }
	     }
	}

	return result;
}

int main()
{

	int arr[]={12,34,5,70};
	printf("%u\n",sumArrayDigits(arr,4));
	return 0;
}
