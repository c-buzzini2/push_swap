/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:34:44 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/02/11 12:50:44 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rotate_up(t_list **tail)
{
	if (tail == NULL || *tail == NULL || (*tail)->next == *tail)
	{
		ft_puterror("Error: cannot rotate nodes");
		return (1);
	}
	*tail = (*tail)->next;
	return (0);
}

static int	ft_rotate_down(t_list **tail)
{
	if (tail == NULL || *tail == NULL || (*tail)->next == *tail)
	{
		ft_puterror("Error: cannot rotate nodes");
		return (1);
	}
	*tail = (*tail)->prev;
	return (0);
}

int	ft_move_rotate(char *str, t_list **tail_a, t_list **tail_b)
{
	if (ft_strncmp(str, "ra", 3) == 0 || ft_strncmp(str, "rr", 3) == 0)
	{
		if (ft_rotate_up(tail_a) == 1)
			ft_error_free_exit(*tail_a, *tail_b);
	}
	if (ft_strncmp(str, "rb", 3) == 0 || ft_strncmp(str, "rr", 3) == 0)
	{
		if (ft_rotate_up(tail_b) == 1)
			ft_error_free_exit(*tail_a, *tail_b);
	}
	else if (ft_strncmp(str, "rra", 4) == 0 || ft_strncmp(str, "rrr", 4) == 0)
	{
		if (ft_rotate_down(tail_a) == 1)
			ft_error_free_exit(*tail_a, *tail_b);
	}
	if (ft_strncmp(str, "rrb", 4) == 0 || ft_strncmp(str, "rrr", 4) == 0)
	{
		if (ft_rotate_down(tail_b) == 1)
			ft_error_free_exit(*tail_a, *tail_b);
	}
	ft_putstr(str);
	ft_putchar('\n');
	return (0);
}