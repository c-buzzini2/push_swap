/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:06:50 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/02/10 14:44:07 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_empty_null(char **arr, int n, int i)
{
	//DO I REALLY NEED THIS?
	if (n == 0)
	{
		arr = (char **)malloc(sizeof(char *));
		if (arr == NULL)
			return (NULL);
		arr[0] = NULL;
	}
	if (n == 1)
	{
		while (i >= 0)
		{
			free(arr[i]);
			i--;
		}
		free(arr);
		return (NULL);
	}
	return (arr);
}

static int	ft_count_substr(const char *s, char c)
{
	int		i;
	int		subs;

	i = 0;
	subs = 0;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		subs++;
		while (s[i] == c)
			i++;
	}
	return (subs);
}

static int	ft_substr_len(const char *s, char c)
{
	int		j;

	j = 0;
	while (s[j] != '\0' && s[j] != c)
		j++;
	return (j);
}

static char	**ft_split2(char const *s, char c, char **arr, int counter_subs)
{
	int		len_sub;
	int		i;
	int		j;

	arr = (char **)malloc((counter_subs + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	len_sub = 0;
	j = 0;
	while (s[j] && s[j] == c)
		j++;
	while (i < counter_subs)
	{
		len_sub = ft_substr_len (s + j, c);
		arr[i] = ft_substr (s, j, len_sub);
		if (arr[i] == NULL)
			return (ft_empty_null(arr, 1, i));
		i++;
		j = j + len_sub;
		while (s[j] && s[j] == c)
			j++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		counter_subs;
	char	**arr;

	arr = NULL;
	if (s == NULL)
		return (ft_empty_null(arr, 0, 0));
	if (s[0] == '\0')
		return (ft_empty_null(arr, 0, 0));
	if (c == 0)
	{
		arr = (char **)malloc(2 * sizeof(char *));
		if (arr == NULL)
			return (NULL);
		arr[0] = ft_strdup(s);
		if (arr[0] == NULL)
			return (ft_empty_null(arr, 1, 0));
		arr[1] = NULL;
		return (arr);
	}
	counter_subs = ft_count_substr (s, c);
	if (counter_subs == 0)
		return (ft_empty_null(arr, 0, 0));
	return (ft_split2(s, c, arr, counter_subs));
}
