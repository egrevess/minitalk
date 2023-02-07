/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_outils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:45:09 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/01/13 12:48:49 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
	{
		result = 0;
	}
	if (power == 0)
	{
		result = 1;
	}
	while (power > 0)
	{	
		result = result * nb;
		power--;
	}
	return (result);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
