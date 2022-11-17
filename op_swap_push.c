/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:49:00 by suchua            #+#    #+#             */
/*   Updated: 2022/11/18 00:49:00 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int print)
{
	int	tmp;

	tmp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = tmp;
	if (print)
		ft_putendl_fd("sa", 1);
}

void	sb(t_stack **b, int print)
{
	int	tmp;

	tmp = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = tmp;
	if (print)
		ft_putendl_fd("sb", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	ft_putendl_fd("ss", 1);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!b && !*b)
		return ;
	stack_add_front(a, ft_newstack((*b)->data));
	tmp = (*b)->next;
	free(*b);
	*b = NULL;
	*b = tmp;
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!a && !*a)
		return ;
	stack_add_front(b, ft_newstack((*a)->data));
	tmp = (*a)->next;
	free(*a);
	*a = NULL;
	*a = tmp;
	ft_putendl_fd("pb", 1);
}
