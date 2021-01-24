/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:49:39 by jfabi             #+#    #+#             */
/*   Updated: 2021/01/24 10:56:08 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	temp1;
	unsigned char	temp2;

	i = 0;
	while (s1[i] == s2[i] && i < (n - 1) && s1[i] != 0)
		i++;
	temp1 = s1[i];
	temp2 = s2[i];
	return (temp1 - temp2);
}
