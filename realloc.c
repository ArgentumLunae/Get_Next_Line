/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   realloc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 12:04:07 by mteerlin      #+#    #+#                 */
/*   Updated: 2020/11/23 12:50:01 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "/home/mteerlin/Documents/Codam/Project_libft/intra-uuid-309e11c1-522a-43e6-8a55-9bd9ae7a9c0f-3375579/libft.h"

void	*ft_realloc(void const *line, int addlen, int *sol)
{
	char *temp;

	temp = NULL;
	if (sol)
	{
		line = malloc(addlen * sizeof(char));
		if (!line)
			return (NULL);
		*sol = 0;
	}
	else
	{
		temp = malloc((ft_strlen(line) + addlen + 1) * sizeof(char));
		if (!temp)
			return (NULL);
		free((void *)line);
		line = temp;
	}
	return ((void *)line);
}
