/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:55:02 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/02/12 11:08:15 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putchar(unsigned int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	returned;

	if (!str)
	{
		returned = write(1, "(null)", 6);
		if (returned == -1)
			return (-1);
	}
	else
	{
		returned = write(1, str, ft_strlen(str));
		if (returned == -1)
			return (-1);
	}
	return (returned);
}

int	ft_puterror(char *str)
{
	int	returned;

	if (!str)
	{
		return (-1);
	}
	else
	{
		returned = write(2, str, ft_strlen(str));
		if (returned == -1)
			return (-1);
	}
	return (returned);
}
