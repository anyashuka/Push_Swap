/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 00:34:10 by dhojt             #+#    #+#             */
/*   Updated: 2018/05/06 00:34:25 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_rb(t_frame *frame)
{
	if (frame->b)
		frame->b = frame->b->next;
}