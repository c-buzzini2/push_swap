/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_cheapest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:09:22 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/02/09 14:26:58 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_choose_cheapest(t_list *tail_a, t_list *tail_b)
{
	t_list	*curr;
	int		cost;
	t_list	*cheapest;
	int		lowest_cost;
	int		lstsize_b;

	lstsize_b = ft_lstsize(tail_b);
	lowest_cost = ft_lstsize(tail_a) + lstsize_b;
	curr = tail_b->next;
	while (lstsize_b > 0)
	{
		curr->dest = ft_find_destination(tail_a, curr->nb);
		cost = ft_calculate_cost(curr->dest->index, curr->index, tail_a, tail_b);
		printf("Nb: %d, dest-index: %d, cost: %d\n", curr->nb, curr->dest->index, cost);
		if (cost < lowest_cost)
		{
			lowest_cost = cost;
			cheapest = curr;
		}
		lstsize_b--;
		curr = curr->next;
	}
	return(cheapest);
}

t_list	*ft_find_destination(t_list *tail_a, int nb)
{
	t_list	*curr;

	curr = tail_a->next;
	while (curr != tail_a && nb > curr->nb)
		curr = curr->next;
	if (curr == tail_a)
	{
		if (tail_a->nb > nb)
			return (tail_a);
		else
			return (ft_smallest_nb(tail_a));
	}
	else
		return (ft_smallest_higher(tail_a, curr, nb));
}

t_list	*ft_smallest_higher(t_list *tail_a, t_list *curr, int nb)
{
	t_list	*smallest_higher;

	smallest_higher = curr;
	while (curr != tail_a)
	{
		if (curr->nb > nb && curr->nb < smallest_higher->nb)
			smallest_higher = curr;
		curr = curr->next;
	}
	if (tail_a->nb > nb && tail_a->nb < smallest_higher->nb)
			smallest_higher = tail_a;
	return (smallest_higher);
}

t_list	*ft_smallest_nb(t_list *tail_a)
{
	t_list	*curr;
	t_list	*smallest;
	
	curr = tail_a->next;
	smallest = tail_a;
	while (curr != tail_a)
	{
		if (curr->nb < smallest->nb)
			smallest = curr;
		curr = curr->next;	
	}
	return (smallest);
}

int		ft_calculate_cost(int index_a, int index_b, t_list *tail_a, t_list *tail_b)
{
	int		cost;
	int		lstsize_a;
	int		lstsize_b;
	
	lstsize_a = ft_lstsize(tail_a);
	lstsize_b = ft_lstsize(tail_b);
	cost = 0;
	if (index_a < lstsize_a / 2 + 1)
		cost += index_a;
	if (index_b < lstsize_b / 2 + 1)
		cost += index_b;
	if (index_a >= lstsize_a / 2 + 1)
		cost += (lstsize_a) - index_a;
	if (index_b >= lstsize_b / 2 + 1)
		cost += (lstsize_b) - index_b;
	return (cost);
}