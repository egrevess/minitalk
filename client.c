/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:46:07 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/01/13 13:42:57 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_send(t_struct *var, int av1)
{
	int	i;
	int	j;

	i = 0;
	while (var->tab[i])
	{
		j = 0;
		while (var->tab[i][j])
		{
			if (var->tab[i][j] == '0')
				kill(av1, SIGUSR1);
			else if (var->tab[i][j] == '1')
				kill(av1, SIGUSR2);
			j++;
			usleep(50);
		}
		i++;
	}
	i = 0;
	while (i < 8)
	{
		kill(av1, SIGUSR1);
		i++;
		usleep(50);
	}
}

int	len(int nb)
{
	int	result;

	result = 0;
	while (nb != 0)
	{
		nb = nb / 2;
		result++;
	}
	return (result);
}

void	ft_putnbr_base(int nb, int base, char *tab, int index)
{
	if (nb >= base)
	{
		ft_putnbr_base(nb / base, base, tab, index - 1);
		nb = nb % base;
	}
	if (nb < base)
	{
		tab[index] = nb + 48;
		tab[index + 1] = '\0';
	}
}

int	main(int ac, char **av)
{
	int			i;
	t_struct	var;

	i = 0;
	if (ac == 3)
	{
		var.tab = malloc(sizeof(*var.tab) * (ft_strlen(av[2]) + 1));
		if (!var.tab)
			return (0);
		while (av[2][i])
		{
			var.tab[i] = malloc(sizeof(*var.tab[i]) * 9);
			if (!var.tab[i])
				return (ft_free(&var, i));
			ft_putnbr_base(av[2][i], 2, var.tab[i], len(av[2][i]) - 1);
			if (ft_strlen(var.tab[i]) <= 8)
				var.tab[i] = ft_put_zero(var.tab[i]);
			i++;
		}
		var.tab[i] = NULL;
		if (ft_atoi(av[1]) > 0)
			ft_send(&var, ft_atoi(av[1]));
		ft_free(&var, ft_strlen(av[2]) - 1);
	}
	return (0);
}
