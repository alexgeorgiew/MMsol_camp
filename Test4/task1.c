#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <time.h>
// #define LAPTOPS_COUNT 10
unsigned int global=0;

struct Laptop{
	unsigned long long serial;
	char brand[100];
	double weight;
	double price;
};

double totalLaptopWeight(struct Laptop* lap)
{
	double total=0.0;
	if(LAPTOPS_COUNT==0)return -1.0;
	for(int i=0;i<LAPTOPS_COUNT;i++)
	{
		  total+=lap[i].weight;
	}

	return total;
}
struct Laptop*  minPriceItem(struct Laptop* lap)
{
	if(LAPTOPS_COUNT==0)
	{
		return NULL;
	}
	double min=DBL_MAX;
	struct Laptop* result;
	for(int i=0;i<LAPTOPS_COUNT;i++)
	{
		if(min>lap[i].price)
		{
			min=lap[i].price;
			result=lap+i;
		}
		
	}

	return result;
}

void print(struct Laptop* lap)
{
	fprintf(stdout,"Information about all laptops\n");
	for(int i=0;i<LAPTOPS_COUNT;i++)
	{
		fprintf(stdout,"SERIAL NUM:%lld BRAND:%s WEIGHT:%lf PRICE:%.2lf\n",lap[i].serial,lap[i].brand,lap[i].weight,lap[i].price);
	}
	fprintf(stdout,"TOTAL WEIGHT %lf\n",totalLaptopWeight(lap));
	struct Laptop* min=minPriceItem(lap);
        

	if(min==NULL)
	{
		fprintf(stdout,"There is no laptop with min price\n");
	}
	else
	{
		fprintf(stdout,"Laptop with min price is\n");
		fprintf(stdout,"SERIAL NUM:%lld BRAND:%s WEIGHT:%lf PRICE:%.2lf\n",min->serial,min->brand,min->weight,min->price);
	}

}
int main()
{
	struct Laptop *arr=(struct Laptop*)malloc(sizeof(struct Laptop)*LAPTOPS_COUNT);
        srand(time(NULL));
 	for(int i=0;i<LAPTOPS_COUNT;i++)
	{
		arr[i].serial=global++;
		int chars=8+rand()%5;
		int index=0;
		for(int k=0;k<chars;k++)
		{
			if(k==0)
			{
				arr[i].brand[index++]=65+rand()%26;
			}
			else
			{
				arr[i].brand[index++]=' ';
				arr[i].brand[index++]=97+rand()%26;
			}
		}
		arr[i].brand[index]='\0';
		arr[i].weight=(25+rand()%(10000-25+1))/1000.;
		arr[i].price=(1000+rand()%(500000-1000+1))/100.;

	}

	print(arr);
	free(arr);
	return 0;

}
