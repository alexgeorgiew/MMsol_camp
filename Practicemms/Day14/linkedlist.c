#include <stdio.h>
#include <stdlib.h>


struct Node{
	struct Node* next;
	int data;
};



void push_front(struct Node** list,int info)
{
	struct Node* new_node=malloc(sizeof(struct Node)*1);
	new_node->next=*list;
	new_node->data=info;
	*list=new_node;
}

void pop_back(struct Node** node)
{
	if( *node == NULL)return;
	if((*node)->next == NULL)
	{
		free(*node);  //free the only node in the struct
		*node=NULL;
		return;
	}

	struct Node* second_last=*node;
	struct Node* last=second_last->next;
	while(last->next != NULL)
	{
		second_last=last;
		last=last->next;
	}

	free(second_last->next);//free memory of last node
	second_last->next=NULL;
}

void print(struct Node* node)
{
	while(node != NULL)
	{
		printf("node addr:%p data:%d next addr:%p\n",node,node->data,node->next);
		node=node->next;
	}
}

int main()
{
       	struct Node* info=malloc(sizeof(struct Node)*1);
	info->next=NULL;
	info->data=3;
        push_front(&info,2);
	print(info);

        printf("pop back\n");

	pop_back(&info);
	pop_back(&info);

	push_front(&info,1);
	print(info);


	return 0;
}
