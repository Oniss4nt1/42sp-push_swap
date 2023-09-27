/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_medium_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:27:45 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/27 18:44:45 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node *merge(t_node *a, t_node *b);
void partition(t_node *head, t_node **front, t_node **back);

void	merge_sort(t_node *head_ref)
{
	t_node *head;
	t_node *a;
	t_node *b;
	
	head = head_ref;
	if ((head == NULL) || (head->next == NULL))
		return ;

	partition(head, &a, &b);

	merge_sort(&a);
	merge_sort(&b);

	head_ref = merge(a, b);
}

t_node *merge(t_node *a, t_node *b)
{
	t_node *result = NULL;

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

void partition(t_node *head, t_node **front, t_node **back)
{
	t_node *fast;
	t_node *slow;
	

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
