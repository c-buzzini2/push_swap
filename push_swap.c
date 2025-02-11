/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:16:19 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/02/11 13:12:19 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_smallest_first(t_list **tail)
{
	t_list	*smallest;
	int		lstsize;

	lstsize = ft_lstsize(*tail);
	smallest = ft_smallest_nb(*tail);
	if (smallest->index < lstsize / 2 + 1)
	{
		while ((*tail)->next != smallest)
			ft_move_rotate("ra", tail, NULL);
	}
	else if (smallest->index >= lstsize / 2 + 1)
	{
		while ((*tail)->next != smallest)
			ft_move_rotate("rra", tail, NULL);
	}
}

int	main(int argc, char **argv)
{
	t_list	*tail_a;
	t_list	*tail_b;
	t_list	*temp_lst;
	int		lstsize_b;
	int		i;

	if (argc <= 2)
		ft_initial_check(argc, argv);
	tail_a = ft_prepare_args(argc, argv);
	if (tail_a == NULL)
		ft_error_free_exit(tail_a, NULL);
	if (ft_lstsize(tail_a) == 2 || ft_lstsize(tail_a) == 3)
		ft_small_stack(&tail_a);
	tail_b = NULL;
	ft_prepare_stack(&tail_a, &tail_b);
	lstsize_b = ft_lstsize(tail_b);
	while (lstsize_b > 0)
	{
		ft_push_cheapest(&tail_a, &tail_b);
		ft_set_indices(tail_a, tail_b);
		lstsize_b--;
	}
	ft_smallest_first(&tail_a);


 	//TESTS!!! delete print loop later
	
	temp_lst = tail_a->next;
	printf ("STACK A\n");
	while (temp_lst != tail_a) 
	{
		printf("%d\n", temp_lst->nb);
		temp_lst = temp_lst->next;
	} 
	printf("%d\n\n", tail_a->nb);


	ft_lstclear(tail_a);
	ft_lstclear(tail_b);

	return 0;
}