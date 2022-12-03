/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:18:30 by suchua            #+#    #+#             */
/*   Updated: 2022/12/04 00:40:03 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_KO(void)
{
	ft_putendl_fd("KO", 1);
}

void	print_OK(void)
{
	ft_putendl_fd("OK", 1);
}

void	free_everything(char *ops, t_stack **a, t_stack **b)
{
	free(ops);
	ft_clear_stack(a);
	ft_clear_stack(b);
	ops = NULL;
	exit_now();
}

void	print_stack(t_stack *a, t_stack *b)
{
	ft_printf("%6c\t%14c\n", 'a', 'b');
	while (a)
	{
		if (b)
			ft_printf("|%11d  |\t|%11d  |\n", a->data, b->data);
		else
			ft_printf("|%11d  |\t|%11c  |\n", a->data, 'n');
		a = a->next;
		if (b)
			b = b->next;
	}
}

void	check_ops(char *op, t_stack **a, t_stack **b)
{
	// if (ops[2] != 0 || ops[3] != 0)
	// {
	// 	free_everything(ops, a, b);
	// 	exit_now();
	// }
	if (!ft_strncmp(op, "pa", 2))
		return ;
	else if (!ft_strncmp(op, "pb", 2))
		return ;
	else if (!ft_strncmp(op, "rra", 3))
		return ;
	else if (!ft_strncmp(op, "rrb", 3))
		return ;
	else if (!ft_strncmp(op, "rrr", 3))
		return ;
	else if (!ft_strncmp(op, "ra", 2))
		return ;
	else if (!ft_strncmp(op, "rb", 2))
		return ;
	else if (!ft_strncmp(op, "rr", 2))
		return ;
	else if (!ft_strncmp(op, "sa", 2))
		return ;
	else if (!ft_strncmp(op, "sb", 2))
		return ;
	else if (!ft_strncmp(op, "ss", 2))
		return ;
	else
		free_everything(op, a, b);
}

void	do_ops(char *op, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(op, "pa", 2) && *b)
		pa(a, b, 0);
	else if (!ft_strncmp(op, "pb", 2) && *a)
		pb(a, b, 0);
	else if (!ft_strncmp(op, "rra", 3) && *a)
		rra(a, 0);
	else if (!ft_strncmp(op, "rrb", 3) && *b)
		rrb(b, 0);
	else if (!ft_strncmp(op, "rrr", 3))
	{
		if (*a && *b)
			rrr(a, b, 0);
		else if (*a)
			rra(a, 0);
		else if (*b)
			rrb(b, 0);
	}
	else if (!ft_strncmp(op, "ra", 2) && *a)
		ra(a, 0);
	else if (!ft_strncmp(op, "rb", 2) && *b)
		ra(a, 0);
	else if (!ft_strncmp(op, "rr", 2))
	{
		if (*a && *b)
			rr(a, b, 0);
		else if (*a)
			ra(a, 0);
		else if (*b)
			rb(b, 0);
	}
	else if (!ft_strncmp(op, "sa", 2) && get_stack_size(*a) >= 2)
		sa(a, 0);
	else if (!ft_strncmp(op, "sb", 2) && get_stack_size(*b) >= 2)
		sb(b, 0);
	else if (!ft_strncmp(op, "ss", 2))
	{
		if (get_stack_size(*a) >= 2 && get_stack_size(*b) >= 2)
			ss(a, b, 0);
		else if (get_stack_size(*a) >= 2)
			sa(a, 0);
		else if (get_stack_size(*b) >= 2)
			sb(b, 0);
	}
}

void	get_input(t_stack **a, t_stack **b)
{
	char	*ops;

	while (1)
	{
		ops = get_next_line(STDIN);
		if (!ops)
			break ;
		check_ops(ops, a, b);
		do_ops(ops, a, b);
		free(ops);
	}
}

void	show_result(t_stack **a)
{
	if (!check_sort(a))
		print_KO();
	else
		print_OK();
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 2)
	{
		stack_a = ft_check_valid(ac, av);
		//print_stack(stack_a, stack_b);
		get_input(&stack_a, &stack_b);
		show_result(&stack_a);
		ft_clear_stack(&stack_a);
		ft_clear_stack(&stack_b);
	}
	return (0);
}
