/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:04:04 by a          #+#    #+#             */
/*   Updated: 2022/01/25 16:23:58 by a         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_hld(int fd, char *lft_str)
{
	char	*buff;
	int		rd_byt;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (0);
	rd_byt = 1;
	while (!ft_strchr(lft_str, '\n') && rd_byt != 0)
	{
		rd_byt = read(fd, buff, BUFFER_SIZE);
		if (rd_byt == -1)
		{
			free(buff);
			return (0);
		}
		buff[rd_byt] = '\0';
		lft_str = ft_strjoin(lft_str, buff);
	}
	free(buff);
	return (lft_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*lft_str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	lft_str[fd] = ft_read_hld(fd, lft_str[fd]);
	if (!lft_str[fd])
		return (0);
	line = ft_line(lft_str[fd]);
	lft_str[fd] = ft_del_bff(lft_str[fd]);
	return (line);
}
