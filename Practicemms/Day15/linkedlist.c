#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"



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
		struct Node* todel=*node;
		*node=NULL;  //free the only node in the struct
		free(todel);
		return;
	}

	struct Node* second_last=*node;
	struct Node* last=second_last->next;
	while(last->next != NULL)
	{
		second_last=last;
		last=last->next;
	}
        second_last->next=NULL;
	free(last);//free memory of last node
}

void print(struct Node* node)
{
	while(node != NULL)
	{
		printf("node addr:%p data:%d next addr:%p\n",node,node->data,node->next);
		node=node->next;
	}
}

void reverse(struct Node** node)
{
	struct Node** left;
	struct Node** mid;
	struct Node** right;

	if( (*node) == NULL)
	{
		return;
	}
	else if( (*node)->next == NULL)return;
	else
	{
		struct Node* n=NULL;
		left=&n;

		mid=node;
		right=&((*mid)->next);
		while( ((*right)->next) != NULL )
		{
                   (*mid)->next=(*left);
		   left=mid;
		   mid=right;
		   right=&((*right)->next);
		}
                 printf("%d %d \n",(*mid)->data,(*right)->data);
		(*mid)->next=(*left);
		
		(*node)=(*right);
	}
}
