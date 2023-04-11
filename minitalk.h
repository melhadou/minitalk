/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 06:54:56 by melhadou          #+#    #+#             */
/*   Updated: 2023/04/11 02:31:24 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

// Main struct for bits
typedef struct t_bit
{
	int	b1:1;
	int	b2:1;
	int	b3:1;
	int	b4:1;
	int	b5:1;
	int	b6:1;
	int	b7:1;
	int	b8:1;
}	t_bit;

void	sig_handler(int sig);
void	char_to_binary(char c, int pid);
void	print_char(int bit, int *i);
int		ft_atoi(const char *nptr);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
#endif
