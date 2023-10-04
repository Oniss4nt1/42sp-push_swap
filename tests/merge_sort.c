/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:59:03 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/04 16:42:10 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*merge(t_node *a, t_node *b);
void	partition(t_node *head, t_node **front, t_node **back);
void	print_list(t_node *head);

t_node	*merge_sort(t_node *head)
{
	t_node	*a;
	t_node	*b;

	if ((head == NULL) || (head->next == NULL))
		return (head);
	partition(head, &a, &b);
	a = merge_sort(a);
	b = merge_sort(b);
	return (merge(a, b));
}

t_node	*merge(t_node *a, t_node *b)
{
	t_node	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->value <= b->value)
	{
		result = a;
		result->next = merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge(a, b->next);
	}
	return (result);
}

void	partition(t_node *head, t_node **front, t_node **back)
{
	t_node	*fast;
	t_node	*slow;

	if (head == NULL || head->next == NULL)
	{
		*front = head;
		*back = NULL;
	}
	else
	{
		slow = head;
		fast = head->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front = head;
		*back = slow->next;
		slow->next = NULL;
	}
}

void	print_list(t_node *head)
{
	t_node	*temp;

	temp = head;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->value);
		temp = temp->next;
	}
	ft_printf("\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;

	if (argc < 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		return (1);
	}
	stack = init_stack();
	if (!process_arguments(stack, argc, argv))
	{
		free_stack(stack);
		return (1);
	}
	if (is_sorted(stack->head_a))
	{
		ft_putstr_fd("Error\nList is already sorted\n", 2);
		free_stack(stack);
		return (1);
	}
	stack->head_a = merge_sort(stack->head_a);
	print_list(stack->head_a);
	ft_printf("Moves: %d\n", stack->moves);
	free_stack(stack);
	return (0);
}
