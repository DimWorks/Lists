#pragma once

typedef struct node
{
	int data;
	struct node* next;
} node;

extern int HEAD;

node* push_to_end(node* list, int data);
void print_from_head(node* list);