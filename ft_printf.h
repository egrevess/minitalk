/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:05:58 by egrevess          #+#    #+#             */
/*   Updated: 2022/10/18 14:06:53 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(int c, int *size);
void	ft_putstr(char *str, int *size);
void	ft_put_addresshexa(void *s, int *size);
void	ft_putnbr_base(unsigned long s, int *size, unsigned int base, char c);
void	ft_putnbr(int nb, int *size);

#endif
