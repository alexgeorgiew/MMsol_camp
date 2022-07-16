#include <stdio.h>
#include <math.h>

int quadEq(double a,double b,double c,double* x1,double* x2);
int quadEq(double a,double b,double c,double* x1,double* x2)
{
	if(a==0)
	{
           if(b==0)
	   {
               if(c==0)
	       {
		       printf("Every number is root!!\n");
		       return -1;

	       }
	       else
	       {
		       printf("There is no solution!!\n");
		       return -1;
	       }
	   }
	   else
	   {
             *x1=-c/b;
	     *x2=-c/b;
	     return 0;
	   }
	}
	else
	{
             double D=b*b-4*a*c;
	     if(D<-0.0001)
	     {
                printf("Thera are only imaginary solutions\n");
			return -1;
	     }
	     else if(D<0.0001) //we will accept that D is equal to 0
	     {
                *x1=-b/2*a;
		*x2=-b/2*a;
		return 0;
	     }
	     else
	     {
                *x1=(-b+sqrt(D))/(2*a);
		*x2=(-b-sqrt(D))/(2*a);
		return 0;
	     }
	}
}

int main(int argc,char** argv)
{
       if(argc!=4)
       {
	       printf("wrong number of arguments\n");
	       return 0;
       }

        double a,b,c,x1,x2;
	sscanf(argv[1],"%lf",&a);
	sscanf(argv[2],"%lf",&b);
	sscanf(argv[3],"%lf",&c);

	if(quadEq(a,b,c,&x1,&x2)==0)
	{
		printf("x1 = %.2lf\n",x1);
		printf("x2 = %.2lf\n",x2);
	}
        

	return 0;
}
