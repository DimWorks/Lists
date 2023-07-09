#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "my_lists.h"

#define RUS setlocale(LC_ALL, "RU");

int HEAD;
int END;

//---------------------------����� ���������� �������� ������------------------------------

node* jump_to_last(node* list)
{
	END = 0;
	while ((list->next) != NULL)
	{
		list = list->next;
		END++;
	}
	return list;
}

//-------------------------------������ ���� � ������---------------------------------------

void push_to_head(int data)
{
	node* list = HEAD;

	RUS											// ����� ������ � ������� ������
	node* tmp = NULL;
	if ((tmp = (node*)malloc(sizeof(node))))	// ��������� ������ ��� ����� �������
	{											// ���� ������ ������� ��������
		tmp->data = data;						// ������ ������ � ���� ������
		tmp->next = list;						// ������ ��������� �� NULL
		HEAD = tmp;								//
	}											// 
	else										// ���� �� ������� �������� ������
	{											// 
		printf("������������ ������!\n");		// ������� ��������� � ��������
	}
}

void push_to_place(int place, int data)
{
	node* list = HEAD;
	RUS

	if (place < 1 || place > jump_to_last(list))			
	{
		printf("������ �������� ������� ��� ����� ��������\n");
	}
	else if (place == 1)
	{
		push_to_head(data);
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
			node* tmp_list = HEAD;					// ������ ��������������� ��������� �� ����
			tmp->data = data;						// ���������� ������ � ����
			for (int i = 1; i < place - 1; i++)		// ��������� �� ������ �� ���� ��������������� �����
			{
				tmp_list->next = list->next;		// ���������� �� ��������������� ��������� ����� ���������� ����
			}
			tmp->next = tmp_list->next;				//
			tmp_list->next = tmp;					// ��������� ����� ����� ������������ � ���������� ������
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
	//printf("Test: %d\t%d", tmp->data, tmp->next);
	return list;								// ���������� ����� �������� ����
}

//-----------------------------����� ������ � �������-----------------------

void print_from_head()
{
	node* list = HEAD;

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

//------------------------------�������� �����------------------------------

void pop_from_head()
{
	node* list = HEAD;

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

void pop_from_end()
{
	node* list = HEAD;

	RUS

	if (list == NULL)
	{
		printf("������ ����!\n");
	}
	else
	{
		list = jump_to_last(HEAD);
		node* prev_node = HEAD;
		while (prev_node->next != list)
		{
			prev_node = prev_node->next;
		}
		free(list);
		prev_node->next = NULL;
	}	
}

void pop_from_place(int place)
{
	RUS

		if (place < 1 || place > jump_to_last(HEAD))
		{
			printf("������ �������� ������� ��� ����� ��������\n");
		}
		else if (place == 1)
		{
			pop_from_head();
		}
		else if (place == jump_to_last(HEAD))
		{
			pop_from_end();
		}
		else
		{
			node* list = HEAD;

			for (int i = 0; i < place; i++)
			{
				list = list->next;
			}
			
			node* prev_node = HEAD;
			while (prev_node->next != list)
			{
				prev_node = prev_node->next;
			}
			prev_node->next = list->next;
			free(list);

		}
}

//--------------------------������������� �����------------------------------

void redact_to_node(int place, int data)
{
	node* list = HEAD;
	RUS

	if (list == NULL)
	{
		printf("������ ����!\n");
	}
	else
	{
		jump_to_last(list);
		if (place < 1 || place > END)
		{
			printf("\n������ �������� ������� ��� ����� ��������\n");
		}
		else if (place == 1)
		{
			list->data = data;
		}
		else if (place == END)
		{
			list->data = data;
		}
		else
		{
			for (int i = 0; i < place; i++)
			{
				list = list->next;
			}
			list->data = data;
		}
	}
}

//----------------------------------���������� ���������-------------------------------------

void bubble_sort()
{
	node* list = HEAD;
	jump_to_last(list);
	for (int i = 0; i < END+1; i++)
	{
		node* next_node = HEAD;
		for (int j = 0; j < END; j++)
		{
			if (list->data < next_node->data)
			{
				int tmp = list->data;
				list->data = next_node->data;
				next_node->data = tmp;
			}
			next_node = next_node->next;			
		}
		list = list->next;
	}
}

//------------

void clean_sheet()
{
	node* list = HEAD;
	node* tmp;

	while (list->next != NULL)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	HEAD = NULL;
}