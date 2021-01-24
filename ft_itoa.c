/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:45:50 by jfabi             #+#    #+#             */
/*   Updated: 2021/01/23 18:46:38 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nlen(int n)
{
	if (n < 0)
		return (nlen(n / 10 * (-1)) + 2);
	if (n < 10)
		return (1);
	return (nlen(n / 10) + 1);
}

char		*ft_itoa(int n)
{
	char	*dst;
	int		i;

	i = nlen(n);
	dst = (char *)malloc((i + 1) * sizeof(char));
	if (dst == 0)
		return (0);
	dst[i] = 0;
	i--;
	if (n < 0)
	{
		dst[0] = 45;
		dst[i] = (n % 10) * (-1) + 48;
		n = (n / 10) * (-1);
		i--;
	}
	while ((n / 10) > 0)
	{
		dst[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	dst[i] = n + 48;
	return (dst);
}
