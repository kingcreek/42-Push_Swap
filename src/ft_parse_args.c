/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:48:18 by imurugar          #+#    #+#             */
/*   Updated: 2023/03/13 20:34:33 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

/**
 * It returns 1 if the character is a space, and 0 otherwise
 * 
 * @param c The character to check.
 * 
 * @return The function is_space() returns 1 if the character is a
 * space, tab, newline, formfeed, vertical tab, or carriage return. 
 * Otherwise, it returns 0.
 */
static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\f'
		|| c == '\v' || c == '\r')
		return (1);
	return (0);
}

/**
 * It takes a string and returns an integer
 * 
 * @param str The string to be converted.
 * 
 * @return the integer value of the string.
 */
int	ft_atoi2(const char *str)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			mod = -1;
		str++;
	}
	if (!*str)
		print_error();
	while (*str)
	{
		if (!ft_isdigit(*str))
			print_error();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		print_error();
	return (mod * i);
}

/**
 * It takes the command line arguments, splits them by spaces, 
 * and then adds each number to a linked list
 * 
 * @param argc the number of arguments passed to the program
 * @param argv the array of strings passed to the program
 * 
 * @return A pointer to a stack.
 */
t_stack	*process(int argc, char **argv, int *size)
{
	t_stack	*a;
	int		i;
	int		j;
	char	**tmp;

	i = 1;
	a = NULL;
	if (argc < 2)
		print_error();
	while (argc > i)
	{
		j = 0;
		tmp = ft_split(argv[i], ' ');
		while (tmp[j])
		{
			add_back(&a, stack_new(ft_atoi2(tmp[j])));
			j++;
			*size += 1;
		}
		freestr(tmp);
		free(tmp);
		i++;
	}
	return (a);
}
