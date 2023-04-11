/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 06:54:44 by melhadou          #+#    #+#             */
/*   Updated: 2023/04/11 21:42:00 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	char_to_binary(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c % 2)
		{
			kill(pid, SIGUSR2);
			usleep(250);
		}
		else
		{
			kill(pid, SIGUSR1);
			usleep(250);
		}
		c /= 2;
		i++;
	}
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
			write(1,"Error: Invalid pid\n", 18);
			return (1);
		}
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
