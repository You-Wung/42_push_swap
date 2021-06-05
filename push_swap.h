/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 21:27:59 by tyou              #+#    #+#             */
/*   Updated: 2021/06/05 16:39:21 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define CHUNK 28
# define S_C 3

typedef struct		s_lstnum
{
	int				n;
	struct s_lstnum	*next;
	struct s_lstnum	*prev;
}					t_lstnum;
typedef struct		s_stack
{
	t_lstnum		*head;
	t_lstnum		*end;
	int				first;
}					t_stack;
typedef struct		s_inta
{
	int				ra;
	int				rb;
	int				pb;
	int				s_rb;
	int				s_ra;
	int				s_pb;
}					t_inta;
typedef struct		s_intb
{
	int				ra;
	int				rb;
	int				pa;
	int				s_rb;
	int				s_ra;
	int				s_pa;
	int				i;
}					t_intb;
int					ft_setac(char **s);
void				build_stack(t_stack *a, int ac, char **av);
int					count_mem(t_stack *a);
void				three(t_stack *a);
void				five(t_stack *a, t_stack *b, int amount);
void				find_pivet(t_stack *a, int *pivet, int size);
void				sort321(t_stack *a, t_stack *b);
void				sort312(t_stack *a, t_stack *b);
void				sort132(t_stack *a, t_stack *b);
void				sort231(t_stack *a, t_stack *b);
void				sort213(t_stack *a, t_stack *b);
void				b_return(t_stack *a, t_stack *b, int size);
void				small_sort(t_stack *a, t_stack *b, int size);
void				small_sort_b(t_stack *b);
int					ft_setac(char **s);
int					ft_isblank(char c);
int					ft_char_num(char c);
void				ft_error(int i);
int					sorted(t_stack *t);
void				sa_sb_ss(t_stack *t, t_stack *tt, int sign);
void				ra_rb_rr(t_stack *t, t_stack *tt, int sign);
void				rra_rrb_rrr(t_stack *t, t_stack *tt, int sign);
void				pa_pb(t_stack *t, t_stack *tt, int sign);
void				b_to_a(t_stack *a, t_stack *b, int size);
void				a_to_b(t_stack *a, t_stack *b, int size);
#endif
