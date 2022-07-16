#include <stdio.h>

int rectangle(double w,double h,double* S,double* P);
int rectangle(double w,double h,double *S,double* P)
{

	if(w<=0 || h <=0)
	{
		printf("Invalid rectangle sides!\n");
		return -1;
	}

	*S=w*h;
	*P=2*w+2*h;
	return 0;
}
int main()
{

	double w,h,P,S;


	while(1)
	{
                scanf("%lf %lf",&w,&h);
		if(feof(stdin))return 0;

                if(rectangle(w,h,&S,&P)==0)
		{
		   printf("S = %.2lf\n",S);
		   printf("P = %.2lf\n",P);
		}
	}

	return 0;
}
