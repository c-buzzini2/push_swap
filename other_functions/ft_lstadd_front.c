/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:34:44 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/01/30 11:18:49 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
	return ;
}

/* int     main (void)
{
    char    *cont2 = "Hello";
    char    *cont1 = "World";
 //   char    *cont3 = "Life";
    t_list  *node = ft_lstnew(cont1);
  //  node->next = ft_lstnew(cont3);
    // node->next->next = ft_lstnew(cont3);
    t_list  *node2 = ft_lstnew(cont2);

    ft_lstadd_front(&node, node2);

    while (node2 != NULL)
    {
        printf("%s\n", (char *)(node2->content));
        t_list *temp_list = node2->next;
        free(node2);
        node2 = temp_list;
    }
    free(node2);
    return (0);
}
 */

//FREEING LISTS
/*
while (curr_lst != NULL)
    {
        t_list *temp = curr_lst;
        curr_lst = curr_lst->next;
        free(temp);
    }
*/