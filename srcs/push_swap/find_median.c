/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 13:46:00 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/25 12:22:21 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(long *array, int len) // replace with ft_sort_array from libft
{
	long	tmp;
	int		i;

	tmp = 0;
	i = 0;
	while (i < len)
	{
		if (array[i] <= array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
}

/* Stores the stack in an array, sorts the array, and finds the median */

static void	find_median(t_frame *frame, t_stack *stack, char stack_name)
{
	long	*array;
	int		i;
	int		quarter_len;

	i = 0;
	frame->stack_len = find_stack_len(frame, stack_name);
	quarter_len = frame->stack_len / 4;
	if (!(array = (long*)malloc(sizeof(long) * frame->stack_len + 1)))
		push_swap_error(frame);
	while (i < frame->stack_len)
	{
		array[i++] = stack->num;
		stack = stack->next;
	}
	sort_array(array, frame->stack_len);
	frame->quarter = array[quarter_len];
	frame->median = array[quarter_len * 2];
	frame->three_quarters = array[quarter_len * 3];
	free(array);
}

void		median(t_frame *frame, char stack_name)
{
	t_stack	*stack;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	find_median(frame, stack, stack_name);
}
