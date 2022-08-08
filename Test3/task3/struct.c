


//size of product_name must be 3+8*d  where d is natural number
//

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
unsigned int globalid=1;
struct Product
{
	double old_price;
	double new_price;
	unsigned int id;
	char product_type;
	char product_name[11];
};

void print(struct Product input)
{
	printf("OLD_PRICE:%.2lf  NEW_PRICE:%.2lf  ID:%u  PRODUCT_TYPE:%c  PRODUCT_NAME:%s\n",input.old_price,input.new_price,input.id,input.product_type,input.product_name);
}

int comparator(const void* a,const void* b)
{
	struct Product* left= (struct Product*)a;
	struct Product* right=(struct Product*)b;

	double changel=left->new_price - left->old_price;
	double changer=right->new_price - right->old_price;

	if(fabs(changel-changer)<0.01)  // we will think that both changes are equal
	{
		int res=(int)right->product_type - (int)left->product_type;
		if(res==0)
		{
			int res2=strcmp(left->product_name,right->product_name);
			if(res2==0)
			{
				return left->id - right->id;
			}
			else if(res>0)return 1;
			else return -1;
		}
		else if(res>0)return 1;
		else return -1;
	}
	else if(changer-changel<0.0)
	{
		return -1;
	}
	else return 1;

}

void write_to_file(struct Product arr[])
{
	FILE* f=fopen("Items","wb");
        if(f==NULL)
	{
		fprintf(stderr,"Can not open file to write products\n");
	}

	fwrite(arr,sizeof(struct Product),40,f);
	fclose(f);

}

int main()
{
	struct Product arr[40];
	char* names[5]={"product1","product2","product3","product4","product5"};

	for(int i=0;i<40;i++)
	{
		arr[i].old_price=(499 + (rand()%10045-499+1) )/100.;
		arr[i].new_price=(499+ (rand()%10045-499+1) )/100.;
		arr[i].product_type='A'+ rand()%4;
		strcpy(arr[i].product_name,names[rand()%5]);
		arr[i].id=globalid;
		globalid++;
		print(arr[i]);
	}
        

	qsort(arr,40,sizeof(struct Product),comparator);
	printf("\nAfter sorting\n");
	for(int i=0;i<40;i++)
	{
		print(arr[i]);
	}

	write_to_file(arr);
	return 0;
}
