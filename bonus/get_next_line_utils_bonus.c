/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:23:09 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/22 14:00:54 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(const char *s1, char *s2)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!s1 && !s2)
		return (NULL);
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	while (s1 && s1[i])
		res[i++] = s1[len++];
	len = ft_strlen(s1);
	i = 0;
	while (s2 && s2[i])
		res[len++] = s2[i++];
	res[len] = '\0';
	free((char *)s1);
	s1 = NULL;
	return (res);
}

char	*ft_substr(const char *s, int start, int len)
{
	int			i;
	int			len_s;
	char		*res;

	i = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(&s[start]);
	if (len_s < len)
		len = len_s;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	s = s + start;
	while (s[i] != '\0' && len > 0)
	{
		res[i] = s[i];
		i++;
		len--;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strdup(char *str)
{
	char	*str2;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
		return (NULL);
	while (str[i])
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
