/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 21:29:19 by tyou              #+#    #+#             */
/*   Updated: 2021/06/05 16:32:37 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			count_num(t_stack *a)
{
	t_lstnum	*tmp;
	int			i;

	if (!a->head)
		return (0);
	tmp = a->head;
	i = 1;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void		algorithm(t_stack *a, t_stack *b, int amount)
{
	int	tmp;

	if (amount == 2 && a->head->n < a->end->n)
	{
		tmp = a->head->n;
		a->head->n = a->end->n;
		a->end->n = tmp;
	}
	if (amount <= 3)
		return (three(a));
	else if (amount <= 5)
		return (five(a, b, amount));
	else if (amount > 5)
	{
		if (!sorted(a))
			return ;
		a_to_b(a, b, count_mem(a));
		return ;
	}
}

int			main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;

	if (ac == 1)
		return (0);
	if (ac == 2 && ft_strchr(av[1], ' '))
	{
		av = ft_split(av[1], ' ');
		ac = ft_setac(av);
	}
	ft_memset(&a, 0, sizeof(t_stack));
	ft_memset(&b, 0, sizeof(t_stack));
	build_stack(&a, ac, av);
	algorithm(&a, &b, ac - 1);
	exit(0);
}
