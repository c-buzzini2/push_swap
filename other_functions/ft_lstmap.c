/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:45:24 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/01/30 11:19:17 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* static void    ft_del_content(void *content)
{
    free(content);
    return ;
}

static void    *ft_test(void *content)
{
	*(int *)content = 2;
    int *new_cont = malloc(sizeof(int));
    if (new_cont == NULL)
        return NULL;
    *new_cont = 42;  
    return (new_cont);
} 
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*lst2;
	void	*next_cont;
	t_list	*next_node;

	if (!lst || !f || !del)
		return (NULL);
	lst2 = NULL;
	while (lst)
	{
		next_cont = f(lst->content);
		next_node = ft_lstnew(next_cont);
		if (next_node == NULL)
		{
			del(next_cont);
			ft_lstclear(&lst2, del);
			return (NULL);
		}
		ft_lstadd_back(&lst2, next_node);
		lst = lst->next;
	}
	return (lst2);
}

/* 
int     main (void)
{
   	int *cont1 = malloc(sizeof(int));
    int *cont2 = malloc(sizeof(int));
    int *cont3 = malloc(sizeof(int));
	if (!cont1 || !cont2 || !cont3)
        return (0);
	
	*cont1 = 1;
    *cont2 = 2;
    *cont3 = 3;
 	
	t_list  *node = ft_lstnew(cont1);
    t_list  *node2 = ft_lstnew(cont2);
    t_list  *node3 = ft_lstnew(cont3);
    t_list  *curr_lst;
    t_list  *new_lst;
    
	ft_lstadd_back(&node, node2);
    ft_lstadd_back(&node, node3);
    curr_lst = node;
    while (curr_lst != NULL)
    {
        printf("%d\n", *(int *)(curr_lst->content));
        curr_lst = curr_lst->next;
    }
    new_lst = ft_lstmap(node, ft_test, ft_del_content);
    curr_lst = new_lst;
    while (curr_lst != NULL)
    {
        printf("%d\n", *(int *)(curr_lst->content));
        curr_lst = curr_lst->next;
    }
   	ft_lstclear(&new_lst, ft_del_content);
	ft_lstclear(&node, ft_del_content);
    return (0);
}
   */