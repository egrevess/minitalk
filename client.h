/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:45:56 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/01/13 13:23:02 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_struct
{
	char	**tab;
}			t_struct;

char	*ft_put_zero(char *str);
void	ft_putnbr_base(int nb, int base, char *tab, int index);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
int		ft_free(t_struct *var, int index);

#endif