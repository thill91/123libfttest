/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:10:43 by adorn             #+#    #+#             */
/*   Updated: 2018/08/09 21:57:21 by thill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		wd_count(const char *s, char d)
{
	int			index;
	int			n;

	index = 0;
	n = 0;
	while (*s)
	{
		if (*s != d && index == 0)
		{
			index = 1;
			n++;
		}
		if (*s == d && index == 1)
			index = 0;
		s++;
	}
	return (n);
}

static int		wd_len(const char *s, char d)
{
	int	len;

	len = 0;
	while (*s && *s != d)
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**t;
	int			wd;
	int			i;

	i = 0;
	if (!s)
		return (0);
	wd = wd_count(s, c);
	t = (char**)malloc(sizeof(*t) * (wd_count(s, c) + 1));
	if (t == NULL)
		return (NULL);
	while (wd > 0)
	{
		while (*s == c && *s)
			s++;
		t[i] = ft_strsub(s, 0, wd_len(s, c));
		if (t[i] == NULL)
			return (NULL);
		s = s + wd_len(s, c);
		i++;
		wd--;
	}
	t[i] = NULL;
	return (t);
}
