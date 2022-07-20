#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
                      
#define TINT 1
#define TCHAR 2
#define TDOUBLE 3
#define TFLOAT 4
#define TUINT8_T 5
#define TUINT16_T 6
#define TUINT32_T 7
#define TUINT64_T 8


void printValue(const void* valuePtr,uint8_t flag)
{
    if(flag==1)
    {
         printf("%d\n",*(int*)valuePtr);
    }
    else if(flag==2)
    {
        printf("%c\n",*(char*)valuePtr);
    }
    else if(flag==3)
    {
	printf("%.2lf\n",*(double*)valuePtr);
    }
    else if(flag==4)
    {
	printf("%.2f\n",*(float*)valuePtr);
    }
    else if(flag==5)
    {
        printf("%" PRIu8 "\n",*(uint8_t*)valuePtr);
    }
    else if(flag==6)
    {
        printf("%" PRIu16 "\n",*(uint16_t*)valuePtr);
    }
    else if(flag==7)
    {
	printf("%" PRIu32 "\n",*(uint32_t*)valuePtr);
    }
    else if(flag==8)
    {
	printf("%" PRIu64 "\n",*(uint64_t*)valuePtr);
    }
    else
    {
	    printf("Unknown type!!!\n");
    }
}

int main()
{
	int num=23;
	printValue(&num,TINT);

	double num2=3.14;
	printValue(&num2,TDOUBLE);

	char symbol='A';
	printValue(&symbol,TCHAR);

	return 0;
}


