/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:53:18 by tyou              #+#    #+#             */
/*   Updated: 2021/06/05 13:40:12 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort_buf(int *buf, int size)
{
	int		tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (buf[i] < buf[j])
			{
				tmp = buf[i];
				buf[i] = buf[j];
				buf[j] = tmp;
			}
		}
	}
}

static int		*set_buf(t_stack *a, int size)
{
	int			i;
	int			*buf;
	t_lstnum	*tmp;

	buf = malloc(sizeof(int) * (size + 1));
	tmp = a->head;
	i = -1;
	while (++i < size)
	{
		buf[i] = tmp->n;
		tmp = tmp->next;
	}
	sort_buf(buf, size);
	return (buf);
}

void			find_pivet(t_stack *a, int *pivet, int size)
{
	int		*buf;

	buf = set_buf(a, size);
	pivet[0] = buf[size / 3];
	if (size / 3 == 1)
		pivet[1] = buf[size / 3 + 1];
	else
	{
		if (size % 2 == 1)
			pivet[1] = buf[size / 3 * 2 - 1];
		else
			pivet[1] = buf[size / 3 * 2];
	}
	free(buf);
}
