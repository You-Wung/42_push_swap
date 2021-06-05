/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 02:34:01 by tyou              #+#    #+#             */
/*   Updated: 2021/06/05 15:41:22 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		b_return(t_stack *a, t_stack *b, int size)
{
	int		i;

	if (count_mem(b) <= 3)
	{
		if (count_mem(b) == 2 && b->head->n < b->head->next->n)
			sa_sb_ss(b, 0, 2);
		else if (count_mem(b) == 3)
			small_sort_b(b);
		while (--size > -1)
			pa_pb(b, a, 2);
	}
	else
	{
		i = size;
		while (--size > -1)
			pa_pb(b, a, 2);
		small_sort(a, b, i);
	}
}

void		size_two(t_stack *a, t_stack *b)
{
	if (a->head->n > a->head->next->n)
	{
		if (b->head->n < b->head->next->n)
			sa_sb_ss(a, b, 3);
		else
			sa_sb_ss(a, 0, 1);
	}
}

void		small_sort(t_stack *a, t_stack *b, int size)
{
	int		n1;
	int		n2;
	int		n3;

	if (size == 1)
		return ;
	if (size == 2)
	{
		size_two(a, b);
		return ;
	}
	n1 = a->head->n;
	n2 = a->head->next->n;
	n3 = a->head->next->next->n;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		sort213(a, b);
	else if (n1 > n2 && n2 > n3 && n1 > n3)
		sort321(a, b);
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		sort312(a, b);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
		sort132(a, b);
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		sort231(a, b);
}

void		small_sort_b(t_stack *b)
{
	int		n1;
	int		n2;
	int		n3;

	n1 = b->head->n;
	n2 = b->head->next->n;
	n3 = b->head->next->next->n;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		rra_rrb_rrr(b, 0, 2);
	else if (n1 < n2 && n2 < n3 && n1 < n3)
	{
		sa_sb_ss(b, 0, 2);
		rra_rrb_rrr(b, 0, 2);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
	{
		ra_rb_rr(b, 0, 2);
		sa_sb_ss(b, 0, 2);
		rra_rrb_rrr(b, 0, 2);
	}
	else if (n1 < n2 && n2 > n3 && n1 < n3)
		ra_rb_rr(b, 0, 2);
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		sa_sb_ss(b, 0, 2);
}
