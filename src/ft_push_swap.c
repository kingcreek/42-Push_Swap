/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:42:05 by amorilla          #+#    #+#             */
/*   Updated: 2023/12/19 15:50:04 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

/*
void	ft_leaks(void)
{
	system("leaks parse");
}
atexit(ft_leaks);
*/
int	main(int argc, char **argv)
{
	int		size;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	size = 0;
	if (argc > 1)
	{
		if (argc < 2)
			print_error();
		a = process(argc, argv, &size);
		if (!a || checkdup(a))
		{
			freestack(&a);
			print_error();
		}
		if (!checksorted(a))
			sort_stacks(&a, &b, size);
		freestacks(&a, &b);
	}
	exit(EXIT_SUCCESS);
}
