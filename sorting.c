/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:17:19 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/02/09 13:15:32 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void ft_push_cheapest(t_list **tail_a, t_list **tail_b)
{
	t_list	*cheapest;

	cheapest = ft_choose_cheapest(*tail_a, *tail_b);
	printf("Cheapest: %d\n", cheapest->nb);
	ft_put_on_top(&cheapest);
	ft_put_on_top(&cheapest->dest);
	ft_push(tail_b, tail_a);
}

void ft_put_on_top(t_list **node)
{
	int		lstsize;
	int		rotations;
	
	lstsize = ft_lstsize(*node);
	if ((*node)->index < lstsize / 2 + 1)
	{
		rotations = (*node)->index;
		while (rotations > 0)
		{
			ft_rotate_up(node);
			rotations--;
		}
			
	}
	else if ((*node)->index >= lstsize / 2 + 1)
	{
		rotations = (lstsize) - (*node)->index;
		while (rotations > 0)
		{
			ft_rotate_down(node);
			rotations--;
		}
	}
}

