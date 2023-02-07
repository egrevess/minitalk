/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_outils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:46:02 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/01/13 12:53:55 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_put_zero(char *str)
{
	int		i;
	int		len;
	int		zero;
	char	*dst;

	len = ft_strlen(str);
	dst = malloc(sizeof(char) * 9);
	if (!dst)
		return (NULL);
	i = 0;
	zero = 8 - len;
	while (i < zero)
	{
		dst[i] = '0';
		i++;
	}
	while (str[i - zero])
	{
		dst[i] = str[i - zero];
		i++;
	}
	dst[i] = '\0';
	free(str);
	return (dst);
}

int	ft_atoi(const char *str)
{
	long int	i;
	size_t		nb;
	long int	neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1 * neg;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = str[i] + (nb * 10) - 48;
		i++;
	}
	if (nb >= 9223372036854775807 && neg == 1)
		nb = -1;
	else if (nb > 9223372036854775807 && neg == -1)
		nb = 0;
	return (nb * neg);
}

int	ft_free(t_struct *var, int index)
{
	int	i;

	i = 0;
	while (i <= index)
	{
		free(var->tab[i]);
		i++;
	}
	free(var->tab);
	return (0);
}
