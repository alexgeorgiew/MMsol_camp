#include <stdio.h>
#include <math.h>
int main()
{
	double height,weight;
	fprintf(stdout,"Enter height and weight: ");
	scanf("%lf %lf",&height,&weight);
	double result=weight/(height*height);
	fprintf(stdout,"BMI old is %lf\n",result);
	result=1.3*(weight/pow(height,2.5));
	fprintf(stdout,"BMI new is %lf\n",result);
	return 0;
}
