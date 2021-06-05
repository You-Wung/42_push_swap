/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:49:03 by tyou              #+#    #+#             */
/*   Updated: 2021/01/07 22:54:44 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*rt;
	unsigned int	size;

	i = 0;
	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (!(rt = malloc(len + 1)))
		return (NULL);
	if (size <= start)
	{
		rt[0] = 0;
		return (rt);
	}
	ft_strlcpy(rt, s + start, len + 1);
	return (rt);
}
