/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:36:06 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/01/31 16:53:54 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	nb;

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
	if (nptr[i] && (nptr[i] < '0' || nptr[i] > '9'))
	{
		ft_puterror("Error: input must be a list of int");
		exit (1);
	}
	return (nb * neg);
}

void	ft_lstclear(t_list *lst)
{
	t_list	*temp_lst;

	if (!lst)
		return ;
	lst->prev->next = NULL;
	while (lst)
	{
		temp_lst = lst->next;
		free(lst);
		lst = temp_lst;
	}
	return ;
}