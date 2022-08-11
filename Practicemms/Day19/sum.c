#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <sys/wait.h>


int main(int argc,char **argv)
{

	int a[2];

	if(pipe(a)==-1)
	{
		fprintf(stderr,"Can not create pipe\n");
		return -1;
	}

	int pid=fork();

	if(pid==-1)
	{
		fprintf(stderr,"Can not fork\n");
		return -1;
	}
	else if(pid==0)
	{
		close(a[0]);
		if(argc==1)
		{
			close(a[1]);
			return 1;
		}
		else
		{
			for(int i=1;i<argc;i++)
			{
				double num=atof(argv[i]);
				write(a[1],&num,sizeof(double));
				printf("%lf\n",num);
			}
		}
		close(a[1]);
		
	}
	else
	{
		wait(NULL);
		close(a[1]);
               if(argc!=1)
	       {
			double cur;
			double sum=0.0,min=DBL_MAX,max=DBL_MIN,avg=0.0;
			int cnt=0;
			while( read(a[0],&cur,sizeof(double)) == sizeof(double) )
			{
			   sum+=cur;
			   if(min>cur)min=cur;
			   if(max<cur)max=cur;
                           cnt++;
			}
			avg=sum/cnt;
			fprintf(stdout,"Sum is %lf\n",sum);
			fprintf(stdout,"Avg is %lf\n",avg);
			fprintf(stdout,"Min is %lf\n",min);
			fprintf(stdout,"Max is %lf\n",max);
	       }
	       else
	       {
		       fprintf(stdout,"There is no numbers\n");
	       }
	       close(a[0]);
		
	}
	return 0;
}
