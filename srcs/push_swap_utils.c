/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:10:07 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/11/07 09:54:51 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sorted(t_list **stack_a)
{
	t_list	*aux;

	aux = *stack_a;
	while (aux->next != 0)
	{
		if (aux->number > (aux->next)->number)
			return (0);
		aux = aux->next;
	}
	return (1);
}

int	listlen(t_list *stack_a)
{
	int	i;

	i = 0;
	while (stack_a != 0)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

void	ft_index(t_list **stack_a)
{
	t_list	*begin;
	int		min;
	int		size;
	int		index;

	begin = *stack_a;
	size = listlen(*stack_a);
	min = (*stack_a)->number;
	index = 0;
	while (index < size)
	{
		while (*stack_a != 0)
		{
			if ((*stack_a)->index == -1 && (*stack_a)->number < min)
				min = (*stack_a)->number;
			*stack_a = (*stack_a)->next;
		}
		*stack_a = begin;
		while ((*stack_a)->number != min)
			*stack_a = (*stack_a)->next;
		(*stack_a)->index = index;
		*stack_a = begin;
		min = 2147483647;
		index++;
	}
}
