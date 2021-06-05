/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:20:01 by tyou              #+#    #+#             */
/*   Updated: 2021/05/24 16:54:24 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		size_s(char *s, int c, int i)
{
	int rt;

	rt = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			break ;
		}
		rt++;
		i++;
	}
	return (rt + 1);
}

int		measure(char *s, int c)
{
	int i;
	int noc;
	int rt;

	i = 0;
	noc = 0;
	rt = 0;
	while (s[i])
	{
		if (s[i] == c)
			noc = 0;
		else if (!noc)
		{
			noc++;
			rt++;
		}
		i++;
	}
	return (rt + 1);
}

char	**fre(char **rt, int j)
{
	while (j >= 0)
	{
		free(rt[j]);
		j--;
	}
	free(rt);
	return (NULL);
}

char	**in_put(char *s, char **rt, int c, int limit)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 1;
	while (s[i])
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (s[i] && j < limit)
		{
			if (!(rt[j] = (char *)malloc(sizeof(char) * size_s(s, c, i))))
				return (fre(rt, j));
			while (s[i] && s[i] != c)
				rt[j][k++] = s[i++];
			rt[j][k] = '\0';
			j++;
		}
		if (s[i] != '\0')
			i++;
	}
	rt[limit] = NULL;
	return (rt);
}

char	**ft_split(char const *s, char c)
{
	char	**rt;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (!(rt = (char **)malloc(sizeof(char *) * measure((char*)s, c))))
		return (NULL);
	rt[0] = malloc(1);
	return (in_put((char*)s, rt, c, measure((char*)s, c)));
}
