
//to not have unused memory
//size of name must be 4*d+2  where d is natural number 
 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
int globalid=1;
struct Product{
	unsigned int id;
	 float price;
	unsigned short sales_count;
	char name[10];
};


void print(struct Product input)
{
	printf("ID:%u  PRICE:%f  SALES_COUNT:%hu NAME:%s  PROFIT:%f\n" ,input.id,input.price,input.sales_count,input.name,input.price*input.sales_count);
}

int comparator(const void *a,const void *b)
{
   struct Product *left=(struct Product*)a;
   struct Product *right=(struct Product*)b;
   float moneyl=(left->sales_count)*(left->price);
   float moneyr=(right->sales_count)*(right->price);

   if(fabs(moneyl-moneyr) < 0.1)
   {
      int res=strcmp(left->name,right->name);
	if(res==0)
	{
		return left->id - right->id;
	}
	else return res;
   }
   else if(moneyl > moneyr)return -1;
   else return 1;
}

int main()
{	
     struct Product arr[30];
     char* product_names[5]={"product1","product2","product3","product4","product5"};
     for(int i=0;i<30;i++)
     {
	     arr[i].id=globalid;
	     globalid++;
	     arr[i].sales_count= rand()%1001;
	     arr[i].price= (150 + rand()%(20025-150) )/100.;
	     strcpy(arr[i].name,product_names[rand()%5]);
     }

	qsort(arr,30,sizeof(struct Product),comparator);
	
	for(int i=0;i<30;i++)
	{
		print(arr[i]);
	}
     return 0;
}
