/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:14:47 by nosahimi          #+#    #+#             */
/*   Updated: 2025/03/02 12:32:18 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_more_operations(int *top_a, int *top_b, int *stack_a, int *stack_b, char *line, int size)
{
		if ((ft_strcmp(line, "rra\n") == 0))
			rev_rotate(*top_a, stack_a, size, "");
		else if ((ft_strcmp(line, "rrb\n") == 0))
			rev_rotate(*top_b, stack_b, size, "");
		else if((ft_strcmp(line, "rr\n") == 0))
		{
			rotate(*top_a, stack_a, size, "");
			rotate(*top_b, stack_b, size, "");
		}
		else if ((ft_strcmp(line, "rrr\n") == 0))
		{
			rev_rotate(*top_a, stack_a, size, "");
			rev_rotate(*top_b, stack_b, size, "");
		}
		else
		{
			write(2, "Error\n", 6);
			morgan_freeman(stack_a, stack_b);
			free(line);
			get_next_line(-1);
			exit(1);
		}
}

void	get_operation(int *top_a, int *top_b, int *stack_a, int *stack_b, int size)
{
	char *line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_strcmp(line, "pa\n") == 0)
			push(top_a, top_b, stack_a, stack_b, size, "");
		else if (ft_strcmp(line, "pb\n") == 0)
			push(top_b, top_a, stack_b, stack_a,size, "");
		else if (ft_strcmp(line, "sa\n") == 0)
			swap(*top_a, stack_a, size,  "");
		else if (ft_strcmp(line, "sb\n") == 0)
			swap(*top_b, stack_b, size,  "");
		else if ((ft_strcmp(line, "ra\n") == 0))
			rotate(*top_a, stack_a, size, "");
		else if ((ft_strcmp(line, "rb\n") == 0))
			rotate(*top_b, stack_b, size, "");
		else
			get_more_operations(top_a, top_b, stack_a, stack_b, line, size);
		free(line);
		line = get_next_line(0);
	}
}
void check_in(int top_a, int top_b, int *stack_a, int *stack_b)
{
	if (is_sorted(top_a, stack_a) && top_b == -1)
	{
		write(1, "OK\n", 3);
		morgan_freeman(stack_a, stack_b);
		exit(0);
	}
	else 
	{
		write(1, "KO\n", 3);
		morgan_freeman(stack_a, stack_b);
		exit(1);
	}
}
int	main(int ac, char *av[])
{
	int	top_a;
	int	top_b;
	int *stack_a;
	int *stack_b ;
	int len;

	if (ac <= 1)
		return (0);
	len = count_args(av, ac) + 1;
	stack_a = malloc(sizeof(int) * (len - 1));
	stack_b = malloc(sizeof(int) * (len - 1));
	if (!stack_a || !stack_b)
	   return (morgan_freeman(stack_a, stack_b), 0);
	top_a = -1;
	top_b = -1;
	fill_stack(&top_a, av, stack_a,stack_b, ac);
	if (error_check(len, stack_a, ac, av) == 1)
		return (write(2, "Error\n", 6),morgan_freeman(stack_a, stack_b), 0);
	 get_operation(&top_a, &top_b, stack_a, stack_b, len);	
	check_in(top_a, top_b, stack_a, stack_b);
}
