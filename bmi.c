#include <stdio.h>
#include <math.h>
int main()
{
	float height,weight;
	fprintf(stdout,"Enter height and weight: ");
	scanf("%f %f",&height,&weight);
	float result=weight/(height*height);
	fprintf(stdout,"BMI old is %f\n",result);
	result=1.3*(weight/pow(height,2.5));
	fprintf(stdout,"BMI new is %f\n",result);
	return 0;
}
