#pragma once

int pseudorandom();

typedef struct node
{
	int data;
	struct node* next;
} node;

extern int HEAD;										//Ãëîáàëüíàÿ ïåğåìåííàÿ, õğàíÿùàÿ íà÷àëî ñïèñêà

//---------------------------------------ÄÎÁÀÂËÅÍÈÅ ÓÇËÀ-----------------------------------------------

void push_to_head(node* list, int data);				//

void push_to_place(node* list, int place, int data);

node* push_to_end(node* list, int data);

//-------------------------------------ÂÛÂÎÄ ÓÇËÀ ÍÀ İÊĞÀÍ---------------------------------------------

void print_from_head(node* list);

//----------------------------------------ÓÄÀËÅÍÈÅ ÓÇËÀ------------------------------------------------

void pop_from_head(node* list);

//-------------------------------------ĞÅÄÀÊÒÈĞÎÂÀÍÈÅ ÓÇËÀ---------------------------------------------

void redact_to_node(node* list, int place, int data);

//-----------------------------------------ÑÎĞÒÈĞÎÂÊÀ-------------------------------------------------

void bubble_sort(node* list);