/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:34:44 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/01/30 11:19:28 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*curr_lst;
	int		i;

	if (lst == NULL)
		return (0);
	i = 0;
	curr_lst = lst;
	while (curr_lst != NULL)
	{
		curr_lst = curr_lst->next;
		i++;
	}
	return (i);
}

/* 
int     main (void)
{
    char    *cont2 = "Hello";
    char    *cont1 = "World";
    char    *cont3 = "Life";
    t_list  *node = ft_lstnew(cont1);
    node->next = ft_lstnew(cont2);
    node->next->next = ft_lstnew(cont3);
    printf("%d", ft_lstsize(node));
    free(node->next->next);
    free(node->next);
    free(node);
    return (0);
} */
