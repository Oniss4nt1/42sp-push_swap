/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:10:27 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/05 16:56:22 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool		is_integer(char *str);
t_numbers	split_and_convert(char *str, t_stack *stack);
t_bool		check_value(char *str);
t_bool		process_array(t_stack *stack, t_numbers array);

/**
 * Function: process_arguments
 * -----------------
 * This is the main function to process the arguments. It checks if the
 * arguments are valid and then adds them to the list.
 * 
 * 
 * @param: *stack: pointer to the stack.
 * @param: argc: number of arguments.
 * @param: **argv: pointer to the arguments.
 *
 * @return: This is a t_bool function, so it returns true or false.
 *
 */

t_bool	process_arguments(t_stack *stack, int argc, char **argv)
{
	t_numbers	array;
	int			i;

	i = 1;
	while (i < argc)
	{
		if (!is_integer(argv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (is_false);
		}
		array = split_and_convert(argv[i], stack);
		i++;
		if (!process_array(stack, array))
			return (is_false);
	}
	return (is_true);
}

/**
 * Function: is_integer
 * -----------------
 * This function checks if the string passed as argument is a valid argument.
 * 
 * @param: *str: pointer to the string.
 *
 * @return: This is a t_bool function, so it returns true if the string is
 * a valid argument and false if it is not.
 *
 */

t_bool	is_integer(char *str)
{
	if (*str == '-')
		str++;
	while ((*str && *str == ' ') || (*str == '\"'))
		str++;
	if (!str || !*str)
		return (is_false);
	while (*str)
	{
		if (*str == ' ' || *str == '\"')
		{
			str++;
			continue ;
		}
		if (*str == '-')
			str++;
		if (!ft_isdigit(*str))
			return (is_false);
		str++;
	}
	return (is_true);
}

/**
 * Function: split_and_convert
 * -----------------
 * After verifying that the string is a valid argument, this function splits
 * the string into an array of strings and then converts each string into an
 * integer, storing them in a struct of type t_numbers. 
 * 
 * @param: *str: pointer to the string.
 * @param: *stack: pointer to the stack.
 * @var: **strings: pointer to the array of strings.
 * @var: array: struct of type t_numbers, containing the array of integers.
 * @var: temp: temporary variable to store the converted string.
 * @var: i: counter variable.
 *
 * @return: This is a t_numbers function, so it returns tje struct containing
 * the array of integers.
 *
 */

t_numbers	split_and_convert(char *str, t_stack *stack)
{
	char		**strings;
	t_numbers	array;
	long int	temp;
	int			i;

	i = 0;
	strings = ft_split(str, ' ');
	while (strings[i])
		i++;
	array.size = i;
	array.num = malloc(sizeof(int) * (i + 1));
	i = 0;
	while (strings[i])
	{
		temp = ft_atol(strings[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			free_error(stack, &array, strings, i);
		array.num[i] = (int)temp;
		free(strings[i]);
		i++;
	}
	free(strings);
	return (array);
}

/**
 * Function: process_array
 * -----------------
 * This is the last function to process the arguments. It adds the integers
 * to the list and checks if there are duplicates.
 *  
 * @param: *stack: pointer to the stack.
 * @param: array: struct of type t_numbers, containing the array of integers.
 * @param: i: counter variable.
 *
 * @return: This is a t_bool function, so it returns true or false.
 *
 */

t_bool	process_array(t_stack *stack, t_numbers array)
{
	int	i;

	i = 0;
	while (i < array.size)
	{
		add_to_list(&stack->head_a, stack, array.num[i]);
		if (is_duplicate(stack->head_a))
		{
			free(array.num);
			return (is_false);
		}
		i++;
	}
	free(array.num);
	return (is_true);
}

