/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:26:55 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/02/12 11:43:31 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_digits_and_spaces(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while ((str[i] >= '0' && str[i] <= '9')
		|| str[i] == ' ' || str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

static int	ft_needs_split(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

static t_list	*ft_prepare_args2(int argc, char **argv)
{
	int		i;
	t_list	*tail_a;

	tail_a = NULL;
	i = 1;
	while (argv[i])
	{
		if (ft_digits_and_spaces(argv[i]) == 0)
		{
			ft_puterror("Error\n");
			exit (1);
		}
		i++;
	}
	tail_a = ft_create_stack(argc - 1, argv + 1);
	return (tail_a);
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
		tail_a = ft_prepare_args2(argc, argv);
	return (tail_a);
}

void	ft_initial_check(int argc, char **argv)
{
	if (argc <= 1)
		exit (0);
	if (argc == 2 && ft_digits_and_spaces(argv[1]) == 0)
	{
		ft_puterror("Error\n");
		exit (1);
	}
	if (argc == 2 && ft_needs_split(argv[1]) == 0)
	{
		ft_atoi(argv[1], NULL);
		exit (0);
	}
}
