#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "my_lists.h"

#define RUS setlocale(LC_ALL, "RU");

int HEAD;

node* jump_to_last(node* list)
{
	while ((list->next) != NULL)
	{
		list = list->next;
	}
	return list;
}

void push_to_head(node* list, int data)
{
	RUS											// ����� ������ � ������� ������
	node* tmp = NULL;
	if ((tmp = (node*)malloc(sizeof(node))))	// ��������� ������ ��� ����� �������
	{											// ���� ������ ������� ��������
		tmp->data = data;						// ������ ������ � ���� ������
		tmp->next = list;						// ������ ��������� �� NULL
		HEAD = tmp;										//
	}											// 
	else										// ���� �� ������� �������� ������
	{											// 
		printf("������������ ������!\n");		// ������� ��������� � ��������
	}
}

void push_to_place(node* list, int place, int data)
{
	if (place < 1 || place > jump_to_last())
	{
		printf("������ �������� ������� ��� ����� ��������\n");
	}
	else if (place == 1)
	{
		push_to_head(HEAD, data);
	}
	else if (place == jump_to_last())
	{
		push_to_end(place, data);
	}
	else
	{
		node* tmp = NULL;
		if ((tmp = (node*)malloc(sizeof(node))))	// ��������� ������ ��� ����� �������
		{											// ���� ������ ������� ��������
			
		}											// 
		else										// ���� �� ������� �������� ������
		{											// 
			printf("������������ ������!\n");		// ������� ��������� � ��������
		}
	}
}

node* push_to_end(node* list, int data)
{
	RUS											// ����� ������ � ������� ������
	node* tmp = NULL;
	if ((tmp = (node*)malloc(sizeof(node))))	// ��������� ������ ��� ����� �������
	{											// ���� ������ ������� ��������
		tmp->data = data;						// ������ ������ � ���� ������
		tmp->next = NULL;						// ������ ��������� �� NULL
		if (list != NULL)						// ���� ��� �� ������ ������� ������
		{										//
			list = jump_to_last(list);			// ������� ��������� �� ��������� ������� ������
			list->next = tmp;					// ������ ������ ���������� �������� � ��������� �������������� ����
		}										//
		else									// ���� ��� ������ ������� ������
		{										//
			HEAD = tmp;							// ���������� � ���������� ���������� ������ ������
			list = tmp;							// ���������� ����� �������� ����
		}										//
	}											// 
	else										// ���� �� ������� �������� ������
	{											// 
		printf("������������ ������!\n");		// ������� ��������� � ��������
	}
	//printf("\t%d\t%d\n", list, HEAD);
	return list;								// ���������� ����� �������� ����
}

void print_from_head(node* list)
{
	RUS
	if (list != NULL)
	{
		while (list != NULL)
		{
			printf("%d ", list->data);
			list = list->next;
		}
	}
	else
	{
		printf("������ ����!\n");
	}
}

void pop_from_head(node* list)
{
	if (list == NULL)
	{
		printf("������ ����!\n");
	}
	else
	{
		node* tmp = list;
		HEAD = tmp->next;
		free(tmp);
	}
}