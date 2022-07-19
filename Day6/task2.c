#include <stdio.h>

double sin(double x)//n represent to which exapansion of Taylor serires
{
   double up=x;
   double down=1.0;
   double result=x/down;
	for(int i=3;i<=9;i+=2)
	{
           up=(-1.0)*up*x*x;
	   down=down*i*(i-1);
	   result+=(up/down);
	}

	return result;
}


int main()
{
	printf("sin(PI/2)=%lf \n",sin(3.14/2));
	return 0;
}
