/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:59:26 by nosahimi          #+#    #+#             */
/*   Updated: 2025/03/19 01:13:42 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_data
{
	int	cost_a;
	int	cost_b;
	int	cost_total;
}	t_cost;

typedef struct s_stack
{
	int	top_a;
	int	top_b;
	int	*stack_a;
	int	*stack_b;
}	t_stack;

//moves
void	push_a(t_stack *s, int size, char *op);
void	push_b(t_stack *s, int size, char *op);
void	swap(int top, int *stack, int size, char *op);
void	rotate(int top, int *stack, int size, char *op);
void	rev_rotate(int top, int *stack, int size, char *op);
void	rr_rrr(t_stack s, int size, char *op);

// cost function
t_cost	get_cost(int target_a, int value_b, t_stack s);
t_cost	best_move(t_stack s);
int		find_target(int nb, int top, int *stack);
int		count_to_top(int value, int *stack, int top);
void	into_the_top(t_cost moves, t_stack s, int ac);

//stack utils 
int		error_check(int len, int *stack, int ac, char **av);
void	fill_stack(t_stack *s, char **av, int ac, int len);
void	morgan_freeman(t_stack *s);

//input handling
int		is_sorted(int top, int *stack);
int		is_all_valid(int ac, char **av);
int		is_valid_num(char *str);
long	ft_atoi(const char *str);
int		count_args(char **av, int ac);

//sorting 
void	sorting(t_stack *s, int ac);
void	turk(t_stack *s, int ac);
void	trio(int *stack, int size);
void	back_to_top(int top_a, int *stack_a, int size);
int		*pseudo_sort(int *array, int size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	swaping(int *a, int *b);

// split
char	**ft_split(char const *s, char c);
void	free_split(char **av);
size_t	count_word(const char *str, char c);

//helper functions
int		ft_strlen(char *str);
int		biggest_num(int top, int *stack);
int		ft_strcmp(char *s1, char *s2);
int		smallest_num(int top, int *stack);

// bonus
int		is_new_line(char *str);
char	*get_next_line(int fd);
char	*ft_strdup(char *str);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *str1, char *str2);

#endif
