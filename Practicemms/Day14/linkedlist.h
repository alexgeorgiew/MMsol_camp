#include <stdio.h>
#include <stdlib.h>

struct Node{
	struct Node* next;
	int data;
};



void push_front(struct Node** list,int info);

void pop_back(struct Node** node);

void print(struct Node* node);

void reverse(struct Node** node);
