/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:16:19 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/01/31 17:05:09 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//START HERE NEXT TIME: Check what "at the same time" means - will I need forks?
//Do I need a separate parsing function that calls the movements and prints them? Remember multiple movements as well
//Should I save them into a file and then GNL?

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
		new_node = ft_new_node(nb);
		if (new_node == NULL)
		{
			ft_puterror("Error: allocation failed");
			ft_lstclear(tail);
			exit (1);
		}
 		if (tail != NULL)
			ft_lstadd_end(&tail, new_node);
		else
			tail = new_node;
		i++;
	} 
	return (tail);
}

int	main(int argc, char **argv)
{
	t_list	*tail_a;
	t_list	*tail_b;
	t_list	*temp_lst;
	
	if (argc <= 1 || (argc == 2 && ft_atoi(argv[1])))
	 	return 0;
	tail_a = ft_create_stack(argc, argv);
	tail_b = NULL;

	
 	//TESTS!!! delete print loop later
	temp_lst = tail_a->next;
	while (temp_lst != tail_a) 
	{
		printf("%d\n", temp_lst->nb);
		temp_lst = temp_lst->next;
	}
	printf("%d\n", tail_a->nb);
	printf("%d\n\n", tail_a->next->nb);
	ft_push(&tail_a, &tail_b);
	temp_lst = tail_a->next;
	while (temp_lst != tail_a) 
	{
		printf("%d\n", temp_lst->nb);
		temp_lst = temp_lst->next;
	} 
	printf("%d\n", tail_a->nb);
	printf("%d\n\n", tail_a->next->nb);
	printf("%d\n", tail_b->nb);
	printf("%d\n", tail_b->next->nb);
	printf("%d\n\n", tail_b->prev->nb);

	ft_lstclear(tail_a);
	return 0;
}