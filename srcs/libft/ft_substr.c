/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:12:25 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/11/07 09:12:30 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		index;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len <= 0)
	{
		str = (char *)malloc(1);
		str[0] = '\0';
		return (str);
	}
	index = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc((len + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	while (s[start] && index < len)
	{
		str[index] = s[start];
		index++;
		start++;
	}
	str[index] = '\0';
	return (str);
}
