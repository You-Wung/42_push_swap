/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 23:58:52 by tyou              #+#    #+#             */
/*   Updated: 2021/06/05 14:40:32 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int			ft_isblank(char c)
{
	return (c == ' ' || c == '\t');
}

int			ft_char_num(char c)
{
	return (c >= '0' && c <= '9');
}

void		ft_error(int i)
{
	char c;

	c = i + '0';
	write(2, "Error\n", 7);
	exit(0);
}

int			count_mem(t_stack *a)
{
	t_lstnum	*tmp;
	int			rt;

	if (a == 0)
		return (0);
	rt = 0;
	tmp = a->head;
	while (tmp)
	{
		rt++;
		tmp = tmp->next;
	}
	return (rt);
}

int			sorted(t_stack *t)
{
	t_lstnum	*tmp;

	tmp = t->head;
	while (tmp)
	{
		if (!tmp->next)
			break ;
		if (tmp->n > tmp->next->n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
