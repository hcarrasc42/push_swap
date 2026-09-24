/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:11:41 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/11/07 09:15:39 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long int	ft_atoi(const char *str)
{
	int			negative;
	long int	number;
	int			i;

	negative = 0;
	number = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit((int)str[i]) == 1)
	{
		number = number * 10;
		number += str[i] - '0';
		i++;
	}
	if (negative == 1)
		number = -number;
	return (number);
}
