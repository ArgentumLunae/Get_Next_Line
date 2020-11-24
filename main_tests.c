/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_tests.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 12:17:59 by mteerlin      #+#    #+#                 */
/*   Updated: 2020/11/23 18:04:30 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "../Codam_libft/libft.h"

int	get_next_line(int fd, char **line);

int	main(void)
{
	char *line;
	int ret1;
	int	ret2;
	int fd1;
	int fd2;

	fd1 = open("/home/mteerlin/Documents/Codam/Project_Get_Next_Line/Get_Next_Line/test file", O_RDONLY);
	fd2 = open("/home/mteerlin/Documents/Codam/Project_Get_Next_Line/Get_Next_Line/ThisHasTextInIt", O_RDONLY);
	ret1 = 1;
	ret2 = 1;
	line = NULL;
	while (ret1 || ret2)
	{
		ret1 = get_next_line(fd1, &line);
		if (ret1 > 0)
		{
			ft_putendl_fd(line, 1);
			free(line);
			line = NULL;
		}
		ret2 = get_next_line(fd2, &line);
		if (ret2 > 0)
		{
			ft_putendl_fd(line, 1);
			free(line);
			line = NULL;
		}
	}
	return (0);
}
