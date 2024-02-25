/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements_reverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:50:04 by imurugar          #+#    #+#             */
/*   Updated: 2024/02/25 14:29:36 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

/**
 * It takes the last element of the stack and puts it at 
 * the beginning of the stack
 * 
 * @param stack pointer to the stack
 * @param option This is the option that will be used to print the command.
 */
void	reverserot(t_stack **stack, char option)
{
	t_stack	*last;
	t_stack	*aux;
	t_stack	*prelast;

	prelast = (*stack);
	last = (*stack)->next;
	if (last != NULL)
	{
		while (last->next)
			last = last->next;
		while (prelast->next->next)
			prelast = prelast->next;
		aux = (*stack);
		(*stack) = last;
		last->next = aux;
		prelast->next = NULL;
		if (option == 'a')
			write(1, "rra\n", 4);
		if (option == 'b')
			write(1, "rrb\n", 4);
	}
}

/**
 * Rrr() rotates both stacks to the right.
 * 
 * @param a pointer to the first stack
 * @param b the stack to be operated on
 */
void	rrr(t_stack **a, t_stack **b)
{
	reverserot(a, 'x');
	reverserot(b, 'x');
	write(1, "rrr\n", 4);
}
