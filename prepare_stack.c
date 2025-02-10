/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:17:19 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/02/10 13:29:02 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Put the highest number at the bottom (if needed), then sort the other two
void	ft_sort_three(t_list **tail)
{
	if ((*tail)->next->nb > (*tail)->nb && (*tail)->next->nb > (*tail)->prev->nb)
		ft_move("ra", tail, NULL);
	else if ((*tail)->prev->nb > (*tail)->nb && (*tail)->prev->nb > (*tail)->next->nb)
		ft_move("rra", tail, NULL);
	if ((*tail)->next->nb > (*tail)->prev->nb)
		ft_move("sa", tail, NULL);	
}

void	ft_sort_two(t_list **tail)
{
	if ((*tail)->nb < (*tail)->next->nb)
		ft_move("sa", tail, NULL);
	return ;
}

//Throw all but three nodes to stack b
void	ft_prepare_stack(t_list **tail_a, t_list **tail_b)
{
	int		lstsize;

	lstsize = ft_lstsize(*tail_a);
	while (lstsize > 3)
	{
			ft_move("pa", tail_a, tail_b);
 			lstsize--;
	}
	ft_sort_three(tail_a);
	ft_set_indices(*tail_a, *tail_b);
}

void	ft_set_indices(t_list *tail_a, t_list *tail_b)
{
	t_list		*curr;
	int			i;
	
	i = 0;
	if (tail_a)
	{
		curr = tail_a->next;
		while (curr != tail_a)
		{
				curr->index = i++;
				curr = curr->next;
		}
		tail_a->index = i;
	}
	i = 0;
	if (tail_b)
	{
		curr = tail_b->next;
		while (curr != tail_b)
		{
				curr->index = i++;
				curr = curr->next;
		}
		tail_b->index = i;
	}
}