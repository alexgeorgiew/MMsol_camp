#include <stdio.h>
#include <stdint.h>

unsigned onesCount(uint64_t mask);
unsigned onesCount(uint64_t mask)
{
    unsigned result=0;

    for(int i=0;i<64;i++)
    {
	    if(!!(mask&(1ull<<i)))result++;
    }
    return result;
}


int main()
{
	unsigned res=onesCount(0b0101011);
	printf("%u\n",res);
	return 0;
}
