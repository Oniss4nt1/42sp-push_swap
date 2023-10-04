/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:10:27 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/04 16:24:19 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool		is_integer(char *str);
t_numbers	split_and_convert(char *str);
t_bool		check_value(int num);
t_bool		is_duplicate(t_node *head);

t_bool	is_sorted(t_node *head)
{
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (is_false);
		head = head->next;
	}
	return (is_true);
}

t_bool	process_arguments(t_stack *stack, int argc, char **argv)
{
	int			i;
	int			j;
	t_numbers	array;

	i = 1;
	while (i < argc)
	{
		if (!is_integer(argv[i]))
		{
			ft_putstr_fd("Error\nNot an integer\n", 2);
			return (is_false);
		}
		array = split_and_convert(argv[i]);
		i++;
		j = 0;
		while (j < array.size)
		{
			add_to_list(&stack->head_a, stack, array.num[j]);
			if (is_duplicate(stack->head_a))
			{
				free(array.num);
				return (is_false);
			}
			j++;
		}
		free(array.num);
	}
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

t_numbers	split_and_convert(char *str)
{
	char		**strings;
	t_numbers	array;
	int			i;

	i = 0;
	strings = ft_split(str, ' ');
	while (strings[i])
		i++;
	array.size = i;
	array.num = malloc(sizeof(long int) * (i + 1));
	i = 0;
	while (strings[i])
	{
		array.num[i] = ft_atol(strings[i]);
		if (array.num[i] > INT_MAX || array.num[i] < INT_MIN)
		{
			ft_putstr_fd("Error\nValue out of range\n", 2);
			free(strings);
			exit(1);
		}
		free(strings[i]);
		i++;
	}
	free(strings);
	return (array);
}

t_bool	is_duplicate(t_node *head)
{
	t_node	*current;
	t_node	*next_node;

	current = head;
	while (current)
	{
		next_node = current->next;
		while (next_node)
		{
			if (current->value == next_node->value)
			{
				ft_putstr_fd("Error\nDuplicate number\n", 2);
				return (is_true);
			}
			next_node = next_node->next;
		}
		current = current->next;
	}
	return (is_false);
}

t_bool	check_value(int num)
{
	if (num > INT_MAX || num < INT_MIN)
	{
		ft_putstr_fd("Error\nValue out of range\n", 2);
		return (is_true);
	}
	return (is_false);
}
