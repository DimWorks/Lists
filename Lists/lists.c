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
	RUS											// Задаём работу с русским языком
	node* tmp = NULL;
	if ((tmp = (node*)malloc(sizeof(node))))	// Выделение памяти под новый элемент
	{											// Если память удалось выделить
		tmp->data = data;						// Запись данных в узел списка
		tmp->next = list;						// Запись указателя на NULL
		HEAD = tmp;										//
	}											// 
	else										// Если не удалось выделить память
	{											// 
		printf("Недостаточно памяти!\n");		// Выводим сообщение о проблеме
	}
}

void push_to_place(node* list, int place, int data)
{
	RUS

	if (place < 1 || place > jump_to_last(list))
	{
		printf("Задана неверная позиция для новго элемента\n");
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
		if ((tmp = (node*)malloc(sizeof(node))))	// Выделение памяти под новый элемент
		{											// Если память удалось выделить
			node* tmp_list = list;					// Создаём вспомогательный указатель на узел
			tmp->data = data;						// Записываем данные в узел
			for (int i = 1; i < place - 1; i++)		// Пробегаем по списку до узла предшествующему этому
			{
				tmp_list->next = list->next;		// Записываем во вспомогательный указатель адрес следующего узла
			}
			tmp->next = tmp_list->next;
			tmp_list->next = tmp;
		}											// 
		else										// Если не удалось выделить память
		{											// 
			printf("Недостаточно памяти!\n");		// Выводим сообщение о проблеме
		}
	}
}

node* push_to_end(node* list, int data)
{
	RUS											// Задаём работу с русским языком
	node* tmp = NULL;
	if ((tmp = (node*)malloc(sizeof(node))))	// Выделение памяти под новый элемент
	{											// Если память удалось выделить
		tmp->data = data;						// Запись данных в узел списка
		tmp->next = NULL;						// Запись указателя на NULL
		if (list != NULL)						// Если это не первый элемент списка
		{										//
			list = jump_to_last(list);			// Находим указатель на последний элемент списка
			list->next = tmp;					// Запись адреса последнего элемента в указатель предпоследнего узла
		}										//
		else									// Если это первый элемент списка
		{										//
			HEAD = tmp;							// Записываем в глобальную переменную начало списка
			list = tmp;							// Записываем адрес текущего узла
		}										//
	}											// 
	else										// Если не удалось выделить память
	{											// 
		printf("Недостаточно памяти!\n");		// Выводим сообщение о проблеме
	}
	//printf("\t%d\t%d\n", list, HEAD);
	return list;								// Возвращаем адрес текущего узла
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
		printf("Список пуст!\n");
	}
}

void pop_from_head(node* list)
{
	RUS


	if (list == NULL)
	{
		printf("Список пуст!\n");
	}
	else
	{
		node* tmp = list;
		HEAD = tmp->next;
		free(tmp);
	}
}