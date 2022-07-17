#include <stdio.h>
#include <math.h>
#include <stdint.h>

void printNum(uint64_t num,uint32_t base)
{
	if(num==0)return;

        printNum(num/base,base);

	if(num%base<10)
	{
		printf("%d",num%base);
	}
	else
	{
		printf("%c",num%base+87);
	}
}
int main()
{
       char number[65];
       int basefrom,baseto;
       fgets(number,65,stdin);
       scanf("%d",&basefrom);
       scanf("%d",&baseto);

       if(basefrom<2 || basefrom>36)
       {
	       printf("Invalid base of the input\n");
	       return 0;
       }
       if(baseto<2 || baseto>36)
       {
	       printf("Invalid base of the input \n");
	       return 0;
       }

       int cur=0;
       while(number[cur]!='\n')
       {
	       char f=number[cur];
	       if(f>47 && f<58) //this symbol is digit
	       {
                   if(basefrom-(f-48)<1) // we know that this digit is not for this base
		   {
                      printf("Invalid digit for this base\n");
		      return 0;
		   }
	       }
	       else if(f>96 && f<123)
	       {
		       if(basefrom-(f-97+10)<1)
		       {
			       printf("Invalid digit for this base\n"); // we know that that letter is not for this base
				       return 0;
		       }
	       }
	       else
	       {
		       printf("Symbol is neeither digit neither letter\n"); 
		       return 0;
	       }
	       
	       cur++;
       }


       if(cur==0)
       {
	       printf("There is no nunmber !!\n");
	       return 0;
       }
       
       uint64_t from10=0;
       for(int i=cur-1;i>-1;i--) // we will convert input number to number in base 10
	{
		if(number[i]<58) // we know that this is digit
		{
			from10+=(number[i]-48)*pow(basefrom,cur-1-i);
		}
		else//this is letter
		{
			from10+=(number[i]-87)*pow(basefrom,cur-1-i);
		}
	}

       printf("Input number in %d base is: ",baseto);

       if(from10!=0)
       {
               printNum(from10,baseto);
       }
       else
       {
	       printf("0");
       }
       printf("\n");
	return 0;
}
