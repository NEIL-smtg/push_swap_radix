/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 01:39:38 by suchua            #+#    #+#             */
/*   Updated: 2022/11/14 01:39:38 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(int first, int second, int third)
{
	if (first < second && first < third)
		return (1);
	if (second < first && second < third)
		return (2);
	if (third < first && third < second)
		return (3);
}

void	ft_handle_min1(int second, int third, t_stack **s, int stack)
{
	if (second > third)
	{
		if (stack == TYPE_A)
		{
			rra(s, PRINT);
			sa(s, PRINT);
		}
		else
		{
			rrb(s, PRINT);
			sb(s, PRINT);
		}
	}
}

void	ft_handle_min2(int first, int third, t_stack **s, int stack)
{
	if (first > third)
	{
		if (stack == TYPE_A)
			ra(s, PRINT);
		else
			rb(s, PRINT);
	}
	else
	{
		if (stack == TYPE_A)
			sa(s, PRINT);
		else
			sb(s, PRINT);
	}
}

void	ft_handle_min3(int first, int second, t_stack **s, int stack)
{
	if (first > second)
	{
		if (stack == TYPE_A)
		{
			sa(s, PRINT);
			rra(s, PRINT);
		}
		else
		{
			sb(s, PRINT);
			rrb(s, PRINT);
		}
	}
	else
	{
		if (stack == TYPE_A)
			rra(s, PRINT);
		else
			rrb(s, PRINT);
	}
}

void	ft_sort3(t_stack **s, int type)
{
	int	first;
	int	second;
	int	third;
	int	min;

	first = (*s)->data;
	second = (*s)->next->data;
	third = (*s)->next->next->data;
	min = find_min(first, second, third);
	if (min == 1)
		ft_handle_min1(second, third, s, type);
	else if (min == 2)
		ft_handle_min2(first, third, s, type);
	else
		ft_handle_min3(first, second, s, type);
}
