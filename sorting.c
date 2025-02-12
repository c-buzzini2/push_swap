/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:17:19 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/02/12 11:54:47 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_both_up(t_list **tail_a, t_list **tail_b,
				t_list *node_a, t_list *node_b)
{
	int		rotations_a;
	int		rotations_b;

	rotations_a = node_a->index;
	rotations_b = node_b->index;
	while (rotations_a > 0 && rotations_b > 0)
	{
		ft_move_rotate("rr", tail_a, tail_b);
		rotations_a--;
		rotations_b--;
	}
	while (rotations_a > 0)
	{
		ft_move_rotate("ra", tail_a, tail_b);
		rotations_a--;
	}
	while (rotations_b > 0)
	{
		ft_move_rotate("rb", tail_a, tail_b);
		rotations_b--;
	}
}

static void	ft_both_down(t_list **tail_a, t_list **tail_b,
				t_list *node_a, t_list *node_b)
{
	int		lstsize_a;
	int		lstsize_b;
	int		rotations_a;
	int		rotations_b;

	lstsize_a = ft_lstsize(*tail_a);
	lstsize_b = ft_lstsize(*tail_b);
	rotations_a = (lstsize_a) - node_a->index;
	rotations_b = (lstsize_b) - node_b->index;
	while (rotations_a > 0 && rotations_b > 0)
	{
		ft_move_rotate("rrr", tail_a, tail_b);
		rotations_a--;
		rotations_b--;
	}
	while (rotations_a > 0)
	{
		ft_move_rotate("rra", tail_a, tail_b);
		rotations_a--;
	}
	while (rotations_b > 0)
	{
		ft_move_rotate("rrb", tail_a, tail_b);
		rotations_b--;
	}
}

static void	ft_rev_rotate_one(t_list **tail, t_list *node, int lstsize, char c)
{
	int		rotations;

	rotations = (lstsize) - node->index;
	while (rotations > 0)
	{
		if (c == 'a')
			ft_move_rotate("rra", tail, NULL);
		if (c == 'b')
			ft_move_rotate("rrb", NULL, tail);
		rotations--;
	}
}

static void	ft_rotate_one(t_list **tail, t_list *node, int lstsize, char c)
{
	int		rotations;

	if (node->index < lstsize / 2 + 1)
	{
		rotations = node->index;
		while (rotations > 0)
		{
			if (c == 'a')
				ft_move_rotate("ra", tail, NULL);
			if (c == 'b')
				ft_move_rotate("rb", NULL, tail);
			rotations--;
		}
	}
	else if (node->index >= lstsize / 2 + 1)
		ft_rev_rotate_one(tail, node, lstsize, c);
}

void	ft_put_on_top(t_list **tail_a, t_list **tail_b,
			t_list *node_a, t_list *node_b)
{
	int		lstsize_a;
	int		lstsize_b;

	lstsize_a = ft_lstsize(*tail_a);
	lstsize_b = ft_lstsize(*tail_b);
	if (node_a->index < lstsize_a / 2 + 1 && node_b->index < lstsize_b / 2 + 1)
		ft_both_up(tail_a, tail_b, node_a, node_b);
	else if (node_a->index >= lstsize_a / 2 + 1
		&& node_b->index >= lstsize_b / 2 + 1)
		ft_both_down(tail_a, tail_b, node_a, node_b);
	else
	{
		ft_rotate_one(tail_a, node_a, lstsize_a, 'a');
		ft_rotate_one(tail_b, node_b, lstsize_b, 'b');
	}
}
