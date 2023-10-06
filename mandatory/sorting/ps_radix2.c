/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:16:20 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/05 18:33:43 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	add_index_to_list(t_stack *stack, int *array);
static int	get_max_bits(t_node *head);
void		radix_sort(t_stack *stack);

void	sort_index(t_stack *stack)
{
	int		i;
	int		count;
	int		*array;
	t_node	*current;
	t_node	*runner;

	array = (int *)malloc(sizeof(int) * stack->size_a);
	if (!array)
		exit(1);
	i = 0;
	current = stack->head_a;
	while (current)
	{
		count = 0;
		runner = stack->head_a;
		while (runner)
		{
			if (current->value > runner->value)
				count++;
			runner = runner->next;
		}
		array[i++] = count;
		current = current->next;
	}
	add_index_to_list(stack, array);
}

static void	add_index_to_list(t_stack *stack, int *array)
{
	int		i;
	t_node	*current;

	i = 0;
	current = stack->head_a;
	while (current)
	{
		current->value = array[i++];
		current = current->next;
	}
	free(array);
}

static int	get_max_bits(t_node *head)
{
	int		max;
	int		bits;
	t_node	*current;

	max = head->value;
	current = head;
	bits = 0;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	while ((max >> bits) > 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *stack)
{
	int		i;
	int		j;
	int		max_bits;
	int		size;
	t_node	*current;

	sort_index(stack);
	max_bits = get_max_bits(stack->head_a);
	size = stack->size_a;
	i = 0;
	while (i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			current = stack->head_a;
			if (((current->value >> i) & 1) == 1)
				rotate(&stack->head_a, 'a');
			else
				push_a_to_b(stack);
		}
		while (stack->size_b != 0)
			push_b_to_a(stack);
		i++;
	}
}
