/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:26:55 by cbuzzini          #+#    #+#             */
/*   Updated: 2024/11/07 10:12:51 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*
int	main(int argc, char **argv)
{
//	(void)argc;
	if (argc < 2)
		return (0);
	printf ("%d", ft_isdigit ((unsigned char) argv[1][0]));
}
*/

/*
int     main(void)
{
	printf ("%d", ft_isalpha (' '));
}
*/
