/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:16:19 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/01/30 15:18:11 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_create_stack(int argc, char **argv)
{
	int		i;
	int		nb;
	t_list	*new_node;
	t_list	*tail;
	
	i = 1;
	tail = NULL;
	while (i <= argc - 1)
	{
		nb = ft_atoi(argv[i]);
		new_node = ft_lstnew(nb);
		if (new_node == NULL)
		{
			ft_puterror("Error: allocation failed");
			ft_lstclear(tail);
			exit (1);
		}
 		if (tail != NULL)
		{
			new_node->next = tail->next;
			new_node->prev = tail;
			tail->next->prev = new_node;
			tail->next = new_node;
		} 
		tail = new_node;
		i++;
	} 
	return (tail);
}

int	main(int argc, char **argv)
{
	t_list	*tail;
	t_list	*temp_lst;
	
	if (argc <= 1 || (argc == 2 && ft_atoi(argv[1])))
	 	return 0;
	tail = ft_create_stack(argc, argv);
 	temp_lst = tail->next;

	
	while (temp_lst != tail) //delete later
	{
		printf("%d\n", temp_lst->nb);
		temp_lst = temp_lst->next;
	}
	printf("%d\n", tail->nb); 
	ft_lstclear(tail);
	return 0;
}