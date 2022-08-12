#include "image.h"

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

       buf->data=(Pixel_Data*)malloc(sizeimage[0]*sizeimage[1]*sizeof(Pixel_Data)); //check if null is returned

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

       for(int i=0;i<sizeimage[0]*sizeimage[1];i++)  
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

int write_to_binaryppm(PPM_Image_Buffer* image,char* filename)
{
	FILE* f=fopen(filename,"wb");
        if(f==NULL)
        {
                fprintf(stderr,"Can not open file to write it in format ppm6");
        }

        fputc('P',f);
        fputc('6',f);
        fputc('\n',f);
        fprintf(f,"%d",image->coln);
        fputc(' ',f);
        fprintf(f,"%d",image->rown);
        fputc('\n',f);
        fputc('2',f);
        fputc('5',f);
        fputc('5',f);
        fputc('\n',f);


        for(int i=0;i<image->rown*image->coln;i++)
        {
                unsigned char arr[3]={image->data[i].red,image->data[i].green,image->data[i].blue};
                fwrite(arr,3,sizeof(unsigned char),f);
        }

        fclose(f);

}

int read_from_binaryppm(PPM_Image_Buffer* image,char* filename)
{
       FILE* f=fopen(filename,"rb");
       if(f==NULL)
       {
               return -1;
       }

       char line1[4];
       fread(line1,3,sizeof(char),f);
       line1[3]='\0';

       if(strcmp(line1,"P6\n")!=0)
       {
               fprintf(stderr,"Special word format is wrong\n");
               return -1;
       }

       int size[2];
       fscanf(f,"%d %d\n",size,size+1);
       if(size[0]<=0 || size[1]<=0)
       {
               printf("Zero or negative dimension\n");
               return -1;
       }
       char c[5];
       fread(c,4,sizeof(char),f);
       c[4]='\0';
       if(strcmp(c,"255\n")!=0)
       {
               printf("Maximal value for color is not right\n");
               return -1;
       }
        image->coln=size[0];
        image->rown=size[1];
       image->data=(struct Pixel_Data*)malloc(sizeof(struct Pixel_Data)*size[0]*size[1]);

        for(int i=0;i<size[0]*size[1];i++)
        {
                unsigned char arr[3];
                fread(arr,3,sizeof(unsigned char),f);
                image->data[i].red=arr[0];
                image->data[i].green=arr[1];
                image->data[i].blue=arr[2];
        }
       fclose(f);
       return 0;

}
