/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosahimi <nosahimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:13:19 by nosahimi          #+#    #+#             */
/*   Updated: 2025/03/02 15:35:57 by nosahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_struct
{
	int a;
	char *ptr;
}t_struct;

void fun(t_struct *ss)
{
	ss->a = 3;
	int top = ss->a;
	top = top + 5;	
	printf("top = %d \n", top);
	ss->ptr = "hello";
}
int main()
{
	t_struct s;
	
	s.a = 42;
	s.ptr = "toto";
	fun(&s);
	printf("%d %s\n",s.a ,s.ptr);
	
}
