/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_unlimit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:10:37 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/11/07 09:55:02 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	getbits(int size)
{
	int	i;

	i = 0;
	size--;
	while (size > 0)
	{
		size = size / 2;
		i++;
	}
	return (i);
}

void	sort_unlimit(t_list **stack_a, t_list **stack_b, int size)
{
	int	num_bits;
	int	position;
	int	loop_size;

	num_bits = getbits(size);
	position = 0;
	while (position < num_bits)
	{
		loop_size = size;
		while (--loop_size >= 0)
		{
			if (((*stack_a)->index >> position) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		position++;
	}
}
