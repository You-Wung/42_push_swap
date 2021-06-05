/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:29:20 by tyou              #+#    #+#             */
/*   Updated: 2021/05/31 20:32:55 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three(t_stack *a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = a->end->prev->prev->n;
	n2 = a->end->prev->n;
	n3 = a->end->n;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		sa_sb_ss(a, 0, 1);
	else if (n1 > n2 && n2 > n3 && n1 > n3)
	{
		sa_sb_ss(a, 0, 1);
		rra_rrb_rrr(a, 0, 1);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ra_rb_rr(a, 0, 1);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		sa_sb_ss(a, 0, 1);
		ra_rb_rr(a, 0, 1);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		rra_rrb_rrr(a, 0, 1);
}
