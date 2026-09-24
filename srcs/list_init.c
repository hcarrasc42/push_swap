/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:10:15 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/11/07 09:54:48 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*list_init(char *argv[])
{
	t_list		*stack_a;
	int			invalid;
	int			i;

	stack_a = ft_calloc(1, sizeof(t_list));
	if (stack_a == 0)
		exit(2);
	i = 0;
	invalid = 0;
	while (argv[i])
	{
		invalid = createlist(argv[i], &stack_a, i);
		if (invalid == 1)
			ft_exit(stack_a, 0, 2);
		i++;
	}
	return (stack_a);
}

int	createlist(char *argv, t_list **stack_a, int i)
{
	int		invalid;
	char	**str;
	int		j;

	invalid = 0;
	j = 0;
	str = ft_split(argv, ' ');
	while (str[j])
	{
		if (invalid == 0)
			invalid = check_alpha(str[j]);
		if (invalid == 0)
			invalid = add_list(*stack_a, str[j], i + j);
		free(str[j]);
		j++;
	}
	free(str);
	return (invalid);
}

int	check_alpha(char *str)
{
	int		invalid;
	int		i;
	char	c;

	i = 0;
	invalid = 0;
	if (str[0] == '-' && str[1])
		i++;
	while (str[i] && invalid == 0)
	{
		c = str[i];
		if (c < '0' || c > '9')
			invalid = 1;
		i++;
	}
	return (invalid);
}

int	add_list(t_list *stack_a, char *str, int index)
{
	long int		num;
	t_list			*new;

	num = ft_atoi(str);
	if (num < -2147483648 || num > 2147483647)
		return (1);
	if (stack_a->number == num && index != 0)
		return (1);
	new = ft_calloc(1, sizeof(t_list));
	if (!new)
		return (1);
	new->number = num;
	new->index = -1;
	new->next = 0;
	if (check_repeat(&stack_a, new, num) == 1)
		return (1);
	if (index == 0)
	{
		stack_a->number = new->number;
		stack_a->index = new->index;
		free(new);
	}
	else
		stack_a->next = new;
	return (0);
}

int	check_repeat(t_list **stack_a, t_list *new, int num)
{
	while ((*stack_a)->next != 0)
	{
		if ((*stack_a)->number == num || ((*stack_a)->next)->number == num)
		{
			free(new);
			return (1);
		}
		*stack_a = (*stack_a)->next;
	}
	return (0);
}
