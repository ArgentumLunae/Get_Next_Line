/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testpredefine.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 16:32:42 by mteerlin      #+#    #+#                 */
/*   Updated: 2020/11/23 14:17:44 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "/home/mteerlin/Documents/Codam/Project_libft/intra-uuid-309e11c1-522a-43e6-8a55-9bd9ae7a9c0f-3375579/libft.h"
#define FD_SIZE 8000

int		get_line(int fd, char **line)
{
	int			ret;
	static char	*s[FD_SIZE];
	char		buff[BUFFER_SIZE + 1];
	char		*temp;

	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		buff[BUFFER_SIZE] = '\0';
		if (line[fd] == NULL)
		{
			line[fd] = ft_strdup(buff);
			if (!line[fd])
			{
				printf("string duplication failed\n");
				return (-1);
			}
		}
		else
		{
			temp = ft_strjoin(line[fd], buff);
			if (!temp)
			{
				printf("joining buffer to line failed\n");
				return (-1);
			}
			free(line[fd])
		}
		if (ft_strchr(line[fd], '\n'))
			break ;
	}
	return ()
}

int			main(void)
{
	int		fd;
	char	**line;

	line = NULL;
	line = (char **)malloc(10 * sizeof(char*));
	if (!line)
		return (0);
	fd = open("test file", O_RDONLY);
	if (fd < 0)
		return (0);
	printf("%d\n", BUFFER_SIZE);
	printf("%d\n", get_line(fd, line));
	printf("%s", line[0]);
	free(line[0]);
	free(line);
	close(fd);
	return (0);
}
