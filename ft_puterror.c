/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:55:02 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/01/29 14:54:06 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_puterror(char *str)
{
	int	returned;

	if (!str)
	{
		returned = write(2, "Error: puterror has no string to print\n", 39);
		if (returned == -1)
			return (-1);
	}
	else
	{
		returned = write(2, str, ft_strlen(str));
		returned += write(2, "\n", 1);

		if (returned == -1)
			return (-1);
	}
	return (returned);
}
