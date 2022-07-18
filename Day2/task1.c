#include <stdio.h>

double max(double a,double b);
double  max(double a,double b)
{
	if(a>b)return a;
	return b;

}

int main()
{
       double a,b,c;
       scanf("%lf",&a);
       scanf("%lf",&b);
       scanf("%lf",&c);
       double result=max(a,max(b,c));
       fprintf(stdout,"Maximum of the given input is : %lf\n",result);

	return 0;
}
//Example    
//            cat numbers | ./a.out     
// 
// where a.out is the executable file of this code 

