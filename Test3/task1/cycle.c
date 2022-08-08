#include <stdio.h>
#include <stdlib.h>


int global=0;
struct Node
{
	int data;
	struct Node *next;
};

void print(struct Node* cll)
{
	struct Node* cur=cll;
	do
	{
		printf("Addres:%p Data:%d\n",cur,cur->data);
		cur=cur->next;
	}while(cur!=cll);
}

struct Node* insertAfter(struct Node* cll,int skipCount,int newElem)
{
	if(skipCount>1000000)return NULL;

	global++;
	struct Node* cur=cll;
     while(skipCount>0)
     {
	cur=cur->next;
	skipCount--;
     }

     if(cur==cur->next)// the list have only one element
     {
	     cur->next=(struct Node*)malloc(sizeof(struct Node)*1);
	     cur->next->next=cur;
	     cur->next->data=newElem;
		     return cur->next;
     }
     else
     {
	     struct Node* new=(struct Node*)malloc(sizeof(struct Node));
	     new->data=newElem;
	     new->next=cur->next;
	     cur->next=new;
	     return new;
     }
}

int main()
{
	unsigned int n;
	printf("Enter N:");
	scanf("%u",&n);
	global=n;
	if(n<=0)
	{
		fprintf(stderr,"Negative number of nodes\n");
		return 0;
	}

	struct Node *first=(struct Node*)malloc(sizeof(struct Node));
	if(first==NULL)
	{
		fprintf(stderr,"Error can not allocate memory for first element for the list\n");
		return -1;
	}
	first->next=first;

	scanf("%d",&(first->data));
	
        struct Node* cur=first;
	for(unsigned int i=0;i<n-1;i++)
	{
		
		int info;
		scanf("%d",&info);
		cur->next=(struct Node*)malloc(sizeof(struct Node));
		cur->next->data=info;
		cur->next->next=first;
		cur=cur->next;

	}

	
	printf("CAll function print\n");
	print(first);

	insertAfter(first,0,10);
	printf("Print after insertion\n");
	print(first);


	//free memory
	struct Node *begin=first;
	for(int i=0;i<global;i++)
	{
		struct Node* del=begin;
		if(i!=global-1)
		{
		begin=begin->next;
		}
		free(del);
	}
	//


	return 0;
}
