/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_tests.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 12:17:59 by mteerlin      #+#    #+#                 */
/*   Updated: 2020/11/28 18:20:38 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

typedef struct	s_fdlst
{
	int		fd;
	int		ret;
	s_fdlst	next;
}				t_fdlst;

int	main(int argc, char *argv[argc])
{
	size_t	cnt;
	t_fdlst	*start;
	t_fdlst	*temp;
	char	*line;

	line = NULL;
	if (argc < 2)
	{
		printf("\033[0;31m");
		printf("No file path given.\n");
		return (0);
	}
	else
	{
		start = (t_fdlst *)malloc(sizeof(t_fdlst));
		if (!start)
			return (NULL);
		new->fd = open(argv[1], O_RDONLY);
		new->ret = 1;
		new->next = NULL;
		temp = start;
		cnt = 2;
		while (cnt < argc)
		{
			temp->next = (t_fdlst *)malloc(sizeof(t_fdlst));
			temp = temp->next;
			temp->fd = open(argv[cnt], O_RDONLY);
			temp->ret = 1;
			temp->next = NULL;
		}
	}
	return (0);
}
