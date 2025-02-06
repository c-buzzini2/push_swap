/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:17:19 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/02/06 15:56:37 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//START: COST ISNT WORKING AT THE LAST INDEX OF B. iT SHOULD BE ONE, BUT IT TRIES TO GO UP
void ft_position_cheapest(t_list **tail_a, t_list **tail_b)
{
	t_list	*cheapest;
	int		lstsize_a;
	int		lstsize_b;
	
	lstsize_a = ft_lstsize(*tail_a);
	lstsize_b = ft_lstsize(*tail_b);
	cheapest = ft_choose_cheapest(*tail_a, *tail_b, lstsize_b);
}

t_list	*ft_choose_cheapest(t_list *tail_a, t_list *tail_b, int lstsize)
{
	int 	dest_index;
	t_list	*curr;
	int		cost;
	t_list	*cheapest;
	int		lowest_cost;

	lowest_cost = ft_lstsize(tail_a) + ft_lstsize(tail_b);
	curr = tail_b->next;
	while (lstsize > 0)
	{
		dest_index = ft_find_destination(tail_a, curr->nb);
		cost = ft_calculate_cost(dest_index, curr->index, tail_a, tail_b);
		printf("Nb: %d, dest-index: %d, cost: %d\n", curr->nb, dest_index, cost);
		if (cost < lowest_cost)
		{
			lowest_cost = cost;
			cheapest = curr;
		}
		lstsize--;
		curr = curr->next;
	}
	return(cheapest);
	//move to the top (will prob send the cheapest index 
	//and search the destination again in the next function)
	//TEST calculate cost and find cheapest
}

int		ft_find_destination(t_list *tail_a, int nb)
{
	t_list	*curr;

	curr = tail_a->next;
	while (curr != tail_a && nb > curr->nb)
		curr = curr->next;
	if (curr == tail_a)
	{
		if (tail_a->nb > nb)
			return (tail_a->index);
		else
			return (ft_smallest_nb(tail_a));
	}
	else
		return (ft_smallest_higher(tail_a, curr, nb));
}

int		ft_smallest_higher(t_list *tail_a, t_list *curr, int nb)
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
	return (smallest_higher->index);
}

int		ft_smallest_nb(t_list *tail_a)
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
	return (smallest->index);
}

int		ft_calculate_cost(int index_a, int index_b, t_list *tail_a, t_list *tail_b)
{
	int		cost;
	int		lstsize_a;
	int		lstsize_b;
	
	lstsize_a = ft_lstsize(tail_a);
	lstsize_b = ft_lstsize(tail_b);
	printf("index b: %d\n", index_b);
	cost = 0;
	if (index_a <= lstsize_a / 2 + 1)
		cost += index_a;
	if (index_b <= lstsize_b / 2 + 1)
		cost += index_b;
	if (index_a > lstsize_a / 2 + 1)
		cost += (lstsize_a) - index_a;
	if (index_b > lstsize_b / 2 + 1)
		cost += (lstsize_b) - index_b;
	return (cost);
}