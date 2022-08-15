#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int sum(int mask)
{
	int result=0;
	for(int i=0;i<32;i++)
	{
	    if(mask&(1<<i))result++;
	}
	return result;
}


int main(int argc,char **argv)
{
	if(argc==1)
	{
		char msg[]="There is no input file\n";
		write(2,msg,strlen(msg));
		return -1;
	}
        int total=0;

	for(int i=0;i<argc-1;i++)
	{
	    int p[2];
	   
            if(pipe(p)==-1)
	    {
		    fprintf(stderr,"Can not create pipe\n");
	    }
	    else
	    {
		    int pid=fork();
		    if(pid==-1)
		    {
			    fprintf(stderr,"Can not fork\n");
		    }
		    else if(pid==0)
	            {
                        close(p[0]);
			
			int f=open(argv[i+1],O_RDONLY);
			if(f==-1)
			{
				fprintf(stdout,"file%d ",i+1);
				perror("- ");
				return -1;
			}
                        int size=lseek(f,0,SEEK_END);
		        
			if(size%4!=0)
			{
				fprintf(stdout,"file%d - format of file is not correct\n",i+1);
				close(f);
				return -1;
			}
			lseek(f,0,SEEK_SET);

			int result=0,num;
			while(read(f,&num,sizeof(num)))
			{
			   result=sum(num);
			}

                        fprintf(stdout,"file%d - %d\n",i+1,result);
			write(p[1],&result,sizeof(result));

			close(p[1]);
			close(f);

			return 0;
		    }
		    else
		    {
			close(p[1]);
			int cur;
			wait(&cur);

			if(WIFEXITED(cur))
			{
			    cur=0;
				read(p[0],&cur,sizeof(cur));
                        	total+=cur;
			}
			close(p[0]);
		    }
	    }
	}

	fprintf(stdout,"Total sum-%d\n",total);

	return 0;
}
