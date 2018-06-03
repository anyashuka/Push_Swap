/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_quarters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 18:47:46 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/01 17:09:25 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reset_moves(t_frame *frame)
{
	BIGGEST = 0;
	BIG_ROTATE = 0;
	BIG_RROTATE = 0;
	BIG_FLAG = 0;
	SMALLEST = 0;
	SMALL_ROTATE = 0;
	SMALL_RROTATE = 0;
	SMALL_FLAG = 0;
}

/*
** Pushes every number above or below quarters into Stack b,
** based on split flag
*/

static void	push_first_quarter(t_frame *frame)
{
	if (frame->b && frame->b->num > QUARTER / 2)
		do_rb(frame);
	do_pb(frame);
}

static void	push_second_quarter(t_frame *frame)
{
	if (frame->b && frame->b->num > (MEDIAN / 4) * 3)
		do_rb(frame);
	do_pb(frame);
}

static void	push_third_quarter(t_frame *frame)
{
	if (frame->b && frame->b->num > (MEDIAN / 4) * 5)
		do_rb(frame);
	do_pb(frame);
}

static void	push_fourth_quarter(t_frame *frame)
{
	if (frame->b && frame->b->num > (MEDIAN / 4) * 7)
		do_rb(frame);
	do_pb(frame);
}

void		push_quarters(t_frame *frame, int split)
{
	t_stack	*stack_a;
	t_stack	*stack_a_end;
	int		flag;

	stack_a = frame->a;
	stack_a_end = frame->a->prev;
	flag = 0;
	find_smallest(frame, 'a');
	while (flag != 1)
	{
		if (stack_a == stack_a_end)
			flag = 1;
		if (split == 1 && stack_a->num <= QUARTER)
			push_first_quarter(frame);
		else if (split == 2 && stack_a->num > QUARTER && stack_a->num <= MEDIAN)
			push_second_quarter(frame);
		else if (split == 3 && stack_a->num > MEDIAN && stack_a->num <= THREE_Q)
			push_third_quarter(frame);
		else if (split == 4 && stack_a->num > THREE_Q)
			push_fourth_quarter(frame);
		else if (split == 4 && stack_a->num == SMALLEST)
			break ;
		else
			do_ra(frame);
		stack_a = frame->a;
	}
	reset_moves(frame);
}

