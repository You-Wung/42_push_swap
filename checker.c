/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:39:17 by tyou              #+#    #+#             */
/*   Updated: 2021/06/05 14:53:58 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			gnl3(t_stack *a, t_stack *b, char *line)
{
	int	i;

	i = 0;
	if (ft_strstr(line, "sb") && ++i)
	{
		if (count_mem(b) > 1)
			sa_sb_ss(b, 0, 0);
	}
	else if (ft_strstr(line, "ss") && ++i)
	{
		if (count_mem(a) > 1 && count_mem(b) == 0)
			sa_sb_ss(a, 0, 0);
		else if (count_mem(b) > 1 && count_mem(a) == 0)
			sa_sb_ss(b, 0, 0);
		else if (count_mem(b) > 1 && count_mem(a) > 1)
			sa_sb_ss(a, b, 0);
	}
	else if (ft_strstr(line, "rb") && ++i)
	{
		if (count_mem(b) > 1)
			ra_rb_rr(b, 0, 0);
	}
	return (i);
}

int			gnl2(t_stack *a, t_stack *b, char *line)
{
	int i;

	i = 0;
	if (ft_strstr(line, "rr") && ++i)
	{
		if (count_mem(a) > 1 && count_mem(b) == 0)
			ra_rb_rr(a, 0, 0);
		else if (count_mem(b) > 1 && count_mem(a) == 0)
			ra_rb_rr(a, 0, 0);
		else if (count_mem(b) > 1 && count_mem(a) > 1)
			ra_rb_rr(a, b, 0);
	}
	else if (ft_strstr(line, "pb") && ++i)
		pa_pb(a, b, 0);
	else if (ft_strstr(line, "pa") && ++i)
		pa_pb(b, a, 0);
	else if (ft_strstr(line, "sa") && ++i)
	{
		if (count_mem(a) > 1)
			sa_sb_ss(a, 0, 0);
	}
	return (i);
}

int			gnl(t_stack *a, t_stack *b, char *line)
{
	int	i;

	i = 0;
	if (ft_strstr(line, "rra") && ++i)
		rra_rrb_rrr(a, 0, 0);
	if (ft_strstr(line, "rrb") && ++i)
		rra_rrb_rrr(b, 0, 0);
	else if (ft_strstr(line, "rrr") && ++i)
	{
		if (count_mem(b) && count_mem(a) == 0)
			rra_rrb_rrr(a, 0, 0);
		else if (count_mem(a) && count_mem(b) == 0)
			rra_rrb_rrr(b, 0, 0);
		else if (count_mem(b) > 1 && count_mem(a) > 1)
			rra_rrb_rrr(a, b, 0);
	}
	else if (ft_strstr(line, "ra") && ++i)
	{
		if (count_mem(a) > 1)
			ra_rb_rr(a, 0, 0);
	}
	return (i);
}

void		action(t_stack *a, t_stack *b)
{
	char		*line;
	int			i[3];

	while (1)
	{
		i[1] = 0;
		i[0] = get_next_line(0, &line);
		i[1] = gnl(a, b, line);
		i[1] += gnl2(a, b, line);
		i[1] += gnl3(a, b, line);
		free(line);
		if (i[0] == 0 && !ft_strstr(line, "\n"))
			break ;
		if (i[1] == 0)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
	}
}

int			main(int ac, char **av)
{
	int			error;
	t_stack		a;
	t_stack		b;

	error = 0;
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
	action(&a, &b);
	if (!sorted(&a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
