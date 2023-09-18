/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:55:27 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/18 17:33:31 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include "../libft/src/ft_putstr_fd.c"

//Function


int main(int argc, char *argv[])
{
	int i;

	i = 1;
	if (argc < 2)
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		return (0);
	}
	while (i < argc)
	{
		printf("Check numbers for %s: %d\n", argv[i], check_numbers(NULL, argv[i]));
		if (!check_numbers(NULL, argv[i]))
		{
			printf("Error\n");
			return (0);
		}
		i++;
	}
	// free(argv);
	return (0);
}

// int main(void)
// {
// 	char *test1 = "123";
// 	char *test2 = "\"123\"";
// 	char *test3 = "abc";
// 	char *test4 = "123 456";
// 	char *test5 = "\"123 456\"";
// 	char *test6 = "123 4a56 789";
// 	char *test7 = "\"123 4a56 789\"";

// 	printf("Check numbers for %s: %d\n", test1, check_numbers(NULL, test1));
// 	printf("Check numbers for %s: %d\n", test2, check_numbers(NULL, test2));
// 	printf("Check numbers for %s: %d\n", test3, check_numbers(NULL, test3));
// 	printf("Check numbers for %s: %d\n", test4, check_numbers(NULL, test4));
// 	printf("Check numbers for %s: %d\n", test5, check_numbers(NULL, test5));
// 	printf("Check numbers for %s: %d\n", test6, check_numbers(NULL, test6));
// 	printf("Check numbers for %s: %d\n", test7, check_numbers(NULL, test7));
// 	return (0);
// }
