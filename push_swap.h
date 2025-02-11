/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:33:53 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/02/11 13:11:02 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	struct s_list	*prev;
	int				nb;
	int				index;
	struct s_list	*dest;
	struct s_list	*next;
}	t_list;


void	ft_initial_check(int argc, char **argv);
int		ft_digits_and_spaces(char *str);
int		ft_needs_split(char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
int		ft_atoi(const char *nptr);
int		ft_putchar(unsigned int c);
int		ft_puterror(char *str);
int		ft_putstr(char *str);
size_t	ft_strlen(const char *s);
t_list	*ft_prepare_args(int argc, char **argv);
void	ft_lstclear(t_list *lst);
void	ft_lstadd_bgn(t_list **tail, t_list *new_node);
t_list	*ft_remove_bgn(t_list **tail);
int		ft_move_ps(char *str, t_list **tail_a, t_list **tail_b);
int		ft_move_rotate(char *str, t_list **tail_a, t_list **tail_b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_sort_three(t_list **tail);
void	ft_sort_two(t_list **tail);
void	ft_small_stack(t_list **tail);
int		ft_lstsize(t_list *lst);
void	ft_error_free_exit(t_list *lstclear_a, t_list *lst_b);
void	ft_prepare_stack(t_list **tail_a, t_list **tail_b);
void	ft_set_indices(t_list *tail_a, t_list *tail_b);
t_list	*ft_choose_cheapest(t_list *tail_a, t_list *tail_b);
t_list	*ft_smallest_nb(t_list *tail_a);
void	ft_push_cheapest(t_list **tail_a, t_list **tail_b);
void	ft_put_on_top(t_list **tail_a, t_list **tail_b,
			t_list *node_a, t_list *node_b);


#endif
