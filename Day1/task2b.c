#include <stdio.h>
#include <math.h>

int main()
{
   double r,l,h;
   fprintf(stdout,"Enter R ,L and H: ");
   scanf("%lf %lf %lf",&r,&l,&h);
   double area=acos((r-h)/h)*r*r-(r-h)*sqrt(2*r*h-h*h);
   double volume=area*l;
   fprintf(stdout,"Water in tank is %lf liters\n",volume);
   return 0;
}
