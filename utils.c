/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:36:06 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/02/04 15:04:11 by cbuzzini         ###   ########.fr       */
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
	if ((nptr[i] && (nptr[i] < '0' || nptr[i] > '9')) || !nptr[0])
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

void	ft_error_clear_exit(t_list *lst_a, t_list *lst_b)
{
	ft_puterror("Error");
	if (!lst_a && !lst_b)
		exit (2);
	if (lst_a)
		ft_lstclear(lst_a);
	if (lst_b)
		ft_lstclear(lst_b);
	exit (2) ;
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int	ft_lstsize(t_list *tail)
{
	t_list	*curr_lst;
	int		i;

	if (tail == NULL)
		return (0);
	i = 0;
	curr_lst = tail->next;
	while (curr_lst != tail)
	{
		curr_lst = curr_lst->next;
		i++;
	}
	if (curr_lst == tail)
		i++;
	return (i);
}