#include <stdio.h>

int main()
{
	char str[501];
	scanf("%s",str);

	
	int i=0;
	while(str[i]!='\0')
	{
		if(i==500)
		{
			fprintf(stderr,"Over 500 characters\n");
			return 0;
		}
		if(i%2==0)
		{
			if(str[i]>=48 && str[i]<=57)
			{
		   		printf("%c",str[i]-48+65);
			}
			else
			{
				fprintf(stderr,"Wrong input\n");
				return 0;
			}
		}
		else
		{
			if(str[i]==48)
			{
				printf("!");
			}
			else if(str[i]==49)
			{
				printf("#");
			}
			else if(str[i]==50)
			{
				printf("/");
			}
			else if(str[i]==51)
			{
				printf("~");
			}
			else if(str[i]==52)
			{
				printf("=");
			}
			else if(str[i]==53)
			{
				printf("'");
			}
			else if(str[i]==54)
			{
				printf("\\");

			}
			else if(str[i]==55)
			{
				printf(">");
			}
			else if(str[i]==56)
			{
				printf(".");
			}
			else if(str[i]==57)
			{
				printf(",");
			}
			else
			{
				fprintf(stderr,"Wrong input\n");
				return 0;
			}
		}
		i++;
	}
	printf("\n");
	return 0;
}
