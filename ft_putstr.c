/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:55:02 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/01/29 15:01:36 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
