#include <stdio.h>
#include <math.h>

int triangle(double a,double b,double c,double* S,double* P);
int triangle(double a,double b,double c,double* S,double* P)
{
     if(a<=0 || b<=0 || c<=0)
     {
	     printf("Invalid triangle sides\n");
	     return -1;
     }
     if(a>=b+c || b>=a+c || c>=a+b)
     {
	     printf("Invalid triangle sides\n");
	     return -1;
     }

     *P=a+b+c;
     double p=*P/2;
     double s=p*(p-a)*(p-b)*(p-c);
     *S=sqrt(s);
     return 0;
}


int main()
{
	double a,b,c,S,P;
	while(1)
	{
            scanf("%lf %lf %lf",&a,&b,&c);
	    if(feof(stdin))return 0;

	    if(triangle(a,b,c,&S,&P)==0)
	    {
	      printf("S = %.2lf\n",S);
	      printf("P = %.2lf\n",P);
	    }
	}
	return 0;
}
