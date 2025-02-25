/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:56:17 by nosahimi          #+#    #+#             */
/*   Updated: 2025/02/25 15:57:36 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int ft_strlen(char *str)
{
    int count;

    count = 0;
    while (str[count])
    {
        count++;
    }
    return (count);
}

void fill_stack(int *top, char **av , int *stack, int ac)
{
    int i;
    int j;
    int count;
    char **fill;
    int av_cpy[ac];

    if (*top == ac - 1)
        return;
    i = 1;
    count = 0;
    while(i < ac )
    {
        j = 0;
        fill = ft_split(av[i], ' ');
        while(fill[j] != NULL)
        {
            av_cpy[count++] = ft_atoi(fill[j]);
            // printf("%d ",ft_atoi(fill[j]));
            j++;
        }
        i++;
    }
    i = count - 1;
    while(i >= 0)
    {
        printf("%d ",av_cpy[i]);
        stack[++(*top)] = av_cpy[i];
        i--;
    }
}

int is_all_digit(char *str)
{
    if (*str == '+' || *str == '-')
        str++;
    while (*str)
    {
        if (!(*str >= '0' && *str <= '9'))
            return 0;
        str++;
    }
    return 1;
}
int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    return (s1[i] - s2[i]);
}
int error_check(int ac, char **av)
{
    int i;
    int j;
    i = 1;
    
    if (ac < 2)
      return 0;
    while (i < ac)
    {
        j = i + 1;
        if (is_all_digit(av[i]) == 0)
            return 0;
        while (j < ac)
        {
            if (ft_atoi(av[i]) ==  ft_atoi(av[j]))
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}