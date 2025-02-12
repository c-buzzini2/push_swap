/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:17:19 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/02/12 11:48:36 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_cheapest(t_list **tail_a, t_list **tail_b)
{
	t_list	*cheapest;

	cheapest = ft_choose_cheapest(*tail_a, *tail_b);
	ft_put_on_top(tail_a, tail_b, cheapest->dest, cheapest);
	ft_move_ps("pa", tail_a, tail_b);
}
