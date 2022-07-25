#include <stdio.h>

int equal(double a,double b)
{
     if(a-b<0.1 && a-b>-0.1)return 1;
     return 0;
}

double root(double input)
{
     if(input<-0.0001) return -1; //we return -1 to indicate error
			      
     if(input<=2.0001)// here we will use Taylor series
     {
	     if(input>=-0.0001 && input<= 0.0001)return 0;
	     if(input>=0.999 && input<=1.001) return 1;
             
	     double x=input-1;
             return  1 + x/2  -(x*x)/8 + (x*x*x)/16 - (5*x*x*x*x)/126;
     }
     else
     {
	      double left=1 ,right=input;
	      double mid;

		      while(left<right)
		      {
			  mid=left+(right-left)/2;
			  if(equal(mid*mid,input))return mid;
                          
			  if(mid*mid<input)
			  {
				  left=mid;
			  }
			  else
			  {
				  right=mid;
			  }
		      }
		      return left;
	     
     }     
}


int main()
{
	
	printf("%lf\n",root(4));
	return 0;
}
