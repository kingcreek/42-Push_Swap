/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_movements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:49:33 by imurugar          #+#    #+#             */
/*   Updated: 2024/02/25 14:29:04 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

/**
 * If both moves are positive, do a rr, if both moves are negative,
 * do a rrr, if one is positive and
 * the other is negative, do a rrrr
 * 
 * @param a pointer to the first stack
 * @param b the stack that we're sorting
 * @param movsa the number of moves to get to the desired position 
 * in stack a
 * @param movsb the number of moves needed to move the element 
 * to the top of stack b
 */
static void	execdoublemoves(t_stack **a, t_stack **b, int *movsa, int *movsb)
{
	if ((*movsa) > 0 && (*movsb) > 0)
	{
		rr(a, b);
		(*movsa)--;
		(*movsb)--;
	}
	else if ((*movsa) < 0 && (*movsb) < 0)
	{
		rrr(a, b);
		(*movsa)++;
		(*movsb)++;
	}
}

/**
 * It takes two stacks, and two integers, and moves the stacks 
 * around until the integers are zero
 * 
 * @param a the stack to move from
 * @param b the stack to move the element to
 * @param movsa the number of moves to get the element to the top 
 * of stack a
 * @param movsb the number of moves needed to get the element to the 
 * top of stack b
 */
static void	executemovs(t_stack **a, t_stack **b, int movsa, int movsb)
{
	while (movsa != 0 || movsb != 0)
	{
		if ((movsa > 0 && movsb > 0) || (movsa < 0 && movsb < 0))
			execdoublemoves(a, b, &movsa, &movsb);
		else if (movsa < 0)
		{
			reverserot(a, 'a');
			movsa++;
		}
		else if (movsb < 0)
		{
			reverserot(b, 'b');
			movsb++;
		}
		else if (movsa > 0)
		{
			rotate(a, 'a');
			movsa--;
		}
		else if (movsb > 0)
		{
			rotate(b, 'b');
			movsb--;
		}
	}
}

/**
 * It finds the best node in the stack b, and executes the moves
 * to get it to the top of stack a
 * 
 * @param a pointer to the first node of the stack a
 * @param b the stack b
 * @param size_a size of stack a
 * @param size_b the size of the stack b
 */
void	exec_optimal_movs(t_stack **a, t_stack **b, int *size_a, int *size_b)
{
	t_stack	*best_node;
	t_stack	*auxb;

	auxb = *b;
	best_node = *b;
	while (auxb)
	{
		if ((absv(best_node->cost_a) + absv(best_node->cost_b))
			> (absv(auxb->cost_a) + absv(auxb->cost_b)))
		{
			best_node = auxb;
		}
		auxb = auxb->next;
	}
	executemovs(a, b, best_node->cost_a, best_node->cost_b);
	push(b, a, 'a');
	(*size_a)++;
	(*size_b)--;
}

/**
 * It calculates the number of rotates needed to get the smallest 
 * element in the stack to the top
 * 
 * @param a pointer to the stack a
 * @param size_a the size of the stack a
 * 
 * @return The number of rotates needed to get the smallest element 
 * to the top of the stack.
 */
static int	calc_num_rotates(t_stack **a, int size_a)
{
	t_stack	*auxa;

	auxa = *a;
	calculate_positions(*a);
	while (auxa)
	{
		if (auxa->idx == 1)
		{
			if ((auxa->pos + 1) <= size_a / 2 + 1)
				return (auxa->pos);
			else
				return (auxa->pos - size_a);
		}
		auxa = auxa->next;
	}
	return (0);
}

/**
 * It takes a stack and the size of that stack as arguments, 
 * and then rotates the stack until it is
 * sorted
 * 
 * @param a the stack to be sorted
 * @param size_a the size of the stack a
 */
void	rotate_until_sorted(t_stack **a, int size_a)
{
	int	num_rotates;

	num_rotates = calc_num_rotates(a, size_a);
	while (num_rotates != 0)
	{
		if (num_rotates < 0)
		{
			reverserot(a, 'a');
			num_rotates++;
		}
		else
		{
			rotate(a, 'a');
			num_rotates--;
		}
	}
}
