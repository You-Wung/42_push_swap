/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 00:52:43 by tyou              #+#    #+#             */
/*   Updated: 2021/05/31 00:57:08 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		double_check(t_stack *a)
{
	t_lstnum	*tmp1;
	t_lstnum	*tmp2;
	int			num;

	tmp1 = a->head;
	while (tmp1)
	{
		num = tmp1->n;
		tmp2 = tmp1;
		while (tmp2->next)
		{
			if (num == tmp2->next->n)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

static void		lst_addend(t_lstnum **origin, t_lstnum *new_num)
{
	t_lstnum *tmp;

	tmp = *origin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_num;
	tmp = tmp->next;
	tmp->prev = *origin;
	*origin = tmp;
}

static void		ft_first_str(t_stack *a, char *s)
{
	int		i;

	i = 0;
	if (*s != '-' && *s != '+' && !ft_char_num(*s))
		ft_error(1);
	if (*s == '-' || *s == '+')
		i++;
	while (ft_char_num(s[i]))
		i++;
	if (s[i] != '\0')
		ft_error(2);
	if (ft_atoi(s) > INT_MAX || ft_atoi(s) < INT_MIN)
		ft_error(9);
	a->head->n = (int)ft_atoi(s);
	a->end = a->head;
}

static void		ft_put_str(t_stack *a, char *s)
{
	t_lstnum	*new_num;
	int			i;

	i = 0;
	new_num = malloc(sizeof(t_lstnum));
	ft_memset(new_num, 0, sizeof(t_lstnum));
	if (*s != '-' && *s != '+' && !ft_char_num(*s))
		ft_error(3);
	if (*s == '-' || *s == '+')
		i++;
	while (ft_char_num(s[i]))
		i++;
	if (s[i] != '\0')
		ft_error(4);
	if (ft_atoi(s) > INT_MAX || ft_atoi(s) < INT_MIN)
		ft_error(9);
	new_num->n = (int)ft_atoi(s);
	lst_addend(&a->end, new_num);
}

void			build_stack(t_stack *a, int ac, char **av)
{
	int		i;

	if (ac == 1)
		ft_error(6);
	a->head = malloc(sizeof(t_lstnum));
	ft_memset(a->head, 0, sizeof(t_lstnum));
	ft_first_str(a, av[1]);
	i = 2;
	while (i < ac)
		ft_put_str(a, av[i++]);
	if (!double_check(a))
		ft_error(5);
}
