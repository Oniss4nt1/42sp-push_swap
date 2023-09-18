/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:10:27 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/18 18:21:20 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "../libft/src/ft_split.c"
#include "../libft/src/ft_substr.c"
#include "../libft/src/ft_strlen.c"
#include "../libft/src/ft_strdup.c"
#include "../libft/src/ft_atoi.c"


t_bool is_integer(char *str);
int *split_and_convert(char *str);
t_bool is_duplicate(t_node *head, int value);
t_bool check_value(char *str);

t_bool check_numbers(t_node *head, char *str)
{
	int *numbers;
	int len;

	len = 0;
	if (!is_integer(str))
		return (is_false);
		
	if (!check_value(str))
		return (is_false);
	numbers = split_and_convert(str);
	if (!numbers)
		return (is_false);
	while (numbers[len])
	{
		if (is_duplicate(head, numbers[len]))
			return (is_false);
		len++;
	}
	free(numbers);
	return (is_true);
}

t_bool is_integer(char *str)
{
	if (*str == '-')
		str++;
	while ((*str && *str == ' ') || (*str == '\"'))
		str++;

	if (!str)
		return (is_false);
	while (*str)
	{
		if (*str == ' ' || *str == '\"')
		{
			str++;
			continue;
		}
		if (!isdigit(*str))
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
		numbers[len] = atoi(strings[len]);
		free(strings[len]);
		printf("numbers[%d]: %d\n", len, numbers[len]);
		len++;
	}
	numbers[len] = 0;
	free(strings);
	return (numbers);
}

t_bool is_duplicate(t_node *head, int value)
{
	t_node *current;
	
	current = head;
	while (current)
	{
		if (current->value == value)
			return (is_true);
		current = current->next;
	}
	return (is_false);
}

t_bool check_value(char *str)
{
	long int value;

	value = atol(str);
	if (value > 2147483647 || value < -2147483648)
		return (is_false);
	return (is_true);
}

