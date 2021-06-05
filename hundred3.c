/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 22:54:36 by tyou              #+#    #+#             */
/*   Updated: 2021/06/05 13:42:25 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort213(t_stack *a, t_stack *b)
{
	if (b->head->n < b->head->next->n)
		sa_sb_ss(a, b, 3);
	else
		sa_sb_ss(a, 0, 1);
}

void	sort321(t_stack *a, t_stack *b)
{
	if (count_mem(a) == 3)
	{
		ra_rb_rr(a, 0, 1);
		if (b->head->n < b->head->next->n)
			sa_sb_ss(a, b, 3);
		else
			sa_sb_ss(a, 0, 1);
	}
	else
	{
		if (b->head->n < b->head->next->n)
			sa_sb_ss(a, b, 3);
		else
			sa_sb_ss(a, 0, 1);
		pa_pb(a, b, 1);
		sa_sb_ss(a, 0, 1);
		pa_pb(b, a, 2);
		if (b->head->n < b->head->next->n)
			sa_sb_ss(a, b, 3);
		else
			sa_sb_ss(a, 0, 1);
	}
}

void	sort312(t_stack *a, t_stack *b)
{
	if (count_mem(a) == 3)
		ra_rb_rr(a, 0, 1);
	else
	{
		if (b->head->n < b->head->next->n)
			sa_sb_ss(a, b, 3);
		else
			sa_sb_ss(a, 0, 1);
		pa_pb(a, b, 1);
		sa_sb_ss(a, 0, 1);
		pa_pb(b, a, 2);
	}
}

void	sort132(t_stack *a, t_stack *b)
{
	pa_pb(a, b, 1);
	sa_sb_ss(a, 0, 1);
	pa_pb(b, a, 2);
}

void	sort231(t_stack *a, t_stack *b)
{
	if (count_mem(a) == 3)
		rra_rrb_rrr(a, 0, 1);
	else
	{
		pa_pb(a, b, 1);
		sa_sb_ss(a, 0, 1);
		pa_pb(b, a, 2);
		if (b->head->n < b->head->next->n)
			sa_sb_ss(a, b, 3);
		else
			sa_sb_ss(a, 0, 1);
	}
}
