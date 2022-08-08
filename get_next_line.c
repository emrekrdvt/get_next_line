/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:04:04 by a          #+#    #+#             */
/*   Updated: 2022/04/04 12:12:45 by a         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*lft_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	lft_str = ft_read_hld(fd, lft_str);
	if (!lft_str)
		return (0);
	line = ft_line(lft_str);
	lft_str = ft_del_bff(lft_str);
	return (line);
}
/*
int main()
{
    int fd;
	fd = open("text.txt", O_RDWR, 777);
	char *line = get_next_line(fd);
	while(line != 0)
	{	
		printf("%s", line);
		line = get_next_line(fd);
	}
}*/
/*
int main()
{
	int fd;
	char *line;
	fd = open("text.txt", O_RDWR, 777);
	line = get_next_line(fd);
	while(line != 0)
	{	
		printf("%s", line);
		line = get_next_line(fd);
	}
}*/
/*
int main()
{
	int fd;
	int kontrol = 0;
	char *kelime;
	fd = open("text.txt", O_CREAT | O_RDWR, 0777);
	kelime = get_next_line(fd);
	while (kontrol)
	{
		if (kelime)
			printf("%s", kelime);
		else
			kontrol  = 0;
	}
}
*/
