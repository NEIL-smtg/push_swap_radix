/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:01:41 by suchua            #+#    #+#             */
/*   Updated: 2022/11/18 16:01:41 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_somewhere(t_stack **a, t_stack **b)
{
	int	n;

	n = 0;
	while (*b)
	{
		while ((*a)->data < (*b)->data)
		{
			ra(a, PRINT);
			n++;
		}
		pa(a, b);
		while (--n)
			rra(a, PRINT);
	}
}

// a 1 3 7
// b 2 4

void	ft_sort5(t_stack **a, t_stack **b)
{
	t_stack	*last;
	t_stack	*bnext;

	bnext = NULL;
	if ((*b)->next)
		bnext = (*b)->next;
	while (*b)
	{
		last = get_last_elem(*a);
		if ((*b)->data > last->data)
		{
			pa(a, b);
			ra(a, PRINT);
		}
		else if ((*b)->data < (*a)->data)
			pa(a, b);
		else if (bnext && bnext->data < (*a)->data)
		{
			sb(b, PRINT);
			pa(a, b);
		}
		else if (bnext && bnext->data > last->data)
		{
			sb(b, PRINT);
			pa(a, b);
			ra(a, PRINT);
		}
		else
			ft_push_somewhere(a, b);
	}	
}
