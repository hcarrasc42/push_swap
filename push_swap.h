/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:46:03 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/11/07 09:46:06 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int				number;
	int				index;
	struct s_list	*next;
}	t_list;

void		push_swap(t_list *stack_a, t_list *stack_b, char **argv);
void		ft_index(t_list **stack_a);
int			listlen(t_list *stack_a);
int			check_sorted(t_list **stack_a);

// sorts
void		sort_3(t_list **stack_a);
void		sort_5(t_list **stack_a, t_list **stack_b);
void		sort_unlimit(t_list **stack_a, t_list **stack_b, int size);

void		printlist(t_list *stack_a, t_list *stack_b);
void		ft_exit(t_list *stack_a, t_list *stack_b, int type);

// list_init
t_list		*list_init(char *argv[]);
int			createlist(char *argv, t_list **stack_a, int i);
int			check_alpha(char *str);
int			add_list(t_list *stack_a, char *str, int index);
int			check_repeat(t_list **stack_a, t_list *new, int num);

// swap
void		sa(t_list **stack_a);
void		sb(t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);

// push
void		pb(t_list **stack_a, t_list **stack_b);
void		pa(t_list **stack_a, t_list **stack_b);

// rotate
void		ra(t_list **stack_a);
void		rb(t_list **stack_b);
void		rr(t_list **stack_a, t_list **stack_b);

// reverse rotate
void		rra(t_list **stack_a);
void		rrb(t_list **stack_b);
void		rrr(t_list **stack_a, t_list **stack_b);

// Libft

size_t		ft_strlen(const char *s);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_calloc(size_t count, size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);

char		**ft_split(char const *s, char c);
char		*ft_split_check_chars(char const *s, char c, int row);
int			ft_split_check_rows(char const *s, char c);

long int	ft_atoi(const char *str);
int			ft_isdigit(int c);

#endif
