#include <stdio.h>
#include <math.h>

int main()
{
   double r,h;
   fprintf(stdout,"Enter R and H: ");
   scanf("%lf %lf",&r,&h);
   double result=3.14*r*r*h;
   fprintf(stdout,"Water in tank is %lf liters\n",result);
   return 0;
}
