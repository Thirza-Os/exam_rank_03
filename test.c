#include "ft_list.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	cmp(int a, int b)
{
	return (a <= b);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*copy;
	int		i;

	copy = lst;
	while(lst->next)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			i = lst->data;
			lst->data = lst->next->data;
			lst->next->data = i;
			lst = copy;
		}
		else
			lst = lst->next;
	}
	lst = copy;
	return(lst);
}

int main(void)
{
	t_list	*test_list;

	test_list = (t_list*)malloc(sizeof(t_list));
	test_list->data = 6;
	test_list->next = (t_list*)malloc(sizeof(t_list));
	test_list->next->data = 9;
	test_list->next->next = (t_list*)malloc(sizeof(t_list));
	test_list->next->next->data = 2;
	test_list->next->next->next = (t_list*)malloc(sizeof(t_list));
	test_list->next->next->next->data = 5;
	test_list->next->next->next->next = NULL;
	sort_list(test_list, cmp);
	while (test_list)
	{
		printf("%i\n", test_list->data);
		test_list = test_list->next;
	}
}
