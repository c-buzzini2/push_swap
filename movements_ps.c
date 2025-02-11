/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:34:44 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/02/11 14:01:20 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_remove_bgn(t_list **tail)
{
	t_list	*temp;

	if (tail == NULL || *tail == NULL)
	{
		ft_puterror("Error: cannot remove node at the beginning\n");//DELETE
		return(NULL);
	}
	if ((*tail)->next == *tail)
	{
		temp = *tail;
		*tail = NULL;
		return (temp);
	}
	temp = (*tail)->next;
	(*tail)->next = (*tail)->next->next;
	(*tail)->next->prev = *tail;
	temp->next = temp;
	temp->prev = temp;
	return (temp);
}

int	ft_lstadd_bgn(t_list **tail, t_list *new_node)
{
	if (tail == NULL || new_node == NULL)
	{
		ft_puterror("Error: cannot add node at the beginning\n");//DELETE
		return (1);
	}
	if (*tail == NULL)
	{
		*tail = new_node;
		return (0);
	}
	new_node->next = (*tail)->next;
	new_node->prev = *tail;
	(*tail)->next->prev = new_node;
	(*tail)->next = new_node;
	return (0);
}

static int	ft_push(t_list **tail_from, t_list **tail_to)
{
	t_list	*moving;

	if (tail_to == NULL || tail_from == NULL)
	{
		ft_puterror("Error: stack missing");//DELETE
		return (1);
	}
	moving = ft_remove_bgn(tail_from);
	if (moving == NULL)
		ft_error_free_exit(*tail_from, *tail_to);
	if (ft_lstadd_bgn(tail_to, moving) == 1)
		ft_error_free_exit(*tail_from, *tail_to);
	return (0);
}

static int	ft_swap_nodes(t_list **tail)
{
	t_list	*second;
	t_list	*head;

	if (tail == NULL || *tail == NULL || (*tail)->next == *tail)
	{
		ft_puterror("Error: cannot swap nodes");//DELETE
		return (1);
	}
	head = (*tail)->next;
	second = head->next;
	if (second == *tail)
	{
		*tail = head;
		return (0);
	}
	(*tail)->next = second;
	second->next->prev = head;
	head->prev = second;
	head->next = second->next;
	second->prev = *tail;
	second->next = head;
	return (0);
}

int	ft_move_ps(char *str, t_list **tail_a, t_list **tail_b)
{
	if (ft_strncmp(str, "sa", 3) == 0 || ft_strncmp(str, "ss", 3) == 0)
	{
		if (ft_swap_nodes(tail_a) == 1)
			ft_error_free_exit(*tail_a, *tail_b);
	}
	if (ft_strncmp(str, "sb", 3) == 0 || ft_strncmp(str, "ss", 3) == 0)
	{
		if (ft_swap_nodes(tail_b) == 1)
			ft_error_free_exit(*tail_a, *tail_b);
	}
	else if (ft_strncmp(str, "pa", 3) == 0)
	{
		if (ft_push(tail_a, tail_b) == 1)
			ft_error_free_exit(*tail_a, *tail_b);
	}
	else if (ft_strncmp(str, "pb", 3) == 0)
	{
		if (ft_push(tail_b, tail_a) == 1)
			ft_error_free_exit(*tail_a, *tail_b);
	}
	ft_putstr(str);
	ft_putchar('\n');
	return (0);
}
