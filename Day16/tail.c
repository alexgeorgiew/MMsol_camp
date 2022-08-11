#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main()
{
	char **lines=(char**)malloc(sizeof(char*)*10);
	int sizes[10]={50,50,50,50,50,50,50,50,50,50};

	for(int i=0;i<10;i++)
	{
		lines[i]=(char*)malloc(sizeof(char)*sizes[i]);
		lines[i][0]='\0';
	}
        

	// reading part
	char symbol;
	int line=0,index=0;
	int flag=0;
	while( read(0,&symbol,1))
        {
           if(symbol=='\n')
	   {   
		if(index>=sizes[line]-1)
                {
	             lines[line]=realloc(lines[line],sizes[line]+2);
	             sizes[line]+=2;
		}
	        lines[line][index]='\n';
		lines[line][index+1]='\0';

		if(line!=9)line++;
		else flag=1;
		index=0;
	   }
	   else
	   {
		   if(flag)
		   {
			   char *temp=lines[0];
			   int temp_size=sizes[0];
			   for(int i=0;i<9;i++)
			   {
				   lines[i]=lines[i+1];
				   sizes[i]=sizes[i+1];
			   }
			   lines[9]=temp;
			   sizes[9]=temp_size;

			   //line=0;
		           flag=0;
		   }
		   if(index==sizes[line])
		   {
			lines[line]=realloc(lines[line],sizes[line]+50);
			sizes[line]+=50;
		   }
		   lines[line][index]=symbol;
		   index++;
	   }
	}
	/////
	

	//print lines
	if(flag)line=0;
	for(int i=line;i<10;i++)
	{
		write(1,lines[i],strlen(lines[i]));
	}
	for(int i=0;i<line;i++)
	{
		write(1,lines[i],strlen(lines[i]));
	}
        ////
	


        //free memory
	for(int i=0;i<10;i++)
	{
		free(lines[i]);
	}
	free(lines);
	return 0;
}
