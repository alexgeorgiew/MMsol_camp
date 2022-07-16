#include <stdio.h>


int main()
{
	double op1,op2,result;
	char option;
	while(1)
	{
		scanf("%lf %c %lf",&op1,&option,&op2);
                if(feof(stdin))return 0;
		if(option!='+' && option !='-' && option!='x' && option!='/')
		{
			fprintf(stderr,"You enter invalid expression\n");
			return 0;
		}

		if(option=='+')
		{
			result=op1+op2;
		}
		else if(option=='-')
		{
			result=op1-op2;
		}
		else if(option=='x')
		{
			result=op1*op2;
		}
		else
		{
			result=op1/op2;
		}
  
		printf("%.2lf\n",result);

		
	}

	return 0;
}
