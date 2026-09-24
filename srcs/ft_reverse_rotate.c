/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:11:17 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/11/07 09:54:40 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*aux;

	if (*stack_a == 0 || (*stack_a)->next == 0)
		return ;
	aux = *stack_a;
	while (((*stack_a)->next)->next != 0)
			*stack_a = (*stack_a)->next;
	((*stack_a)->next)->next = aux;
	aux = (*stack_a)->next;
	(*stack_a)->next = 0;
	*stack_a = aux;
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	t_list	*aux;

	if (*stack_b == 0 || (*stack_b)->next == 0)
		return ;
	aux = *stack_b;
	while (((*stack_b)->next)->next != 0)
			*stack_b = (*stack_b)->next;
	((*stack_b)->next)->next = aux;
	aux = (*stack_b)->next;
	(*stack_b)->next = 0;
	*stack_b = aux;
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
