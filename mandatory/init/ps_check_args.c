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
