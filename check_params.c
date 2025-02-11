/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:26:55 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/02/11 14:47:52 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr, t_list *tail_a)
{
	int		i;
	int		neg;
	long	nb;

	i = 0;
	nb = 0;
	neg = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] && (nptr[i] < '0' || nptr[i] > '9'
		|| nb * neg > INT_MAX || nb * neg < INT_MIN))
	{
		ft_puterror("Error: input must be an int within INT_MAX and INT_MIN");//DELETE
		ft_error_free_exit(tail_a, NULL);
	}
	return ((int)nb * neg);
}

int	ft_digits_and_spaces(char *str)
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

int	ft_needs_split(char *str)
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

void	ft_initial_check(int argc, char **argv)
{
	if (argc <= 1)
		exit (0);
	if (argc == 2 && ft_digits_and_spaces(argv[1]) == 0)
	{
		ft_puterror("Error: parameters must be ints");//KEEP JUST ERROR NEWLINE
		exit (1);
	}
	if (argc == 2 && ft_needs_split(argv[1]) == 0)
	{
		ft_atoi(argv[1], NULL);
		exit (0);
	}
}