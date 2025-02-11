/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:08:55 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/02/10 15:02:40 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dest;
	int		i;

	len = ft_strlen(s);
	i = 0;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == 0)
		return (0);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_substr2(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*src_substr;
	char	*dest_substr;
	size_t	str_len;

	i = 0;
	str_len = ft_strlen(s);
	if (len > str_len + 1)
		len = str_len;
	if (start + len > str_len)
		len = str_len - start;
	dest_substr = (char *)malloc((len + 1) * sizeof(char));
	if (dest_substr == 0)
		return (NULL);
	src_substr = ((char *)s) + start;
	while (src_substr[i] != '\0' && i < len)
	{
		dest_substr[i] = src_substr[i];
		i++;
	}
	dest_substr[i] = '\0';
	return (dest_substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest_substr;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		dest_substr = (char *)malloc(1 * sizeof(char));
		if (dest_substr == NULL)
			return (NULL);
		dest_substr[0] = '\0';
		return (dest_substr);
	}
	else
		return (ft_substr2 (s, start, len));
}
