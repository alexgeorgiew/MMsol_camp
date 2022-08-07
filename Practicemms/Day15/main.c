#include "linkedlist.h"







int main()
{
	struct Node* first=(struct Node*)malloc(sizeof(struct Node)*1);
	first->data=2;
	first->next=NULL;

	push_front(&first,1);
	print(first);
	reverse(&first);
	
	//printf("%d\n",first->data);
	
	return 0;
}
