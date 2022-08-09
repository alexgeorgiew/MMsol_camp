#include "image.h"

int main(int argc,char** argv)
{
	PPM_Image_Buffer image;
	if(argc<4 || argc>5)
	{
		fprintf(stderr,"Wrong number of arguments\n");
		return -1;
	}
        if(argc==4)   // last argument must be -g
	{
              if( strcmp(argv[3],"-g")==0 )
	      {
	    	 if(read_ppm_color_bitmap(argv[1],&image)==-1)
	    	 {
		   	 fprintf(stderr,"read_ppm_color_bitmap not correct execution\n");
			    return -1;
	    	 }

	    	 convert_to_grayscale(&image);

            	 if(write_ppm_color_bitmap(argv[2],&image)==-1)
	    	 {
			fprintf(stderr,"write_ppm_color_bitmap not correct finish\n");
			free(image.data);
			return -1;
	    	 }
	      }
	      else if(strcmp(argv[3],"-t")==0)
	      {
                   
	      }
	      else if(strcmp(argv[3],"-b")==0)
	      {

		    read_ppm_color_bitmap(argv[1],&image); //chech if correct
		    write_to_binaryppm(&image,argv[2]);
	      }
	      else
	      {
		      fprintf(stderr,"Program can not work with this arguments\n");
		      return -1;
	      }
  
	}
	else  
	{
           if(argv[3][0]!='-' || argv[3][1]!='f')return -1;

	   int r=0,g=0,b=0;
	   for(int i=0;argv[4][i]!='\0';i++)
	   {
		   if(argv[4][i]=='r')r++;
		   else if(argv[4][i]=='g')g++;
		   else if(argv[4][i]=='b')b++;
		   else return -1;
	   }
	   if(r>1 || g>1 || b>1)return -1;

            if(read_ppm_color_bitmap(argv[1],&image)==-1)
	    {

		    fprintf(stderr,"read_ppm_color_bitmap exited with status -1\n");
		    return -1;
	    }

	    filter_color_component(&image,r+g*2+b*4);

	    if(write_ppm_color_bitmap(argv[2],&image)==-1)
	    {
		    fprintf(stderr,"write_ppm_color_bitmap exited with status -1\n");
		    free(image.data);
		    return -1;
	    }
	}

	free(image.data);

        
	return 0;
}
