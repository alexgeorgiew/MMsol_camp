#include <stdio.h>
#include <stdarg.h>

unsigned bitsNCount(unsigned count,unsigned bitscnt,...)
{
	unsigned result=0;
	va_list args;
	va_start(args,bitscnt);
	for(unsigned i=0;i<count;i++)
	{
		int mask=va_arg(args,int);
		int cnt1s=0;
                for(int j=0;j<32;j++)
		{
			if(mask&(1<<j))cnt1s++;
		}
		if(cnt1s==bitscnt)result++;
	}

	return result;
}
int main()
{
	printf("%u\n",bitsNCount(4,2,0x0a,0xff,0,1));
	printf("%u\n",bitsNCount(3,8,0xff,0x13f1,0xaaaa));
	printf("%u\n",bitsNCount(5,10,0x0a,0xa0ff,0,10,0b1010111110111));
	return 0;
}
