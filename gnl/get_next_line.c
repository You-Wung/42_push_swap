/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:33:53 by tyou              #+#    #+#             */
/*   Updated: 2021/06/05 14:36:51 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	rtn(int ret, char **str)
{
	if (ret == -1)
	{
		free(*str);
		return (-1);
	}
	return (ret == 0 ? 0 : 1);
}

static int	app2(char **str, char **line)
{
	if ((*line = ft_strdup(*str)) == NULL)
		return (rtn(-1, str));
	free(*str);
	*str = NULL;
	return (0);
}

static int	strrr(char **str, char **line)
{
	*line = ft_strdup(*str);
	return (1);
}

static int	app(char **str, char **line, int ret)
{
	char	*fre;
	char	*tmp;

	if (ret == -1)
		return (rtn(-1, str));
	if (ft_strstr(*str, "\n") && strrr(str, line))
		return (rtn(0, str));
	tmp = ft_strchr(*str, '\n');
	if (tmp != NULL)
	{
		*tmp = '\0';
		if ((*line = ft_strdup(*str)) == NULL)
			return (rtn(-1, line));
		fre = *str;
		if ((*str = ft_strdup(tmp + 1)) == NULL)
			return (rtn(-1, str));
		free(fre);
	}
	else
		app2(str, line);
	if ((*line)[0] == 0)
		return (0);
	return (rtn(ret, str));
}

int			get_next_line(int fd, char **line)
{
	static char	*str[1024];
	char		*backup;
	char		*buf;
	int			ret;

	ret = 1;
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE < 1 || !line)
		return (-1);
	*line = NULL;
	if (str[fd] == NULL)
		if (((str[fd] = ft_strdup("")) == NULL))
			return (rtn(-1, &str[fd]));
	if (!(buf = (char*)malloc(BUFFER_SIZE + 1)))
		return (rtn(-1, &buf));
	while (ft_strchr(str[fd], '\n') == NULL &&
						(ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		backup = str[fd];
		if ((str[fd] = ft_strjoin(str[fd], buf)) == NULL)
			return (rtn(-1, &str[fd]));
		free(backup);
	}
	free(buf);
	return (app(&str[fd], line, ret));
}
