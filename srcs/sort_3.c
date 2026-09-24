/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:10:58 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/11/07 09:54:57 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_list **stack_a)
{
	if ((*stack_a)->number < ((*stack_a)->next)->number)
	{
		if ((*stack_a)->number < (((*stack_a)->next)->next)->number)
		{
			sa(stack_a);
			ra(stack_a);
		}
		else
			rra(stack_a);
	}
	else
	{
		if ((*stack_a)->number > (((*stack_a)->next)->next)->number)
		{
			if (((*stack_a)->next)->number > (((*stack_a)->next)->next)->number)
			{
				sa(stack_a);
				rra(stack_a);
			}
			else
				ra(stack_a);
		}
		else
			sa(stack_a);
	}
}
