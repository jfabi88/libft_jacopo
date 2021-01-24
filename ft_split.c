/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:10:27 by jfabi             #+#    #+#             */
/*   Updated: 2021/01/24 15:13:26 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**copy(char const *s, char c, int col, char **ret)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	while (s[j] != 0 && s[j] == c)
		j++;
	if (s[j] == 0)
	{
		ret[col] = 0;
		return (ret);
	}
	while (s[i + j] != 0 && s[i + j] != c)
	{
		ret[col][i] = s[i + j];
		i++;
	}
	ret[col][i] = 0;
	ret = copy(s + i + j, c, col + 1, ret);
	return (ret);
}

static char		**len_c(char const *s, char c, int col, char **ret)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	if (s[i] == 0)
		return (ret);
	while (s[j] != 0 && s[j] == c)
		j++;
	while (s[j + i] != 0 && s[j + i] != c)
		i++;
	ret[col] = (char *)malloc(sizeof(char) * (i + 1));
	if (ret[col] == 0)
		return (ret);
	ret = len_c(s + i + j, c, col + 1, ret);
	if (ret[col + 1] == 0)
	{
		free(ret[col]);
		return (ret);
	}
	return (ret);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		cont;
	char	**ret;

	i = 0;
	cont = 0;
	if (s == 0)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			cont++;
		i++;
	}
	ret = (char**)malloc(sizeof(char*) * (cont + 1));
	if (ret == 0)
		return (0);
	ret = len_c(s, c, 0, ret);
	if (ret == 0)
	{
		free(ret);
		return (0);
	}
	ret = copy(s, c, 0, ret);
	return (ret);
}
