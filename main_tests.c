/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_tests.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 12:17:59 by mteerlin      #+#    #+#                 */
/*   Updated: 2020/11/27 14:30:40 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

typedef struct	s_fdret
{
	int				fd;
	int				ret;
	struct s_fdret	*next;
}				t_fdret;

t_fdret	*ft_lstnew(int content)
{
	t_fdret	*new;

	new = (t_fdret *)malloc(sizeof(t_fdret));
	if (new == NULL)
		return (NULL);
	new->fd = content;
	new->ret = 1;
	new->next = (void *)NULL;
	return (new);
}

int	main(int argc, char *argv[argc])
{
	char	*line;

	if (argc < 2)
	{
		printf("No file given.");
		return (0);
	}
	if (argc >= 2)
	{
		int i;
		t_fdret *list;
		t_fdret *temp;

		list = ft_lstnew(open(argv[1], O_RDONLY));
		temp = list;
		i = 2;
		while (i < argc)
		{
			temp->next = ft_lstnew(open(argv[i], O_RDONLY));
			temp = temp->next;
			i++;
		}
		temp = list;
		while (temp != NULL)
		{
			while (temp->ret > 0)
			{
				temp->ret = get_next_line(temp->fd, &line);
				if (line)
				{
					printf("%s\n", line);
				}
				free(line);
				line = NULL;
			}
			printf("%d", temp->ret);
			printf("\n\n");
			temp = temp->next;
		}
		while (list != NULL)
		{
			close(list->fd);
			temp = list->next;
			free(list);
			list = temp;
		}
		return (0);
	}
	return (0);
}
