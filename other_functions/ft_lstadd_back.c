/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:34:44 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/01/30 11:18:45 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_lst;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_lst = ft_lstlast(*lst);
	last_lst->next = new;
	return ;
}

/*
int     main (void)
{
    char    *cont2 = "Hello";
    char    *cont1 = "World";
 //   char    *cont3 = "Life";
    t_list  *node = ft_lstnew(cont1);
  //  node->next = ft_lstnew(cont3);
    // node->next->next = ft_lstnew(cont3);
    t_list  *node2 = ft_lstnew(cont2);

    ft_lstadd_back(&node, node2);

    while (node != NULL)
    {
        printf("%s\n", (char *)(node->content));
        t_list *temp_list = node->next;
        free(node);
        node = temp_list;
    }
    free(node);
    return (0);
}
*/