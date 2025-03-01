/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:30:48 by nosahimi          #+#    #+#             */
/*   Updated: 2025/02/28 17:22:13 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	int top_a;
	int top_b;
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
	if (is_sorted(top_a, stack_a))
		return (morgan_freeman(stack_a, stack_b), 0);
	if (len < 3)
		trio(stack_a, len);
	else
		sorting(&top_a, &top_b, stack_a, stack_b, len - 1);
	morgan_freeman(stack_a, stack_b);
}
