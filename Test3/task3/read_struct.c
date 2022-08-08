#include <stdio.h>

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




int main()
{
	FILE* f=fopen("Items","rb");
	if(f==NULL)
	{
		fprintf(stderr,"can not open file read\n");
		return -1;
	}
	struct Product arr[40];

	fread(arr,sizeof(struct Product),40,f);
	
	for(int i=0;i<40;i++)
	{
		print(arr[i]);
	}

	fclose(f);
	return 0;
}
