#include <stdio.h>
#include "my_lists.h"

int HEAD; 								// ���������� ������������� ���������� ����������			

int main()
{
	node* list = NULL;
	for (int i = 0; i < 13; i++)
	{
		list = push_to_end(list, i+8);
	}	
	print_from_head(HEAD);
}