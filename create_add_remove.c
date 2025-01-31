/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_add_remove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:34:44 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/01/31 15:12:06 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_new_node(int nb)
{
	t_list	*new_node;

	new_node = malloc(1 * sizeof (t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->nb = nb;
	new_node->prev = new_node;
	new_node->next = new_node;
	return (new_node);
}

void	ft_lstadd_bgn(t_list **tail, t_list *new_node)
{
	if (tail == NULL || new_node == NULL)
	{
		ft_puterror("Error: cannot add node at the beginning");
  	}
	if (*tail == NULL)
	{
		*tail = new_node;
		return ;
	}
	new_node->next = (*tail)->next;
	new_node->prev = *tail;
	(*tail)->next->prev = new_node;
	(*tail)->next = new_node;
	return ;
}

void	ft_lstadd_end(t_list **tail, t_list *new_node)
{
	if (tail == NULL || new_node == NULL)
	{
		ft_puterror("Error: cannot add node at the end");
		exit (1);
  	}
	if (*tail == NULL)
	{
		*tail = new_node;
		return ;
	}
	new_node->next = (*tail)->next;
	new_node->prev = *tail;
	(*tail)->next->prev = new_node;
	(*tail)->next = new_node;
	*tail = new_node;
	return ;
}

t_list	*ft_remove_end(t_list **tail)
{
	t_list	*temp;
	if (tail == NULL || *tail == NULL)
	{
		ft_puterror("Error: cannot remove node at the end");
		exit(1);
  	}
	if ((*tail)->next == *tail)
    {
        *tail = NULL;
        return (*tail);
    }
	(*tail)->prev->next = (*tail)->next;
	(*tail)->next->prev = (*tail)->prev;
	temp = *tail;
	*tail = (*tail)->prev;
	temp->next = temp;
	temp->prev = temp;
	return (temp);
}

t_list	*ft_remove_bgn(t_list **tail)
{
	t_list	*temp;
	if (tail == NULL || *tail == NULL)
	{
		ft_puterror("Error: cannot remove node at the beginning");
		exit(1);
  	}
	if ((*tail)->next == *tail)
    {
        *tail = NULL;
        return (*tail);
    }
	temp = (*tail)->next;
	(*tail)->next = (*tail)->next->next;
	(*tail)->next->prev = *tail;
	temp->next = temp;
	temp->prev = temp;
	return (temp);
}