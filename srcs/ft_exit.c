/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:11:30 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/11/07 09:54:22 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_exit(t_list *stack_a, t_list *stack_b, int type)
{
	t_list	*aux;

	while (stack_a != 0)
	{
		aux = stack_a;
		stack_a = stack_a->next;
		free(aux);
	}
	while (stack_b != 0)
	{
		aux = stack_b;
		stack_b = stack_a->next;
		free(aux);
	}
	if (type == 2)
		write(2, "Error\n", 6);
	exit(type);
}
