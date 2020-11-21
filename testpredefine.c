/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testpredefine.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 16:32:42 by mteerlin      #+#    #+#                 */
/*   Updated: 2020/11/21 15:04:24 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "../Libft/libft.h"

static char	*fill_line(char *thisline, char *buff, int len)
{
	static int	sol = 0;
	char		*temp;

	if (sol != 0)
	{
		temp = malloc((ft_strlen(thisline) + len + 1));
		if (!temp)
			return (NULL);
		ft_strlcpy(temp, thisline, ft_strlen(thisline) + 1);
		ft_strlcat(temp, buff, ft_strlen(thisline) + len + 1);
		free(thisline);
		thisline = temp;
	}
	else
	{
		thisline = malloc(len + 1);
		if (!thisline)
			return (NULL);
		ft_strlcpy(thisline, buff, len + 1);
		sol++;
	}
	return (thisline);
}

int		get_line(int fd, char **line)
{
	static int	linecnt = 0;
	char		buff[BUFFER_SIZE + 1];
	char		*temp;
	int			readcheck;

	readcheck = 1;
	while (readcheck > 0)
	{
		readcheck = read(fd, buff, BUFFER_SIZE);
		buff[BUFFER_SIZE] = '\0';
		temp = ft_strchr(buff, '\n');
		if (temp == NULL)
		{
			write(1, "1\n", 2);
			if (!fill_line(line[linecnt], buff, BUFFER_SIZE))
				return (-1);
		}
		else
		{
			write(1, "1\n", 2);
			*temp = '\0';
			if (!fill_line(line[linecnt], buff, ft_strlen(buff)))
				return (-1);
			return (1);
		}
	}
	return (0);
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
	printf("%s\n", line[0]);
	free(line[0]);
	free(line);
	close(fd);
	return (0);
}
