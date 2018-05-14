/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:26:29 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/14 16:38:36 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_frame		*create_frame(t_frame *frame, int argc, char **argv)
{
	if (!(frame = (t_frame *)malloc(sizeof(t_frame))))
		push_swap_error(frame);
	frame->a = NULL;
	frame->b = NULL;
	frame->argc = argc;
	frame->argv = argv;
	frame->line = NULL;
	frame->str = NULL;
	return (frame);
}
