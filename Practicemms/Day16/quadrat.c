#include <stdio.h>
#include <unistd.h>



//THIS PROGRAM IS NOT GOOD AT ALL


int main(int argc,char**argv)
{
	double a=0.0,b=0.0,c=0.0;
	int p=2;
        char opt;

	int ca=0,cb=0,cc=0,cp=0;
	while( (opt=getopt(argc,argv,"a:b:c:p:")) !=-1 )
	{
		switch(opt)
		{
			case 'a':
                         sscanf(optarg,"%lf",&a);
			 ca++;
				break;
			case 'b':
			 sscanf(optarg,"%lf",&b);
			 cb++;
				break;
			case 'c':
			 sscanf(optarg,"%lf",&c);
			 cc++;
				break;
			case 'p':
				sscanf(optarg,"%d",&p);
				cp++;
				break;
		}
	}
        

       if(ca==0)
       {
	       if(cb==0)
	       {
		       if(cc==0)
		       {
			       fprintf(stderr,"Enter information about the equation\n");
			       return -1;
		       }
		       else if(cc==1)
		       {
			       if(c!=0.0)
			       {
				       fprintf(stdout,"there is no solution\n");
			       }
			       else
			       {
				       fprintf(stdout,"There are many solutions\n");
			       }
		       }
		       else
		       {
			       fprintf(stderr,"You have entered to many arguments c\n");
			       return -1;
		       }
	       }
	       else if(cb==1)
	       {
			if(cc==0)
			{
				printf("X=0\n");
			}
			else if(cc==1)
			{
				if(b==0)
				{
					if(c==0)
					{
						fprintf(stdout,"There are many solutions\n");
					}
					else
					{
						fprintf(stdout,"There is no solution\n");
					}
				}
				else
				{
					printf("x=%.\plf",-c/b);
				}
			}
			else
			{
				fprintf(stderr,"There is too many arguments c\n");
				return -1;
			}
	       }
	       else
	       {
		       fprintf(stderr,"To many arguments for b\n");
		       return -1;
	       }
       
       }
       else if(ca==1)
       {
	  if(a!=0.0)
	  {
          	  double d=b*b-4*a*c;
		  if(d<0.01 && d>-0.01)
		  {
			  char fmt[10];
			  sprintf(fmt,"x=%%.%dlf",p);
			  printf(fmt,-b/(2*a));
	  	  }
		  else
		  {
			  printf("x1=")
		  } 
	  }

       }
       else
       {
	       fprintf(stderr,"Two many arguments  a\n");
	       return -1;
       }


	return 0;
}
