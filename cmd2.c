/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 23:54:32 by tyou              #+#    #+#             */
/*   Updated: 2021/06/05 13:39:53 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sub_pa(t_stack *t, t_stack *tt)
{
	t_lstnum *tmp;
	t_lstnum *tmp2;

	tmp = t->head;
	if (t->head->next != 0)
	{
		tmp2 = tt->head;
		t->head = t->head->next;
		tmp2->prev = tmp;
		t->head->prev = 0;
		tt->head = tmp;
		tt->head->next = tmp2;
		tt->head->prev = 0;
	}
	else
	{
		tmp2 = tt->head;
		t->head = t->head->next;
		tt->head = tmp;
		tmp2->prev = tmp;
		tt->head->next = tmp2;
		t->end = 0;
	}
}

void			pa_pb(t_stack *t, t_stack *tt, int sign)
{
	t_lstnum	*tmp;

	if (count_mem(t) == 0)
		return ;
	if (sign == 1)
		write(1, "pb\n", 3);
	else if (sign == 2)
		write(1, "pa\n", 3);
	tmp = t->head;
	if (!tt->head && !tt->end)
	{
		t->head = t->head->next;
		tmp->next = 0;
		tt->head = tmp;
		tt->end = tmp;
	}
	else
		sub_pa(t, tt);
}
