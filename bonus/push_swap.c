/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:30:48 by nosahimi          #+#    #+#             */
/*   Updated: 2025/03/16 03:04:18 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (is_sorted(s.top_a, s.stack_a))
		return (morgan_freeman(&s), 0);
	if (len < 3)
		trio(s.stack_a, len);
	else
		sorting(&s, len - 1);
	morgan_freeman(&s);
}
