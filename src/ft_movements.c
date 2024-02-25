/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:24:28 by imurugar          #+#    #+#             */
/*   Updated: 2023/03/12 16:57:44 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

/**
 * If the stack has more than one element, swap the first two elements.
 * 
 * @param stack a pointer to a pointer to the first element of the stack
 */
void	sa(t_stack **stack)
{
	t_stack	*second;

	second = (*stack)->next;
	if (second != NULL)
	{
		(*stack)->next = second->next;
		second->next = (*stack);
		(*stack) = second;
		write(1, "sa\n", 3);
	}
}

/**
 * It takes the first element of the origin stack and puts 
 * it at the beginning of the destination stack
 * 
 * @param origin the stack from which we are taking the element
 * @param dest the stack where the element will be pushed to
 * @param stackdest The stack that the element will be pushed to.
 */
void	push(t_stack **origin, t_stack **dest, char stackdest)
{
	t_stack	*aux;

	aux = (*origin);
	(*origin) = aux->next;
	aux->next = (*dest);
	(*dest) = aux;
	if (stackdest == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

/**
 * It takes the first element of the stack and puts it at the end of the stack
 * 
 * @param stack pointer to the stack that will be rotated.
 * @param option 'a' or 'b'
 */
void	rotate(t_stack **stack, char option)
{
	t_stack	*last;
	t_stack	*aux;

	last = (*stack)->next;
	if (last != NULL)
	{
		while (last->next)
			last = last->next;
		aux = (*stack);
		(*stack) = aux->next;
		last->next = aux;
		aux->next = NULL;
		if (option == 'a')
			write(1, "ra\n", 3);
		if (option == 'b')
			write(1, "rb\n", 3);
	}
}

/**
 * It rotates both stacks
 * 
 * @param a pointer to the first element of the stack a
 * @param b the stack to be rotated
 */
void	rr(t_stack **a, t_stack **b)
{
	rotate(a, 'x');
	rotate(b, 'x');
	write(1, "rr\n", 3);
}
