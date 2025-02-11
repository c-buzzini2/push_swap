/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:34:44 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/02/11 13:33:35 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_new_node(int nb)
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

static int	ft_lstadd_end(t_list **tail, t_list *new_node)
{
	if (tail == NULL || new_node == NULL)
	{
		ft_puterror("Error: cannot add node at the end\n");//DELETE
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
	*tail = new_node;
	return (0);
}

static void	ft_check_repetition(t_list **tail, int nb)
{
	t_list	*curr;

	curr = (*tail)->next;
	while (curr != *tail)
	{
		if (curr->nb == nb)
		{
			printf("Repeated number");//DELETE
			ft_error_free_exit(*tail, NULL);
		}
		curr = curr->next;
	}
	if ((*tail)->nb == nb)
	{
		printf("Repeated number");//DELETE
		ft_error_free_exit(*tail, NULL);
	}
}

static t_list	*ft_create_stack(int argc, char **argv)
{
	int		i;
	int		nb;
	t_list	*new_node;
	t_list	*tail;

	i = 0;
	tail = NULL;
	while (i <= argc - 1)
	{
		nb = ft_atoi(argv[i], tail);
		if (tail != NULL)
			ft_check_repetition(&tail, nb);
		new_node = ft_new_node(nb);
		if (new_node == NULL)
			ft_error_free_exit(tail, NULL);
		if (ft_lstadd_end(&tail, new_node) == 1)
			return (NULL);
		i++;
	}
	return (tail);
}

t_list	*ft_prepare_args(int argc, char **argv)
{
	int		i;
	t_list	*tail_a;
	char	**args;
	
	tail_a = NULL;
	i = 0;
	if (argc == 2 && ft_needs_split(argv[1]) == 1)
	{
		args = ft_split(argv[1], ' ');
		while (args[i] != NULL)
			i++;
		tail_a = ft_create_stack(i, args);
		i = 0;
		while (args[i] != NULL)
			free(args[i++]);
		free(args);
	}
	else if (argc > 2)
	{
		i = 1;
		while (argv[i])
		{
			if (ft_digits_and_spaces(argv[i]) == 0)
			{
				ft_puterror("Error: parameters must be ints");//KEEP ERROR ONLY NEWLINE
				exit (1);
			}
			i++;
		}
		tail_a = ft_create_stack(argc - 1, argv + 1);
	}
	return (tail_a);
}