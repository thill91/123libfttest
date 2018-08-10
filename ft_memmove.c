/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 21:25:00 by thill             #+#    #+#             */
/*   Updated: 2018/07/31 21:59:30 by thill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *str_d;
	char *str_s;

	str_d = (char *)dst;
	str_s = (char *)src;
	if (str_s < str_d)
	{
		str_d = str_d + len - 1;
		str_s = str_s + len - 1;
		while (len > 0)
		{
			*str_d-- = *str_s--;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*str_d++ = *str_s++;
			len--;
		}
	}
	return (dst);
}
