/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:31:44 by tyou              #+#    #+#             */
/*   Updated: 2021/06/03 00:08:22 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sa_sb_ss(t_stack *t, t_stack *tt, int sign)
{
	int			i;

	if (sign == 1)
		write(1, "sa\n", 3);
	else if (sign == 2)
		write(1, "sb\n", 3);
	else if (sign == 3)
		write(1, "ss\n", 3);
	if (tt)
	{
		i = tt->head->n;
		tt->head->n = tt->head->next->n;
		tt->head->next->n = i;
	}
	i = t->head->n;
	t->head->n = t->head->next->n;
	t->head->next->n = i;
}

static void	ra_print(int sign)
{
	if (sign == 1)
		write(1, "ra\n", 3);
	else if (sign == 2)
		write(1, "rb\n", 3);
	else if (sign == 3)
		write(1, "rr\n", 3);
}

void		ra_rb_rr(t_stack *t, t_stack *tt, int sign)
{
	t_lstnum	*tmp;
	int			i;

	ra_print(sign);
	if (tt)
	{
		i = tt->head->n;
		tmp = tt->head;
		while (tmp->next)
		{
			tmp->n = tmp->next->n;
			tmp = tmp->next;
		}
		tt->end->n = i;
	}
	i = t->head->n;
	tmp = t->head;
	while (tmp->next)
	{
		tmp->n = tmp->next->n;
		tmp = tmp->next;
	}
	t->end->n = i;
}

static void	rra_print(int sign)
{
	if (sign == 1)
		write(1, "rra\n", 4);
	else if (sign == 2)
		write(1, "rrb\n", 4);
	else if (sign == 3)
		write(1, "rrr\n", 4);
}

void		rra_rrb_rrr(t_stack *t, t_stack *tt, int sign)
{
	t_lstnum	*tmp;
	int			i;

	if (count_mem(t) == 0)
		return ;
	rra_print(sign);
	if (tt)
	{
		i = tt->end->n;
		tmp = tt->end;
		while (tmp->prev)
		{
			tmp->n = tmp->prev->n;
			tmp = tmp->prev;
		}
		tt->head->n = i;
	}
	i = t->end->n;
	tmp = t->end;
	while (tmp->prev)
	{
		tmp->n = tmp->prev->n;
		tmp = tmp->prev;
	}
	t->head->n = i;
}
