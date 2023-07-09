#pragma once

int pseudorandom();

typedef struct node
{
	int data;
	struct node* next;
} node;

extern int HEAD;										//Глобальная переменная, хранящая начало списка

//---------------------------------------ДОБАВЛЕНИЕ УЗЛА-----------------------------------------------

void push_to_head(int data);				//

void push_to_place(int place, int data);

node* push_to_end(node* list, int data);

//-------------------------------------ВЫВОД УЗЛА НА ЭКРАН---------------------------------------------

void print_from_head();

//----------------------------------------УДАЛЕНИЕ УЗЛА------------------------------------------------

void pop_from_head();
void pop_from_end();
void pop_from_place(int place);

//-------------------------------------РЕДАКТИРОВАНИЕ УЗЛА---------------------------------------------

void redact_to_node(int place, int data);

//-----------------------------------------СОРТИРОВКА-------------------------------------------------

void bubble_sort();

//------

void clean_sheet();