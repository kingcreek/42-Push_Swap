/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_more_than_three.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:18:28 by imurugar          #+#    #+#             */
/*   Updated: 2023/03/15 14:50:49 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

/**
 * It pushes the top element of stack A to stack B and 
 * decreases the size of stack A by one
 * 
 * @param a pointer to the first stack
 * @param b the stack that we're sorting
 * @param current_size the current size of the stack
 */
static void	push_and_decrease(t_stack **a, t_stack **b, int *current_size)
{
	push(a, b, 'b');
	(*current_size)--;
}

/**
 * It pushes all the numbers except the three biggest ones to stack B
 * First, push most lower number, based on the half of numbers + 1
 * 
 * @param a pointer to the first element of the stack a
 * @param b the stack that we're pushing to
 * @param size the size of the stack
 */
static void	push_all_except_three(t_stack **a, t_stack **b, int size)
{
	int	half;
	int	current_size;

	half = (size / 2) + 1 ;
	current_size = size;
	while (current_size > half && current_size >= 3)
	{
		if ((*a)->idx < half)
			push_and_decrease(a, b, &current_size);
		else
			rotate(a, 'a');
	}
	while (current_size > 3)
	{
		if ((*a)->idx == size
			|| (*a)->idx == size - 1
			|| (*a)->idx == size - 2)
			rotate(a, 'a');
		else
			push_and_decrease(a, b, &current_size);
	}
	sort_three_numbers(a);
}

/**
 * It calculates the position of each element in the stack
 * 
 * @param s The stack to be sorted.
 */
void	calculate_positions(t_stack *s)
{
	t_stack	*aux;
	int		pos;

	pos = 0;
	aux = s;
	while (aux)
	{
		aux->pos = pos;
		pos++;
		aux = aux->next;
	}
}

/**
 * It assigns the target position of each element in the stack b
 * 
 * @param a pointer to the head of the stack a
 * @param b the stack that we're trying to sort
 */
void	assign_target_pos(t_stack **a, t_stack **b)
{
	t_stack	*aux_b;

	aux_b = *b;
	while (aux_b)
	{
		assign_target_pos_lower_idx(a, &aux_b);
		aux_b = aux_b->next;
	}
}

/**
 * It pushes all the elements of the stack to the second stack,
 * except for the three smallest elements.
 * Then, it assigns a target position to each element of the second stack,
 * and executes the optimal
 * moves to get the elements of the second stack to their target positions
 * 
 * @param a pointer to the stack a
 * @param b the stack that we're pushing all the elements to
 * @param size the size of the stack
 */
void	sort_more_than_three(t_stack **a, t_stack **b, int size)
{
	int	size_b;
	int	size_a;

	push_all_except_three(a, b, size);
	size_a = 3;
	size_b = size - 3;
	while (*b)
	{
		calculate_positions(*a);
		calculate_positions(*b);
		assign_target_pos(a, b);
		assign_costs(b, size_a, size_b);
		exec_optimal_movs(a, b, &size_a, &size_b);
	}
	rotate_until_sorted(a, size_a);
}
