/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:10:27 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/20 19:24:37 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool is_integer(char *str);
int *split_and_convert(char *str);
t_bool check_value(char *str);
t_bool is_duplicate(t_node *head);

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

t_bool process_arguments(t_stack *stack, int argc, char **argv)
{
	int *numbers;
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		if (!is_integer(argv[i]))
		{
			ft_putstr_fd("Error\nInvalid number\n", 2);
			return (is_false);
		}
		if (!check_value(argv[i]))
		{
			ft_putstr_fd("Error\nInvalid value\n", 2);
			return (is_false);
		}
		numbers = split_and_convert(argv[i]);
		i++;
		j = 0;
		while (numbers[j])
		{
			add_to_list(&stack->head_a, stack, numbers[j]);
			if (is_duplicate(stack->head_a))
			{
				free(numbers);
				return (is_false);
			}
			j++;
		}
		free(numbers);
	}
	return (is_true);
}

t_bool is_integer(char *str)
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
			continue;
		}
		if (*str == '-')
			str++;
		if (!ft_isdigit(*str))
			return (is_false);
		str++;
	}
	return (is_true);
}


int *split_and_convert(char *str)
{
	char **strings;
	int *numbers;
	int len;

	len = 0;
	strings = ft_split(str, ' ');
	while (strings[len])
		len++;
	numbers = malloc(sizeof(int) * (len + 1));
	len = 0;
	while (strings[len])
	{
		numbers[len] = ft_atoi(strings[len]);
		free(strings[len]);
		len++;
	}
	numbers[len] = 0;
	free(strings);
	return (numbers);
}

t_bool is_duplicate(t_node *head)
{
	t_node *current;
	t_node *next_node;

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


t_bool check_value(char *str)
{
	long int value;

	value = atol(str);
	if (value > 2147483647 || value < -2147483648)
	{
		ft_putstr_fd("Error\nValue out of range\n", 2);
		return (is_false);
	}
	return (is_true);
}