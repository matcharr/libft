/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023-11-15 10:00:00 by mathis            #+#    #+#             */
/*   Updated: 2023-11-15 10:00:00 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	print_result(int result, char *test_name)
{
	if (result)
		printf("✅ %s: OK\n", test_name);
	else
		printf("❌ %s: KO\n", test_name);
}

int	main(void)
{
	// Test ft_strlen
	printf("Testing ft_strlen:\n");
	print_result(ft_strlen("Hello") == 5, "ft_strlen basic");
	print_result(ft_strlen("") == 0, "ft_strlen empty");
	
	// Test ft_strchr
	printf("\nTesting ft_strchr:\n");
	print_result(ft_strchr("Hello", 'e') == strchr("Hello", 'e'), "ft_strchr found");
	print_result(ft_strchr("Hello", 'z') == strchr("Hello", 'z'), "ft_strchr not found");
	
	// Test ft_strdup
	printf("\nTesting ft_strdup:\n");
	char *dup = ft_strdup("Test string");
	print_result(strcmp(dup, "Test string") == 0, "ft_strdup");
	free(dup);
	
	// Test ft_split
	printf("\nTesting ft_split:\n");
	char **split = ft_split("hello,world,42", ',');
	print_result(strcmp(split[0], "hello") == 0, "ft_split[0]");
	print_result(strcmp(split[1], "world") == 0, "ft_split[1]");
	print_result(strcmp(split[2], "42") == 0, "ft_split[2]");
	print_result(split[3] == NULL, "ft_split[3] NULL");
	for (int i = 0; split[i]; i++)
		free(split[i]);
	free(split);
	
	// Test linked list functions
	printf("\nTesting linked list functions:\n");
	t_list *lst = NULL;
	t_list *node1 = ft_lstnew(ft_strdup("First"));
	t_list *node2 = ft_lstnew(ft_strdup("Second"));
	
	ft_lstadd_front(&lst, node2);
	ft_lstadd_front(&lst, node1);
	
	print_result(ft_lstsize(lst) == 2, "ft_lstsize");
	print_result(strcmp(lst->content, "First") == 0, "ft_lstadd_front[0]");
	print_result(strcmp(lst->next->content, "Second") == 0, "ft_lstadd_front[1]");
	
	// Clean up linked list
	ft_lstclear(&lst, free);
	
	printf("\nAll tests completed!\n");
	return (0);
}