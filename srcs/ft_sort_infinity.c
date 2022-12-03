/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_infinity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:48:36 by suchua            #+#    #+#             */
/*   Updated: 2022/12/04 00:37:15 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	size;

	size = get_stack_size(*a);
	i = -1;
	while (!check_sort(a))
	{
		j = -1;
		++i;
		while (++j < size)
		{
			if (((*a)->t_data >> i) & 1)
				ra(a, PRINT);
			else
				pb(a, b, PRINT);
		}
		while (*b)
			pa(a, b, PRINT);
	}
}

void	ft_sort_infinity(t_stack **a, t_stack **b)
{
	radix_sort(a, b);
}
