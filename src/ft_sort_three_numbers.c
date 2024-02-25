/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:26:31 by imurugar          #+#    #+#             */
/*   Updated: 2023/03/12 16:57:54 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

/**
 * If the first element is the largest, rotate the stack. 
 * If the second element is the largest, reverse
 * rotate the stack. If the first element is larger than 
 * the second element, swap the first two elements
 * 
 * @param a the stack to sort
 */
void	sort_three_numbers(t_stack **a)
{
	t_stack	*first;
	t_stack	*seccond;
	t_stack	*third;

	first = *a;
	seccond = (*a)->next;
	third = (*a)->next->next;
	if (first->idx > seccond->idx && first->idx > third->idx)
		rotate(a, 'a');
	else if (first->idx < seccond->idx && seccond->idx > third->idx)
		reverserot(a, 'a');
	first = *a;
	seccond = (*a)->next;
	if (first->idx > seccond->idx)
		sa(a);
}
