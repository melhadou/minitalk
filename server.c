/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 06:54:49 by melhadou          #+#    #+#             */
/*   Updated: 2023/05/23 11:42:25 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_bit	g_char_bits;

void	print_char(int bit, int *i)
{
	if (*i == 1)
		g_char_bits.b1 = bit;
	else if (*i == 2)
		g_char_bits.b2 = bit;
	else if (*i == 3)
		g_char_bits.b3 = bit;
	else if (*i == 4)
		g_char_bits.b4 = bit;
	else if (*i == 5)
		g_char_bits.b5 = bit;
	else if (*i == 6)
		g_char_bits.b6 = bit;
	else if (*i == 7)
		g_char_bits.b7 = bit;
	else if (*i == 8)
	{
		g_char_bits.b8 = bit;
		write(1, (unsigned char *)&g_char_bits, 1);
		*i = 0;
	}
}

void	sig_handler(int sig)
{
	static int	i;

	if (!i)
		i = 1;
	if (sig == SIGUSR1)
	{	
		print_char(0, &i);
		i++;
	}
	else if (sig == SIGUSR2)
	{	
		print_char(1, &i);
		i++;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_handler = &sig_handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "PID == ", 7);
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
