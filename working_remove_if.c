#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>

int	cmp(void *dat_one, void *dat_two)
{
	int *i = dat_one;
	int *j = dat_two;

	if (*i == *j)
		return(0);
	return(1);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *current;
	t_list *temp;

	current = *begin_list;
	while(current && cmp((current)->data, data_ref) == 0)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*begin_list = current;
	while(current && current->next)
	{
		if (cmp(current->next->data, data_ref) == 0)
		{
			temp = current->next->next;
			free(current->next);
			current->next = temp;
		}
		current = current->next;
	}
}

int main(void)
{
	t_list *lst;
	int i = 2;
	int j = 2;

	lst = (t_list*)malloc(sizeof(t_list));
	lst->data = &i;
	lst->next = (t_list*)malloc(sizeof(t_list));
	lst->next->data = &i;
	lst->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->data = &i;
	lst->next->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->next->data = &i;
	lst->next->next->next->next =  NULL;

	ft_list_remove_if(&lst, &j, cmp);

	while (lst != NULL)
	{
		t_list *temp = lst->next;
		printf("%d\n", *(int*)lst->data);
		free(lst);
		// lst = temp;
		lst = lst->next;
	}
	// system("leaks --quiet a.out");
	return (0);
}