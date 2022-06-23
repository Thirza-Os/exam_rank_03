#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>

int cmp(void *data, void *data_ref)
{
	int *i = data;
	int *j = data_ref;

	if (*i == *j)
		return (0);
	return (1);
}

void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list  *current;
    t_list  *temp;

    while(*begin_list && cmp ((*begin_list)->data, data_ref) == 0) // Head pointer
    {
        current = *begin_list;
        *begin_list = (*begin_list)->next;
        free(current);
    }
    current = *begin_list;
    while(current && current->next)                     //content linked lists
    {
        if (cmp(current->next->data, data_ref) == 0)
        {
            temp = current->next;
            current->next = temp->next;
            free(temp);
        }
        current = current->next;
    }
}

int main(void)
{
	t_list *lst;
	int i = 1;
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
		printf("%d\n", *(int*)lst->data);
		lst = lst->next;
	}

	return (0);
}