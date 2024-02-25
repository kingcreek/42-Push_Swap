/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heuristics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:37:11 by imurugar          #+#    #+#             */
/*   Updated: 2024/02/25 14:29:14 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

/**
 * Optimal number of moves for an element to be in the top of the stack B
 * 
 * @param b pointer to the head of the stack b
 * @param size_b the size of the stack b
 */
static void	calc_cost_b(t_stack **b, int size_b)
{
	t_stack	*aux_b;

	aux_b = *b;
	while (aux_b)
	{
		if ((aux_b->pos + 1) <= size_b / 2 + 1)
			aux_b->cost_b = aux_b->pos;
		else
			aux_b->cost_b = aux_b->pos - size_b;
		aux_b = aux_b->next;
	}
}

/**
 * It calculates the cost of moving a number from stack B to top of stack A
 * 
 * @param b the stack to be sorted
 * @param size_a the size of the stack a
 */
static void	calc_cost_a(t_stack **b, int size_a)
{
	t_stack	*aux_b;

	aux_b = *b;
	while (aux_b)
	{
		if ((aux_b->target_pos + 1) <= size_a / 2 + 1)
			aux_b->cost_a = aux_b->target_pos;
		else
			aux_b->cost_a = aux_b->target_pos - size_a;
		aux_b = aux_b->next;
	}
}

/**
 * It assigns a cost to each element in the stack, based on how
 * many moves it would take to get that
 * element to the top of the stack.
 * 
 * @param b the stack
 * @param size_a the size of the stack a
 * @param size_b the size of the stack b
 */
void	assign_costs(t_stack **b, int size_a, int size_b)
{
	calc_cost_b(b, size_b);
	calc_cost_a(b, size_a);
}

/**
 * Absv() returns the absolute value of the integer passed to it.
 * 
 * @param num The number to be converted to absolute value.
 * 
 * @return The absolute value of the number.
 */
int	absv(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}
