/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:34:44 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/01/30 14:27:00 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int nb)
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

/* int	main()
{
	t_list	*tail;
	tail = ft_lstnew(13);
	printf("%d\n", tail->nb);
	printf("%d\n", tail->next->nb);
	printf("%d\n", tail->prev->nb);
	return 0;
} */