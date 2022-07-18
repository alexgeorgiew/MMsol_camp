#include <stdio.h>
#include <stdint.h>


unsigned zerosCount(uint64_t mask1,uint32_t mask2,uint16_t mask3,uint8_t mask4);
unsigned zerosCount(uint64_t mask1,uint32_t mask2,uint16_t mask3,uint8_t mask4)
{
	unsigned result=0; //here we will save count of ones than than substract all bits from it
	for(int i=0;i<64;i++)
	{
		if(i<8)
		{
           if(!!(mask1&(1ull<<i)))result++;
		   if(!!(mask2&(1<<i)))result++;
		   if(!!(mask3&(1<<i)))result++;
		   if(!!(mask4&(1<<i)))result++;
		}
		else if(i<16)
		{
           if(!!(mask1&(1ull<<i)))result++;
		   if(!!(mask2&(1<<i)))result++;
		   if(!!(mask3&(1<<i)))result++;
		}
		else if(i<32)
		{
           if(!!(mask1&(1ull<<i)))result++;
		   if(!!(mask2&(1<<i)))result++;
		}
		else  // i<64
		{
           if(!!(mask1&(1ull<<i)))result++;
		}

	}

	return (64+32+16+8)-result;
}

void flipOddbits(uint64_t* mask);
void flipOddbits(uint64_t* mask)
{
	for(int i=0;i<64;i++)
	{
		if(i%2==1)
		{
			*mask=*mask^(1ull<<i);
		}
	}
}

void mirrorBits(uint16_t* mask);
void mirrorBits(uint16_t* mask)
{
	uint16_t copy=0;
      for(int i=0;i<16;i++)
	  {
		  if(!!(*mask&(1<<i)))
		  {
			  copy+=1<<(15-i);
		  }
	  }
	  *mask=copy;
}


int main()
{
    printf("Task1 :\n");
	printf("%u\n",zerosCount(0b1001,0b1111,0b100001,0b11));

	uint64_t task2=0b0000000000000000000000000000000000000000000000000000000000000000;
	flipOddbits(&task2);
	printf("Task2 : \n");
	printf("%lu= \n%lu\n",task2,0b1010101010101010101010101010101010101010101010101010101010101010);

	printf("Task3: \n");
	uint16_t task3=0b0011111100000011;
	mirrorBits(&task3);
	printf("%u=\n%u\n",task3,0b1100000011111100);
	return 0;
}
