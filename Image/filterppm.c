#include <stdlib.h>
#include <stdio.h>

typedef struct Pixel_Data{
    unsigned char red,green,blue;
}Pixel_Data;


typedef struct PPM_Image_Buffer{
      Pixel_Data* data;
      int rown,coln;
}PPM_Image_Buffer;

int max(int a,int b)
{
	if(a>b)return a;
	return b;
}

int read_ppm_color_bitmap(char* filename, PPM_Image_Buffer* buf)
{
       FILE* f=fopen(filename,"r");
       if(f==NULL)
       {
	       fprintf(stderr,"Can not open file to read\n");
	       return -1;
       }
       
       char firstword[2];
       size_t read;
       read=fscanf(f,"%c%c",firstword,firstword+1);
       if( read == EOF )
       {
       		fprintf(stderr,"Error when reading special word\n");
		fclose(f);
		return -1;
       }
       if(read!=2)
       {
	       fprintf(stderr,"First special word is not contain of 2 chars\n");
	       fclose(f);
	       return -1;
       }
       if( firstword[0]!='P'  || firstword[1]!='3' )
       {
	       fprintf(stderr,"First special word has differnt char than expected ones\n");
	       fclose(f);
	       return -1;
       }     
       
       int sizeimage[2];
       read=fscanf(f,"%d %d",sizeimage,sizeimage+1);
       if( read == EOF )
       {
       	        fprintf(stderr,"Error when reading size of image\n");
		fclose(f);
		return -1;
       }

       if(read!=2)
       {
	       fprintf(stderr,"Dimesions are not 2 numbers\n");
	       fclose(f);
	       return -1;
       }
       if( sizeimage[0]<=0  || sizeimage[1]<=0)
       {
	       fprintf(stderr,"Negative size of dimension\n");
	       fclose(f);
	       return -1;
       }
  	
       buf->coln=sizeimage[0];
       buf->rown=sizeimage[1];

       buf->data=(Pixel_Data*)malloc(sizeimage[0]*sizeimage[1]*sizeof(Pixel_Data));

       int specialword255;
       if( fscanf(f,"%d",&specialword255) == EOF)
       {
	       free(buf->data);
	       fprintf(stderr,"Error when read special word 255\n");
	       fclose(f);
	       return -1;
       }
       if(specialword255!=255)
       {
	       free(buf->data);
	       fprintf(stderr,"Special word 255 is something else\n");
	       fclose(f);
	       return -1; 
       }

       for(int i=0;i<sizeimage[0]*sizeimage[1];i++)   //here we should check for empty  lines 
       {
	       int r,g,b;
	       if(fscanf(f,"%d %d %d",&r,&g,&b) != 3)
	       {
		       free(buf->data);
		       fprintf(stderr,"Error when read info for a pixel\n");
		       fclose(f);
		       return -1;
	       }
	       if(r<0 || r>255 || g<0 || g>255 || b<0 || b>255)
	       {
		       free(buf->data);
		       fclose(f);
		       return -1;
		}
	       buf->data[i].red=r;
	       buf->data[i].green=g;
	       buf->data[i].blue=b;
       }

        if(fclose(f) == EOF)
	{
		free(buf->data);
		return -1;
	}
       return 0;
}

int write_ppm_color_bitmap(char* filename, PPM_Image_Buffer *buf)
{
	FILE *f=fopen(filename,"w+");
	if(f==NULL)
	{
		return -1;
	}

	if(fprintf(f,"P3\n") < 0 )
	{
		fprintf(stderr,"Error while writing saved word in the new image\n");
		fclose(f);
		return -1;
	}
	if(fprintf(f,"%d %d\n",buf->coln,buf->rown) < 0)
	{
		fprintf(stderr,"Error while writing dimensional information\n");
		fclose(f);
		return -1;
	}
	if(fprintf(f,"255\n") < 0 )
	{
		fprintf(stderr,"Error while writing special word\n");
		fclose(f);
		return -1;
	}
        
	for(int i=0;i< buf->coln * buf->rown ;i++)
	{
		if(fprintf(f,"%d %d %d\n",buf->data[i].red,buf->data[i].green,buf->data[i].blue) < 0 )
		{
			fprintf(stderr,"Error while writing information about pixel\n");
			fclose(f);
			return -1;
		}

	}
       if(fclose(f) == EOF)
       {
	       return -1;
       }
 	return 0;
}

void filter_color_component(PPM_Image_Buffer* buf,unsigned int rgb_mask)
{
	int r=!!(rgb_mask & 1);
	int g=!!(rgb_mask & 2);
	int b=!!(rgb_mask & 4);
	for(int i=0;i< buf->coln * buf->rown ;i++)
	{
		buf->data[i].red*=r;
		buf->data[i].green*=g;
		buf->data[i].blue*=b;
	}
}

void convert_to_grayscale(PPM_Image_Buffer* buf)
{
	for(int i=0;i< buf->coln * buf->rown ;i++)
	{
            buf->data[i].red=(unsigned char)(buf->data[i].red*0.3);
            buf->data[i].green=(unsigned char)(buf->data[i].green*0.3);
            buf->data[i].blue=(unsigned char)(buf->data[i].blue*0.3);
	    unsigned char value=max(max(buf->data[i].red,buf->data[i].green),buf->data[i].blue);
	    buf->data[i].red=value;
	    buf->data[i].green=value;
	    buf->data[i].blue=value;
	}
}

void printfBuffer(PPM_Image_Buffer* input)
{
      printf("P3\n");
      printf("%d %d\n",input->coln,input->rown);
      printf("255\n");
      for(int i=0; i< input->coln*input->rown ;i++)
      {
		printf("%d %d %d\n",input->data[i].red,input->data[i].green,input->data[i].blue);
      }
}

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
            if( argv[3][0]!='-' || argv[3][1]!='g' || argv[3][2]!='\0')return -1;

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
