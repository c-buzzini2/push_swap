/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:33:53 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/01/30 15:03:10 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


typedef struct s_list
{
	struct s_list	*prev;
	int				nb;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *nptr);
int		ft_putchar(unsigned int c);
int		ft_puterror(char *str);
int		ft_putstr(char *str);
size_t	ft_strlen(const char *s);
t_list	*ft_lstnew(int nb);
void	ft_lstclear(t_list *lst);
t_list	*ft_create_stack(int argc, char **argv);





#endif
