/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:26:10 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/05 18:31:54 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Function: sorting
 * -----------------
 * This function is used to see what sorting algorithm to use. If the number of
 * numbers to sort is between 2 and 15, it uses the sort_short function, if it
 * is greater than 15, it uses the radix_sort function.
 * 
 * @param: *stack: pointer to the stack.
 * @param: argc: number of arguments.
 * 
 * @return: This is a void function, so it does not return a value.
 *
 */

void	sorting(t_stack *stack, int argc)
{
	if (argc >= 2 && argc <= 15)
		sort_short(stack);
	else
		radix_sort(stack);
}
