/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 13:18:53 by tyou              #+#    #+#             */
/*   Updated: 2021/05/22 00:52:35 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			is_space(char str)
{
	if (str == '\t' || str == '\n' || str == '\v' || str == '\f'
					|| str == '\r' || str == ' ')
		return (1);
	else
		return (0);
}

long long	ft_atoi(const char *str)
{
	int			i;
	long long	rt;
	int			sign;

	sign = 1;
	i = 0;
	rt = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		rt = (rt * 10) + (str[i] - 48);
		i++;
	}
	return (sign * rt);
}
