/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 06:54:44 by melhadou          #+#    #+#             */
/*   Updated: 2023/05/27 13:37:34 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig(int pid, int val)
{
	usleep(250);
	if (val)
	{
		kill(pid, SIGUSR2);
		return ;
	}
	kill(pid, SIGUSR1);
}

void	char_to_binary(char c, int pid)
{
	t_bit	bits;

	bits = *(t_bit *)&c;
	send_sig(pid, bits.b1);
	send_sig(pid, bits.b2);
	send_sig(pid, bits.b3);
	send_sig(pid, bits.b4);
	send_sig(pid, bits.b5);
	send_sig(pid, bits.b6);
	send_sig(pid, bits.b7);
	send_sig(pid, bits.b8);
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid == 0 || pid < 0)
		{
			write(1, "Error: Invalid pid\n", 19);
			return (1);
		}
		i = 0;
		while (argv[2][i])
		{
			char_to_binary(argv[2][i], pid);
			i++;
		}
	}
	else
	{
		write(1, "Usage: ./client PID 'Message'\n", 30);
		return (1);
	}
	return (0);
}
