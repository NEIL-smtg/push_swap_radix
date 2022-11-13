/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:07:31 by suchua            #+#    #+#             */
/*   Updated: 2022/11/11 18:51:59 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, int print)
{
	t_stack	*new_first;
	t_stack	*tmp;
	int		size;

	if (!a || !*a || get_stack_size(*a) <= 1)
		return ;
	tmp = get_last_elem(*a);
	size = get_stack_size(*a);
	stack_add_front(a, ft_newstack(tmp->data));
	free(tmp);
	tmp = NULL;
	tmp = (*a);
	while (size-- > 1)
		tmp = tmp->next;
	tmp->next = NULL;
	if (print)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **b, int print)
{
	t_stack	*new_first;
	t_stack	*tmp;
	int		size;

	if (!b || !*b || get_stack_size(*b) <= 1)
		return ;
	tmp = get_last_elem(*b);
	size = get_stack_size(*b);
	stack_add_front(b, ft_newstack(tmp->data));
	free(tmp);
	tmp = NULL;
	tmp = (*b);
	while (size-- > 1)
		tmp = tmp->next;
	tmp->next = NULL;
	if (print)
		ft_putendl_fd("rra", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_putendl_fd("rrr", 1);
}
