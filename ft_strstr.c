/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 22:12:01 by thill             #+#    #+#             */
/*   Updated: 2018/08/09 11:35:29 by thill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *w_str;
	const char *p_str;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		w_str = haystack;
		p_str = needle;
		while (*p_str && *w_str == *p_str)
		{
			w_str++;
			p_str++;
		}
		if (*p_str == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
