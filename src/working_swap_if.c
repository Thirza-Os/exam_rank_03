#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>

int	cmp(int a, int b)
{
	printf("This a: %i\n This is b:%i\n", a, b);
	return (a <= b);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*tmp;
	int		copy;

	tmp = lst;
	while (lst->next)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			copy = lst->data;
			lst->data = lst->next->data;
			lst->next->data = copy;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}

int main(void)
{
	t_list *lst;
	int i = 1;
	int j = 2;

	lst = (t_list*)malloc(sizeof(t_list));
	lst->data = 4;
	lst->next = (t_list*)malloc(sizeof(t_list));
	lst->next->data = 3;
	lst->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->data = 2;
	lst->next->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->next->data = 1;
	lst->next->next->next->next =  NULL;

	sort_list(lst, cmp);

	while (lst != NULL)
	{
		t_list *temp = lst->next;
		printf("%d\n", lst->data);
		free(lst);
		lst = temp;
		// lst = lst->next;
	}
	// system("leaks --quiet a.out");
	return (0);
}