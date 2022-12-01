/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_infinity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:48:36 by suchua            #+#    #+#             */
/*   Updated: 2022/12/02 01:50:03 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	contain_positive(t_stack *s)
{
	t_stack	*tmp;

	tmp = s;
	while (tmp)
	{
		if (tmp->data >= 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	push_back(t_stack **a, t_stack **b)
{
	while (contain_positive(*b))
	{
		if ((*b)->data < 0)
			rb(b, PRINT);
		else
			pa(a, b);
	}
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	size;

	size = get_stack_size(*a);
	i = -1;
	while (!check_sort(a))
	{
		++i;
		j = -1;
		while (++j < size)
		{
			if ((*a)->data < 0)
				pb(a, b);
			else if (((*a)->data >> i) & 1)
				ra(a, PRINT);
			else
				pb(a, b);
		}
		push_back(a, b);
		size = get_stack_size(*a);
	}
}

void	ft_sort_infinity(t_stack **a, t_stack **b)
{
	radix_sort(a, b);
	sort_negative(a, b);
}
