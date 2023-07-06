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
	RUS

	if (place < 1 || place > jump_to_last(list))
	{
		printf("������ �������� ������� ��� ����� ��������\n");
	}
	else if (place == 1)
	{
		push_to_head(HEAD, data);
	}
	else if (place == jump_to_last(list))
	{
		push_to_end(place, data);
	}
	else
	{
		node* tmp = NULL;
		if ((tmp = (node*)malloc(sizeof(node))))	// ��������� ������ ��� ����� �������
		{											// ���� ������ ������� ��������
			node* tmp_list = list;					// ������ ��������������� ��������� �� ����
			tmp->data = data;						// ���������� ������ � ����
			for (int i = 1; i < place - 1; i++)		// ��������� �� ������ �� ���� ��������������� �����
			{
				tmp_list->next = list->next;		// ���������� �� ��������������� ��������� ����� ���������� ����
			}
			tmp->next = tmp_list->next;
			tmp_list->next = tmp;
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
	RUS


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