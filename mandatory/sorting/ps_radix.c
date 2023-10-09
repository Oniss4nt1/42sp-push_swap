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

/**
 * Function: sort_index
 * -----------------
 * This function sorts the list a by index. It creates an array with the size
 * of the list and then it traverses the list and compares the value of the
 * current node with the value of the next node. If the value of the current
 * node is greater than the value of the next node, it increments the counter.
 * This is made for each node of the list for obtain the index of each node,
 * which is the number of nodes that are smaller than the current node. Then,
 * it calls the function add_index_to_list, which adds the index to each node
 * of the list.
 * 
 * @param: *stack: pointer to the stack.
 * @var: *array: pointer to the array.
 * @var: i: counter used to traverse the array.
 * @var: count: counter used to obtain the index of each node.
 * @var: *current: pointer to the current node, used to traverse the list.
 * @var: *runner: pointer to the runner node, used to traverse the list.
 * 
 * @return: This is a void function, so it does not return a value.
 *
 */

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

/**
 * Function: add_index_to_list
 * -----------------
 * This function adds the index to each node of the list. It traverses the list
 * and adds the value of the array to the value of the current node, changing
 * the value of the current node to the index of the node. Then, it frees the
 * array.
 * 
 * @param: *stack: pointer to the stack.
 * @var: *array: pointer to the array.
 * @var: i: counter used to traverse the array.
 * @var: *current: pointer to the current node, used to traverse the list.
 * 
 * @return: This is a void function, so it does not return a value.
 *
 */

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

/**
 * Function: get_max_bits
 * -----------------
 * This function gets the maximum number of bits of the list. It traverses the
 * list and compares the value of the current node with the value of the next
 * node. If the value of the current node is greater than the value of the next
 * node, it changes the value of the variable max to the value of the current
 * node. Then, it shifts the value of max to the right until it is equal to 0
 * and increments the counter bits. Finally, it returns the value of bits.
 * 
 * @param: *head: pointer to the head of the list.
 * @var: max: variable used to store the maximum value of the list.
 * @var: bits: counter used to store the number of bits.
 * @var: *current: pointer to the current node, used to traverse the list.
 * 
 * @return: This is a void function, so it does not return a value.
 *
 */

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

/**
 * Function: radix_sort
 * -----------------
 * This function sorts the list a by radix sort. It calls the function
 * sort_index, which sorts the list by index, after that, it gets the maximum
 * number of bits of the list and stores it in the variable max_bits. Then, it
 * iterates from 0 to max_bits. Inside the loop, it iterates from 0 to the size
 * of the list. Inside the loop, it gets the value of the current node and
 * compares it with 1, if the result of the bitwise operation is 1, it calls
 * the function rotate, which rotates the list a. If the result of the bitwise
 * operation is 0, it calls the function push_a_to_b, which pushes the node
 * to the list b. After that, it iterates from 0 to the size of the list b and
 * calls the function push_b_to_a, which pushes the node to the list a. Finally,
 * it increments the counter i and repeats the process until i is equal to
 * max_bits.
 * 
 * @param: *stack: pointer to the stack.
 * @var: i: counter used to loop from 0 to max_bits.
 * @var: j: counter used to loop from 0 to the size of the list.
 * @var: max_bits: variable used to store the maximum number of bits of the list.
 * @var: size: variable used to store the size of the list.
 * @var: *current: pointer to the current node, used to traverse the list.
 * 
 * @return: This is a void function, so it does not return a value.
 *
 */

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
