/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:33:53 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/02/09 13:12:12 by cbuzzini         ###   ########.fr       */
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
	int				index;
	struct s_list	*dest;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *nptr);
int		ft_putchar(unsigned int c);
int		ft_puterror(char *str);
int		ft_putstr(char *str);
size_t	ft_strlen(const char *s);
t_list	*ft_new_node(int nb);
void	ft_lstclear(t_list *lst);
t_list	*ft_create_stack(int argc, char **argv);
void	ft_lstadd_end(t_list **tail, t_list *new_node);
void	ft_lstadd_bgn(t_list **tail, t_list *new_node);
t_list	*ft_remove_end(t_list **tail);
t_list	*ft_remove_bgn(t_list **tail);
void	ft_swap_nodes(t_list **tail);
void	ft_rotate_up(t_list **tail);
void	ft_rotate_down(t_list **tail);
void	ft_push(t_list **tail_from, t_list **tail_to);
int		ft_move(char *str, t_list **tail_a, t_list **tail_b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_sort_three(t_list **tail);
void	ft_sort_two(t_list **tail);
int		ft_lstsize(t_list *lst);
void	ft_error_free_exit(t_list *lstclear_a, t_list *lst_b);
void	ft_check_repetition(t_list **tail, int nb);
void	ft_prepare_stack(t_list **tail_a, t_list **tail_b);
void	ft_set_indices(t_list *tail_a, t_list *tail_b);
t_list	*ft_choose_cheapest(t_list *tail_a, t_list *tail_b);
t_list	*ft_find_destination(t_list *tail_a, int nb);
t_list	*ft_smallest_nb(t_list *tail_a);
t_list	*ft_smallest_higher(t_list *tail_a, t_list *curr, int nb);
int		ft_calculate_cost(int index_a, int index_b, t_list *tail_a, t_list *tail_b);
void 	ft_push_cheapest(t_list **tail_a, t_list **tail_b);
void 	ft_put_on_top(t_list **node);


#endif
