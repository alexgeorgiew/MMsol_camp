#include <stdio.h>

int doubleComp(double a,double b)
{
	 if(a>b)
	 { 
               if(a-b<0.0001)return 1;
	       return 0;
	 }
	 if(b-a<0.0001)return 1;
	 return 0;
}

double root(double input)
{
	if(input<0.0)
	{
		printf("Error negative number\n");
	}
	double cur=input/2;
        double step=0;
       while(1)
       {
             if(doubleComp(cur*cur,input))
	     {
		     return cur;
	     }
	     else if(cur*cur>input)
	     {
		     return cur;
	     }
	     else
	     {
		   step=cur;
                   cur=(input/step+step)/2;
	     }
       }
}


int main()
{
	
	printf("%lf\n",root(2));
	return 0;
}
