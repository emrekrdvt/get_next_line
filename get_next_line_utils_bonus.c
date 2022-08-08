/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 23:10:25 by a          #+#    #+#             */
/*   Updated: 2022/01/13 17:05:46 by a         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *lft_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!lft_str)
	{
		lft_str = malloc(sizeof(char) * 1);
		lft_str[0] = '\0';
	}
	if (!lft_str || !buff)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(lft_str) + ft_strlen(buff) + 1));
	if (!str)
		return (0);
	i = -1;
	while (lft_str[++i] != '\0')
		str[i] = lft_str[i];
	j = 0;
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[i] = 0;
	free(lft_str);
	return (str);
}

char	*ft_line(char *lft_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!lft_str[i])
		return (0);
	while (lft_str[i] && lft_str[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	i = 0;
	while (lft_str[i] && lft_str[i] != '\n')
	{
		str[i] = lft_str[i];
		i++;
	}
	if (lft_str[i] == '\n')
	{
		str[i] = lft_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_del_bff(char *lft_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (lft_str[i] && lft_str[i] != '\n')
		i++;
	if (!lft_str[i])
	{
		free(lft_str);
		return (0);
	}
	str = malloc(sizeof(char) * (ft_strlen(lft_str) - i + 1));
	if (!str)
		return (0);
	j = 0;
	i++;
	while (lft_str[i])
		str[j++] = lft_str[i++];
	str[j] = 0;
	free(lft_str);
	return (str);
}
