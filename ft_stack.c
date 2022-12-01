/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:17:21 by suchua            #+#    #+#             */
/*   Updated: 2022/11/08 23:17:21 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_newstack(int data, int sign)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->sign = sign;
	return (new);
}

t_stack	*get_last_elem(t_stack *stack)
{
	t_stack	*s;

	if (!stack)
		return (NULL);
	s = stack;
	while (s->next)
		s = s->next;
	return (s);
}

int	get_stack_size(t_stack *stack)
{
	t_stack	*s;
	int		size;

	if (!stack)
		return (0);
	s = stack;
	size = 0;
	while (s)
	{
		s = s->next;
		size++;
	}
	return (size);
}

void	ft_clear_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack && stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	(*stack) = NULL;
}
