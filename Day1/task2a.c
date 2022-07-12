#include <stdio.h>
#include <math.h>

int main()
{
   float r,h;
   fprintf(stdout,"Enter R and H: ");
   scanf("%f %f",&r,&h);
   float result=3.14*r*r*h;
   fprintf(stdout,"Water in tank is %f liters\n",result);
   return 0;
}
