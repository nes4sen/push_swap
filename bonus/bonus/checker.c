/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:14:47 by nosahimi          #+#    #+#             */
/*   Updated: 2025/03/19 01:12:29 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_more_operations(t_stack s, char *line, int size)
{
	if ((ft_strcmp(line, "rra\n") == 0))
		rev_rotate(s.top_a, s.stack_a, size, "");
	else if ((ft_strcmp(line, "rrb\n") == 0))
		rev_rotate(s.top_b, s.stack_b, size, "");
	else if ((ft_strcmp(line, "rr\n") == 0))
	{
		rotate(s.top_a, s.stack_a, size, "");
		rotate(s.top_b, s.stack_b, size, "");
	}
	else if ((ft_strcmp(line, "rrr\n") == 0))
	{
		rev_rotate(s.top_a, s.stack_a, size, "");
		rev_rotate(s.top_b, s.stack_b, size, "");
	}
	else if ((ft_strcmp(line, "ss\n") == 0))
	{
		swap(s.top_a, s.stack_a, size, "");
		swap(s.top_b, s.stack_b, size, "");
	}
	else
	{
		(write(2, "Error\n", 6), morgan_freeman(&s));
		(free(line), get_next_line(-1), exit(1));
	}
}

void	get_operation(t_stack *s, int size)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_strcmp(line, "pa\n") == 0)
			push_a(s, size, "");
		else if (ft_strcmp(line, "pb\n") == 0)
			push_b(s, size, "");
		else if (ft_strcmp(line, "sa\n") == 0)
			swap(s->top_a, s->stack_a, size, "");
		else if (ft_strcmp(line, "sb\n") == 0)
			swap(s->top_b, s->stack_b, size, "");
		else if ((ft_strcmp(line, "ra\n") == 0))
			rotate(s->top_a, s->stack_a, size, "");
		else if ((ft_strcmp(line, "rb\n") == 0))
			rotate(s->top_b, s->stack_b, size, "");
		else
			get_more_operations(*s, line, size);
		free(line);
		line = get_next_line(0);
	}
}

void	check_in(t_stack s)
{
	if (is_sorted(s.top_a, s.stack_a) && s.top_b == -1)
	{
		write(1, "OK\n", 3);
		morgan_freeman(&s);
		exit(0);
	}
	else
	{
		write(1, "KO\n", 3);
		morgan_freeman(&s);
		exit(1);
	}
}

int	main(int ac, char *av[])
{
	t_stack	s;
	int		len;

	if (ac <= 1)
		return (0);
	len = count_args(av, ac) + 1;
	s.stack_a = malloc(sizeof(int) * (len - 1));
	s.stack_b = malloc(sizeof(int) * (len - 1));
	if (!s.stack_a || !s.stack_b)
		return (morgan_freeman(&s), 0);
	s.top_a = -1;
	s.top_b = -1;
	fill_stack(&s, av, ac, len);
	if (error_check(len, s.stack_a, ac, av) == 1)
		return (write(2, "Error\n", 6), morgan_freeman(&s), 0);
	get_operation(&s, len);
	check_in(s);
}
