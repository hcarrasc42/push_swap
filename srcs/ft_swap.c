/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:10:26 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/11/07 09:54:45 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **stack_a)
{
	t_list	*aux;

	if (*stack_a == 0 || (*stack_a)->next == 0)
		return ;
	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	aux->next = (*stack_a)->next;
	(*stack_a)->next = aux;
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	t_list	*aux;

	if (*stack_b == 0 || (*stack_b)->next == 0)
		return ;
	aux = *stack_b;
	*stack_b = (*stack_b)->next;
	aux->next = (*stack_b)->next;
	(*stack_b)->next = aux;
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sb(stack_a);
	sb(stack_b);
}
