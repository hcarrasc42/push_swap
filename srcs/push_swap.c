/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:45:53 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/11/07 09:54:53 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(t_list *stack_a, t_list *stack_b, char **argv)
{
	int	size;

	stack_a = list_init(argv);
	if (check_sorted(&stack_a) == 1)
		ft_exit(stack_a, 0, 0);
	ft_index(&stack_a);
	size = listlen(stack_a);
	if (size == 3)
		sort_3(&stack_a);
	else if (size == 5)
		sort_5(&stack_a, &stack_b);
	else
		sort_unlimit(&stack_a, &stack_b, size);
	ft_exit(stack_a, stack_b, 0);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = 0;
	stack_b = 0;
	if (argc == 1)
		return (0);
	if (argc > 1)
		push_swap(stack_a, stack_b, argv + 1);
	return (0);
}

void	printlist(t_list *stack_a, t_list *stack_b)
{
	t_list	*aux;

	while (stack_a != 0)
	{
		printf("%d ", stack_a->number);
		aux = stack_a;
		stack_a = stack_a->next;
		free(aux);
	}
	printf("\n");
	while (stack_b != 0)
	{
		printf("%d ", stack_b->number);
		aux = stack_b;
		stack_b = stack_b->next;
		free(aux);
	}
	printf("\n");
	ft_exit(stack_a, stack_b, 0);
}
