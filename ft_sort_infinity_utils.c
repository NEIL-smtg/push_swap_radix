/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_infinity_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 00:21:18 by suchua            #+#    #+#             */
/*   Updated: 2022/12/02 00:21:18 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_from_top(t_stack **b, int max)
{
	while ((*b)->data != max)
		rb(b, PRINT);
}

void	rotate_from_bottom(t_stack **b, int max)
{
	while ((*b)->data != max)
		rrb(b, PRINT);
}

void	push_back_to_a(int max_index, t_stack **a, t_stack **b, int max)
{
	if (max_index < get_stack_size(*b) / 2)
		rotate_from_top(b, max);
	else
		rotate_from_bottom(b, max);
	pa(a, b);
}

void	find_max(t_stack **a, t_stack **b)
{
	int		max;
	int		i;
	int		j;
	t_stack	*tmpb;

	i = 0;
	j = 0;
	max = (*b)->data;
	tmpb = (*b);
	while (tmpb)
	{
		if (tmpb->data > max)
		{
			j = i;
			max = tmpb->data;
		}
		i++;
		tmpb = tmpb->next;
	}
	push_back_to_a(j, a, b, max);
}

void	sort_negative(t_stack **a, t_stack **b)
{
	while (*b)
		find_max(a, b);
}
