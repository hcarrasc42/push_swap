/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:10:45 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/11/07 09:54:59 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a)->index != 3 && (*stack_a)->index != 4)
		ra(stack_a);
	pb(stack_a, stack_b);
	while ((*stack_a)->index != 3 && (*stack_a)->index != 4)
		ra(stack_a);
	pb(stack_a, stack_b);
	if ((*stack_b)->index < ((*stack_b)->next)->index)
		sb(stack_b);
	if (check_sorted(stack_a) == 0)
		sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	ra(stack_a);
	ra(stack_a);
}
