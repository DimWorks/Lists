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
	print_from_head(HEAD);
	printf("\n");
	for (int i = 7; i > -1; i--)
	{
		push_to_head(HEAD, i);
	}
	print_from_head(HEAD);

	for (int i = 0; i < 3; i++)
	{
		pop_from_head(HEAD);
	}

	printf("\n");
	print_from_head(HEAD);

	/*for (int i = 0; i < 20; i++)
	{
		printf("test: %d\n", pseudorandom());
	}*/
}