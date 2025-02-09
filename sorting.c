/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:17:19 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/02/09 15:03:38 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void ft_push_cheapest(t_list **tail_a, t_list **tail_b)
{
	t_list	*cheapest;

	cheapest = ft_choose_cheapest(*tail_a, *tail_b);
	printf("Cheapest: %d\n", cheapest->nb);
	ft_put_on_top(tail_b, cheapest);
	ft_put_on_top(tail_a, cheapest->dest);
	ft_push(tail_b, tail_a);
	ft_smallest_first(tail_a);
}

void ft_put_on_top(t_list **tail, t_list *node)
{
	int		lstsize;
	int		rotations;
	
	lstsize = ft_lstsize(*tail);
	if (node->index < lstsize / 2 + 1)
	{
		rotations = node->index;
		printf("ROTATIONS: %d\n", rotations);
		while (rotations > 0)
		{
			ft_rotate_up(tail);
			rotations--;
		}
	}
	else if (node->index >= lstsize / 2 + 1)
	{
		rotations = (lstsize) - node->index;
		while (rotations > 0)
		{
			ft_rotate_down(tail);
			rotations--;
		}
	}
}

void ft_smallest_first(t_list **tail)
{
	t_list	*smallest;
	int		lstsize;
	
	lstsize = ft_lstsize(*tail);
	smallest = ft_smallest_nb(*tail);
	if (smallest->index < lstsize / 2 + 1)
	{
		while ((*tail)->next != smallest)		
			ft_rotate_up(tail);
	}
	else if (smallest->index >= lstsize / 2 + 1)
	{
		while ((*tail)->next != smallest)		
			ft_rotate_down(tail);
	}
}