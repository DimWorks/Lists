#pragma once

int pseudorandom();

typedef struct node
{
	int data;
	struct node* next;
} node;

extern int HEAD;

void push_to_head(node* list, int data);

node* push_to_end(node* list, int data);

void print_from_head(node* list);

void pop_from_head(node* list);