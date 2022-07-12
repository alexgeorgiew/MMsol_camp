#include <stdio.h>
#include <math.h>

int main()
{
   float r,l,h;
   fprintf(stdout,"Enter R ,L and H: ");
   scanf("%f %f %f",&r,&l,&h);
   float area=acosf((r-h)/h)*r*r-(r-h)*sqrtf(2*r*h-h*h);
   float volume=area*l;
   fprintf(stdout,"Water in tank is %f liters\n",volume);
   return 0;
}
