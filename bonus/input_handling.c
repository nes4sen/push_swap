/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:16:25 by nosahimi          #+#    #+#             */
/*   Updated: 2025/03/16 16:04:59 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_num(char *str)
{
	while (*str)
	{
		while (*str == ' ' || *str == '\t')
			str++;
		if (*str == '-' || *str == '+')
		{
			str++;
			if (!(*str >= '0' && *str <= '9') || *str == '\0')
				return (0);
		}
		while (*str && ((*str >= '0' && *str <= '9')))
			str++;
		if (!(*str >= '0' && *str <= '9')
			&& (*str != ' ' && *str != '\t') && *str)
			return (0);
	}
	return (1);
}

int	is_valid_arg(char *str)
{
	if (*str == '\0')
		return (0);
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	if (*str == '\0')
		return (0);
	return (1);
}

int	is_all_valid(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_valid_num(av[i]) == 0 || is_valid_arg(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(int top, int *stack)
{
	int	i;

	i = 0;
	while (i < top)
	{
		if (stack[i] < stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	error_check(int len, int *stack, int ac, char **av)
{
	int	i;
	int	j;

	if (is_all_valid(ac, av) == 0 || ac < 2)
		return (1);
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len - 1)
		{
			if (stack[i] == stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
