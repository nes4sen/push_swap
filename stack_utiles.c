/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:56:17 by nosahimi          #+#    #+#             */
/*   Updated: 2025/03/02 12:08:04 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	if (!s1 && !s2)
		return (NULL);
	while (n--)
		*s1++ = *s2++;
	return (dest);
}
static void int_range(char *str, int *stack_a, int *stack_b)
{
    if (ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN)
    {
        write(2, "Error\n", 6);
        morgan_freeman(stack_a, stack_b);
        exit(1);
    }
}
long ft_atoi(const char *str)
{
	long	nb;
	int	sign;

	while (*str == ' ' || (*str >= 7 && *str <= 13))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	nb = 0;
	while (*str && (*str >= '0' && *str <= '9'))
		nb = (nb * 10) + (*str++ - 48);
	return (sign * nb);
}
void fill_stack(int *top, char **av , int *stack_a, int *stack_b, int ac)
{
	int i;
	int j;
	int count;
	char **fill;
	int av_cpy[550]; 

	i = 1;
	count = 0;
	while (i < ac)
	{
		fill = ft_split(av[i], ' ');
		j = 0;
		while (fill[j] != NULL)
		{
			int_range(fill[j], stack_a, stack_b);
			av_cpy[count++] = ft_atoi(fill[j]);
			j++;
		}
		free_split(fill);
		i++;
	}
	i = count  - 1;
	while (i >= 0)
	    stack_a[++(*top)] = av_cpy[i--];
}
