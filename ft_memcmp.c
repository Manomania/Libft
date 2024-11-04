/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:51:48 by maximart          #+#    #+#             */
/*   Updated: 2024/11/04 13:43:35 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char *c1;
	char *c2;

	if (n == 0)
		return (0);
	c1 = (char *)s1;
	c2 = (char *)s2;
	while (n)
	{
		if (*c1 != *c2)
			return ((unsigned char *)c1 - (unsigned char*)c2);
		c1++;
		c2++;
		n--;
	}
	return (0);
}