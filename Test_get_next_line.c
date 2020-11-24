/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Test_get_next_line.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 14:19:08 by mteerlin      #+#    #+#                 */
/*   Updated: 2020/11/24 13:02:21 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../Codam_libft/libft.h"

int	test_get_next_line(int fd, char **line)
{
	int			ret;
	int			len;
	static char	*s[2000];
	char		buff[BUFFER_SIZE + 1];
	char		*temp;

	if (fd < 0 || line == NULL)
		return (-1);
	if (s[fd] != NULL && ft_strchr(s[fd], '\n'))
		ret = 0;
	else
		ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		buff[ret] = '\0';
		if (s[fd] == NULL)
		{
			s[fd] = ft_strdup(buff);
			if (s[fd] == NULL)
				return (-1);
		}
		else
		{
			temp = ft_strjoin(s[fd], buff);
			if (temp == NULL)
				return (-1);
			free(s[fd]);
			s[fd] = temp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
		ret = read(fd, buff, BUFFER_SIZE);
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s[fd] == NULL)
		return (0);
	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_substr(s[fd], 0, len);
		temp = ft_strdup(&(s[fd][len + 1]));
		free(s[fd]);
		s[fd] = temp;
	}
	else
	{
		*line = ft_strdup(s[fd]);
		free(s[fd]);
		s[fd] = NULL;
	}
	return (1);
}
