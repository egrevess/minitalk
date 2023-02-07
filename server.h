/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:45:14 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/01/13 12:54:43 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "ft_printf.h"

typedef struct s_struct
{
	char	*tab;
	int		index;
	char	buff[10000000];
	int		i;
}	t_struct;

int		ft_iterative_power(int nb, int power);
void	binaire_to_char(void);
void	put_buff(int value);
void	ft_get_pid(void);
int		ft_strlen(char *str);

#endif