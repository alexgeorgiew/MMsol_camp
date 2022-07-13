#include <stdio.h>


int main()
{
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	if(a+b==1)
	{
          fprintf(stdout,"Result of XOR over this input is 1\n");
	}
	else
	{
          fprintf(stdout,"Result of XOR over this input is 0\n");
	}

	return 0;
}
//example to use the program
//
//  cat numbers.txt | ./a.out
//
//  where a.out is executable file of this code
