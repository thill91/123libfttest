/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:34:30 by thill             #+#    #+#             */
/*   Updated: 2018/08/09 16:12:01 by thill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**t;

	i = 0;
	k = 0;
	if (!s || !(t = (char **)malloc(sizeof(char *) * (ft_wcount(s, c) + 1))))
		return (NULL);
	while (i < ft_wcount(s, c))
	{
		if (!(t[i] = (char *)malloc(sizeof(char *) * (ft_wlen(&s[k], c) + 1))))
			return (NULL);
		j = 0;
		while (s[k] == c)
			k += 1;
		while (s[k] != c && s[k] != '\0')
			t[i][j++] = s[k++];
		t[i][j] = '\0';
		i += 1;
	}
	t[i] = NULL;
	return (t);
}
