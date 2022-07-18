#include <stdio.h>
#include <stdarg.h>

size_t onesCount(size_t count,...);
size_t onesCount(size_t count,...)
{
   va_list args;
   va_start (args,count);
   size_t result=0;
   for(size_t i=0;i<count;i++)
   { 
	   int mask=va_arg(args,int);
	   for(size_t j=0;j<32;j++)
	   {
           if(!!(mask&(1<<j)))result++;
	   }

   }

   va_end(args);
   return result;
}

int main()
{
     printf("onesCount(4,0x0a,0,1,2)= %lu\n",onesCount(4,0x0a,0,1,2));
	 printf("onesCount(3,0xff,0x131,0xaaaa)= %lu\n",onesCount(3,0xff,0x131,0xaaaa));
	 printf("onesCount(2,0b0001,9)= %lu\n",onesCount(2,0b0001,9));
    return 0;
}
