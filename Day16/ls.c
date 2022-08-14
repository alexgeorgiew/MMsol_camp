#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>



int main(int argc,char** argv)
{
    if(argc >3)
    {
	fprintf(stderr,"Program needs exactly 0,1 or 2 arguments");
	return -1;
    }
    

    if(argc==1)
    {
       DIR *d;
       struct dirent *dir;
       d = opendir(".");
       if(d) 
       {
            while ((dir = readdir(d)) != NULL) 
	    {
	        if(dir->d_name[0]!='.')
	        {
                   printf("%s  ", dir->d_name);
                }
	
           }
	    printf("\n");
	    closedir(d);
       }
       else
       {
	       fprintf(stderr,"Can not open current dir\n");
	       return -1;
       }
    }
    if(argc==2) //check if file or direectory
    {

    }
    else    //here we will have dir and option to show hidden files 
    {

    }

    return 0;
}
