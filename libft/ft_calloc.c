/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:05:07 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/13 14:29:08 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if (nmemb == 0 || size == 0)
		return (ft_strdup(""));
	if (nmemb != 0 && SIZE_MAX / nmemb < size)
		return (NULL);
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	ft_memset(arr, 0, nmemb * size);
	return (arr);
}
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include "libft.h"

// int main(void)
// {
// 	int *a = ft_calloc(5, sizeof(int));
// 	int *b = calloc(5, sizeof(int));
// 	printf("ft_calloc == calloc: %d\n", memcmp(a, b, 5 * sizeof(int)) == 0);
// 	free(a);
// 	free(b);
// 	return 0;
// }