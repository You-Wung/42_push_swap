/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:30:52 by tyou              #+#    #+#             */
/*   Updated: 2021/06/05 16:39:28 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			order_check(t_stack *a, t_stack *b)
{
	if (b->head && a->head->n > b->head->n &&
				b->head->n > a->end->n)
		pa_pb(b, a, 2);
}

static int			check_order(t_stack *a, t_stack *b)
{
	t_lstnum	*tmp;
	int			rt;

	rt = 0;
	tmp = a->head;
	while (tmp)
	{
		if (tmp->n > b->head->n)
			break ;
		tmp = tmp->next;
		rt++;
	}
	return (rt);
}

static void			logic_five(t_stack *a, t_stack *b, int cnt, int amount)
{
	int		i;

	i = check_order(a, b);
	if (count_mem(a) == i)
		i = 0;
	i++;
	if (cnt > amount / 2)
	{
		i -= amount / 2;
		while (--i > 0)
			rra_rrb_rrr(a, 0, 1);
	}
	else
	{
		while (--i > 0)
			ra_rb_rr(a, 0, 1);
	}
}

static void			find_position(t_stack *a, t_stack *b, int amount)
{
	t_lstnum	*tmp;
	int			i;
	int			cnt;

	cnt = 0;
	tmp = a->head;
	if (!b->head)
		return ;
	i = b->head->n;
	while (tmp && i > tmp->n && ++cnt)
		tmp = tmp->next;
	tmp = a->head;
	logic_five(a, b, cnt, amount);
	pa_pb(b, a, 2);
	order_check(a, b);
	while (sorted(a))
	{
		if (cnt > amount / 2)
			ra_rb_rr(a, 0, 1);
		else
			rra_rrb_rrr(a, 0, 1);
	}
}

void				five(t_stack *a, t_stack *b, int amount)
{
	int		i;

	i = -1;
	if (!sorted(a))
		return ;
	while (++i < amount - 3)
		pa_pb(a, b, 1);
	three(a);
	while (i > 0)
	{
		if (sorted(a) == 1)
			ft_error(7);
		find_position(a, b, count_mem(a));
		i--;
	}
}
