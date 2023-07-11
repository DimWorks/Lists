#include <stdio.h>
#include "my_lists.h"

int HEAD; 								// ќбъ€вление использовани€ глобальной переменной			

int main()
{
	node* list = NULL;
	for (int i = 0; i < 7; i++)
	{
		list = push_to_end(list, i+8);
	}	
	print_from_head();
	printf("\n");
	for (int i = 7; i > -1; i--)
	{
		push_to_head(i);
	}
	print_from_head();

	for (int i = 0; i < 3; i++)
	{
		pop_from_head();
	}

	printf("\n");
	print_from_head();

	push_to_place(2, 489);

	printf("\n");
	print_from_head();

	redact_to_node(5, 345);

	printf("\n");
	print_from_head();

	bubble_sort();

	printf("\n");
	print_from_head();

	pop_from_end();

	printf("\n");
	print_from_head();

	pop_from_place(5);

	printf("\n");
	print_from_head();

	printf("\n");
	print_from_end();

	clean_sheet();

	printf("\n");
	print_from_head();

	/*for (int i = 0; i < 20; i++)
	{
		printf("test: %d\n", pseudorandom());
	}*/
}