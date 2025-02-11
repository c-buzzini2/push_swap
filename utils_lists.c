/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:36:06 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/02/11 11:35:57 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list *lst)
{
	t_list	*temp_lst;

	if (!lst)
		return ;
	lst->prev->next = NULL;
	while (lst)
	{
		temp_lst = lst->next;
		free(lst);
		lst = temp_lst;
	}
	return ;
}

void	ft_error_free_exit(t_list *lst_a, t_list *lst_b)
{
	ft_puterror("Error\n");
	if (!lst_a && !lst_b)
		exit (2);
	if (lst_a)
		ft_lstclear(lst_a);
	if (lst_b)
		ft_lstclear(lst_b);
	exit (2);
}

int	ft_lstsize(t_list *tail)
{
	t_list	*curr_lst;
	int		i;

	if (tail == NULL)
		return (0);
	i = 1;
	curr_lst = tail->next;
	while (curr_lst != tail)
	{
		curr_lst = curr_lst->next;
		i++;
	}
	return (i);
}
