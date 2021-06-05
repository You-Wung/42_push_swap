/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:03:16 by tyou              #+#    #+#             */
/*   Updated: 2021/06/05 15:40:29 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_to_b2(t_stack *a, t_stack *b, t_inta *ct)
{
	ct->s_ra = ct->ra;
	ct->s_pb = ct->pb;
	ct->s_rb = ct->rb;
	if (ct->ra == count_mem(a))
		ct->ra = 0;
	if (ct->rb == count_mem(b))
		ct->rb = 0;
	while (ct->rb > 0 || ct->ra > 0)
	{
		if (ct->rb && ct->ra < 1)
			rra_rrb_rrr(b, 0, 2);
		else if (ct->ra && ct->rb < 1)
			rra_rrb_rrr(a, 0, 1);
		else
			rra_rrb_rrr(a, b, 3);
		ct->rb--;
		ct->ra--;
	}
	a_to_b(a, b, ct->s_ra);
	b_to_a(a, b, ct->s_rb);
	b_to_a(a, b, ct->s_pb - ct->s_rb);
}

void		a_to_b(t_stack *a, t_stack *b, int size)
{
	int			pivet[3];
	t_inta		ct;

	ft_memset(&ct, 0, sizeof(t_inta));
	if (size <= 3)
	{
		small_sort(a, b, size);
		return ;
	}
	find_pivet(a, &pivet[0], size);
	while (size--)
	{
		if (a->head->n >= pivet[1] && ++ct.ra)
			ra_rb_rr(a, 0, 1);
		else
		{
			pa_pb(a, b, 1);
			++ct.pb;
			if (b->head->n >= pivet[0] && ++ct.rb)
				ra_rb_rr(b, 0, 2);
		}
	}
	a_to_b2(a, b, &ct);
}

static void	b_to_a2(t_stack *a, t_stack *b, t_intb *ct)
{
	ct->s_ra = ct->ra;
	ct->s_pa = ct->pa;
	ct->s_rb = ct->rb;
	if (ct->ra == count_mem(a))
		ct->ra = 0;
	if (ct->rb == count_mem(b))
		ct->rb = 0;
	a_to_b(a, b, ct->s_pa - ct->s_ra);
	while (ct->rb > 0 || ct->ra > 0)
	{
		if (ct->rb && ct->ra < 1)
			rra_rrb_rrr(b, 0, 2);
		else if (ct->ra && ct->rb < 1)
			rra_rrb_rrr(a, 0, 1);
		else
			rra_rrb_rrr(a, b, 3);
		ct->rb--;
		ct->ra--;
	}
	a_to_b(a, b, ct->s_ra);
	b_to_a(a, b, ct->s_rb);
}

void		b_to_a(t_stack *a, t_stack *b, int size)
{
	int			pivet[3];
	t_intb		ct;

	ft_memset(&ct, 0, sizeof(t_intb));
	if (size <= 3)
	{
		b_return(a, b, size);
		return ;
	}
	find_pivet(b, &pivet[0], size);
	while (size--)
	{
		if (b->head->n < pivet[0] && ++ct.rb)
			ra_rb_rr(b, 0, 2);
		else
		{
			pa_pb(b, a, 2);
			++ct.pa;
			if (a->head->n < pivet[1] && ++ct.ra)
				ra_rb_rr(a, 0, 1);
		}
	}
	b_to_a2(a, b, &ct);
}
