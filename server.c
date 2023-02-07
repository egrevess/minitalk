/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:44:39 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/01/13 13:39:55 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_struct	g_var;

void	ft_get_pid(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	ft_printf("%d\n", server_pid);
}

void	put_buff(int value)
{
	char	c;
	int		len;

	c = value;
	len = 0;
	if (c == '\0')
	{
		len = ft_strlen(g_var.buff);
		write(1, &g_var.buff, g_var.i);
		g_var.buff[0] = '\0';
		g_var.i = 0;
	}
	else
		g_var.buff[g_var.i] = c;
	g_var.i++;
}

void	binaire_to_char(void)
{
	int	i;
	int	power;
	int	value;

	i = 7;
	value = 0;
	power = 0;
	while (i >= 0)
	{
		if (g_var.tab[i] == '1')
		{
			value = value + ft_iterative_power(2, power);
		}
		power++;
		i--;
	}
	put_buff(value);
}

void	execut(int sig)
{
	if (sig == SIGUSR2)
	{
		g_var.tab[g_var.index] = '1';
	}
	else if (sig == SIGUSR1)
	{
		g_var.tab[g_var.index] = '0';
	}
	if (g_var.index == 7)
	{
		g_var.tab[g_var.index + 1] = '\0';
		g_var.index = -1;
		binaire_to_char();
	}
	g_var.index = g_var.index + 1;
}

int	main(int ac, char **av)
{
	(void) av;
	if (ac == 1)
	{
		g_var.index = 0;
		g_var.i = 0;
		g_var.tab = malloc(sizeof(*g_var.tab) * 9);
		if (!g_var.tab)
		{
			free(g_var.tab);
			return (0);
		}
		ft_get_pid();
		signal(SIGUSR1, execut);
		signal(SIGUSR2, execut);
		while (1)
		{
			pause();
		}
		free(g_var.tab);
	}
	return (0);
}
