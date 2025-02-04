/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:34:44 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/02/04 14:21:54 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_nodes(t_list **tail)
{
	t_list	*second;
	t_list	*head;
	
	if (tail == NULL || *tail == NULL || (*tail)->next == *tail)
	{
		ft_puterror("Error: cannot swap nodes");
		//ft_clear_and_exit
		exit (1);
  	}
	head = (*tail)->next;
	second = head->next;
	if (second == *tail)
	{
		*tail = head;
		return;
	}
	(*tail)->next = second;
	second->next->prev = head;
	head->prev = second;
	head->next = second->next;
	second->prev = *tail;
	second->next = head;
}

void	ft_push(t_list **tail_from, t_list **tail_to)
{
	t_list	*moving;
	
	if (tail_to == NULL || tail_from == NULL)
	{
		ft_puterror("Error: stack missing");
		exit(1);
  	}
	moving = ft_remove_bgn(tail_from);
	ft_lstadd_bgn(tail_to, moving);
}

void	ft_rotate_up(t_list **tail)
{
	if (tail == NULL || *tail == NULL || (*tail)->next == *tail)
	{
		ft_puterror("Error: cannot rotate nodes");
		exit(1);
  	}
	*tail = (*tail)->next;
}

void	ft_rotate_down(t_list **tail)
{
	if (tail == NULL || *tail == NULL || (*tail)->next == *tail)
	{
		ft_puterror("Error: cannot rotate nodes");
		exit(1);
  	}
	*tail = (*tail)->prev;
}