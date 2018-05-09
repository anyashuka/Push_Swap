/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:30:17 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/08 12:30:19 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Main creates frame to hold stack a and stack b by caling create_frame.
*/

int		main(int argc, char **argv)
{
	t_frame		*frame;

	frame = NULL;
	if (argc < 2)
		push_swap_error(frame);
	frame = create_frame(frame, argc, argv);
	checker(frame);
	return (0);
}
