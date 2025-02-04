/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:16:19 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/02/04 15:22:25 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_move(char *str, t_list **tail_a, t_list **tail_b)
{
	if (ft_strncmp(str, "sa", 3) == 0 || ft_strncmp(str, "ss", 3) == 0)
		ft_swap_nodes(tail_a);
	if (ft_strncmp(str, "sb", 3) == 0 || ft_strncmp(str, "ss", 3) == 0)
		ft_swap_nodes(tail_b);
	else if (ft_strncmp(str, "ra", 3) == 0 || ft_strncmp(str, "rr", 3) == 0)
		ft_rotate_up(tail_a);
	if (ft_strncmp(str, "rb", 3) == 0 || ft_strncmp(str, "rr", 3) == 0)
		ft_rotate_up(tail_b);
	else if (ft_strncmp(str, "rra", 4) == 0 || ft_strncmp(str, "rrr", 4) == 0)
		ft_rotate_down(tail_a);
	if (ft_strncmp(str, "rrb", 4) == 0 || ft_strncmp(str, "rrr", 4) == 0)
		ft_rotate_down(tail_b);
	else if (ft_strncmp(str, "pa", 3) == 0)
		ft_push(tail_a, tail_b);
	else if (ft_strncmp(str, "pb", 3) == 0)
		ft_push(tail_b, tail_a);
	ft_putstr(str);
	ft_putchar('\n');
	return (0);		
}

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

void	ft_sort_three(t_list **tail)
{
	if ((*tail)->next->nb > (*tail)->nb && (*tail)->next->nb > (*tail)->prev->nb)
		ft_move("ra", tail, NULL);
	else if ((*tail)->prev->nb > (*tail)->nb && (*tail)->prev->nb > (*tail)->next->nb)
		ft_move("rra", tail, NULL);
	if ((*tail)->next->nb > (*tail)->prev->nb)
		ft_move("sa", tail, NULL);	
}

void	ft_sort_two(t_list **tail)
{
	if ((*tail)->nb < (*tail)->next->nb)
		ft_move("sa", tail, NULL);
	return ;
}

int	main(int argc, char **argv)
{
	t_list	*tail_a;
	t_list	*tail_b;
	t_list	*temp_lst;
	
	if (argc <= 1 || (argc == 2 && ft_atoi(argv[1])))
	 	return 0;
	if (argc == 2 && ft_atoi(argv[1]) == 0)
	 	return 0;
	tail_a = ft_create_stack(argc, argv);
	if (ft_lstsize(tail_a) == 2 || ft_lstsize(tail_a) == 3)
	{
		if (ft_lstsize(tail_a) == 2)
			ft_sort_two(&tail_a);
		else if (ft_lstsize(tail_a) == 3)
			ft_sort_three(&tail_a);
		ft_lstclear(tail_a);
		return (0);	
	}
	tail_b = NULL;

	
 	//TESTS!!! delete print loop later
	temp_lst = tail_a->next;
	printf ("STACK A\n");
	while (temp_lst != tail_a) 
	{
		printf("%d\n", temp_lst->nb);
		temp_lst = temp_lst->next;
	}
	printf("%d\n", tail_a->nb);
	printf("%d\n\n", tail_a->next->nb);
	ft_move("pa", &tail_a, &tail_b);
	ft_move("pa", &tail_a, &tail_b);
	ft_move("pa", &tail_a, &tail_b);
	ft_move("pa", &tail_a, &tail_b);
	ft_move("ss", &tail_a, &tail_b);
	temp_lst = tail_a->next;
	printf ("STACK A\n");
	while (temp_lst != tail_a) 
	{
		printf("%d\n", temp_lst->nb);
		temp_lst = temp_lst->next;
	} 
	printf("%d\n", tail_a->nb);
	printf("%d\n\n", tail_a->next->nb);
	temp_lst = tail_b->next;
	printf ("STACK B\n");
	while (temp_lst != tail_b) 
	{
		printf("%d\n", temp_lst->nb);
		temp_lst = temp_lst->next;
	} 
	printf("%d\n", tail_b->nb);
	printf("%d\n\n", tail_b->next->nb);

	ft_lstclear(tail_a);
	return 0;
}