/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:33:37 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/03/21 22:09:52 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_count(char *str, char c)
{
	int		i;
	int		j;
	int		word;

	i = 0;
	j = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != c && j == 0)
		{
			j = 1;
			word++;
		}
		else if (str[i] == c)
		{
			j = 0;
		}
		i++;
	}
	return (word);
}

void	ft_int(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

char	**ft_free(char **p, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(p[i]);
		p[i] = 0;
		i++;
	}
	free(p);
	p = 0;
	return (NULL);
}

char	**fill(char *str, char **p, char c, int num_words)
{
	int	skip;
	int	len;
	int	j;

	ft_int(&skip, &len, &j);
	while (j < num_words)
	{
		if (*str != c && skip == 0)
		{
			skip = 1;
			len = 0;
		}
		else if ((*str == c || *str == '\0') && skip == 1)
		{
			p[j] = ft_substr(str - len, 0, len);
			if (!p[j])
				return (ft_free(p, j));
			skip = 0;
			j++;
		}
		len++;
		str++;
	}
	return (&p[j]);
}

char	**ft_split(char *s, char c)
{
	char	**p;
	char	**tmp;
	int		words;

	if (!s)
		return (NULL);
	words = count_count(s, c);
	p = malloc((words + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	tmp = fill(s, p, c, words);
	if (tmp == NULL)
		return (NULL);
	*tmp = 0;
	return (p);
}
