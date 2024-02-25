/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:46:11 by imurugar          #+#    #+#             */
/*   Updated: 2024/02/25 14:29:58 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

/**
 * It returns the node with the smallest value in the stack
 * 
 * @param a the stack we're sorting
 * 
 * @return The node with the smallest value in the stack.
 */
static t_stack	*get_min_node(t_stack *a)
{
	t_stack	*minimal_node;
	t_stack	*aux;

	aux = a;
	while (aux && aux->idx != 0)
	{
		aux = aux->next;
	}
	minimal_node = aux;
	while (aux)
	{
		if (aux->value < minimal_node->value && aux->idx == 0)
			minimal_node = aux;
		aux = aux->next;
	}
	return (minimal_node);
}

/**
 * It assigns an index to each node in the stack
 * 
 * @param a the stack to assign indexes to
 * @param size the size of the stack
 */
void	assign_indexes(t_stack *a, int size)
{
	int		index;

	index = 1;
	while (index <= size)
	{
		get_min_node(a)->idx = index;
		index++;
	}
}

/**
 * It checks if the stack is sorted
 * 
 * @param a the stack to be checked
 * 
 * @return The function is_sorted() returns 1 
 * if the stack is sorted, 0 otherwise.
 */
int	is_sorted(t_stack *a)
{
	int		sorted;
	t_stack	*aux;

	sorted = 1;
	aux = a;
	while (aux->next && sorted)
	{
		if (aux->idx > aux->next->idx)
			sorted = 0;
		aux = aux->next;
	}
	return (sorted);
}

/**
 * It assigns indexes to the stack, checks if it's sorted, 
 * and if it's not, it sorts it
 * 
 * @param a pointer to the first stack
 * @param b the stack that we're going to use to sort the stack a.
 * @param size the size of the stack
 */
void	sort_stacks(t_stack **a, t_stack **b, int size)
{
	assign_indexes(*a, size);
	if (!is_sorted(*a))
	{
		if (size == 2)
			sa(a);
		if (size == 3)
			sort_three_numbers(a);
		if (size > 3)
			sort_more_than_three(a, b, size);
	}
}
