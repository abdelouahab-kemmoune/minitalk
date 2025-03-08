/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:15:18 by akemmoun          #+#    #+#             */
/*   Updated: 2025/01/28 14:04:43 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	msg(int pid, char *str)
{
	int		error;
	int		counter;
	char	c;

	error = 0;
	while (*str)
	{
		counter = 7;
		c = *str;
		while (counter >= 0)
		{
			if ((c >> counter) & 1)
				error = kill(pid, SIGUSR1);
			else
				error = kill(pid, SIGUSR2);
			usleep(500);
			counter--;
			if (error == -1)
			{
				write(1, "Error", 5);
				exit (1);
			}
		}
		str++;
	}
}

int	main(int ac, char **av)
{
	long	pid;
	char	*str;

	pid = 0;
	if (ac == 3 && ft_isdigit(av[1]))
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0 || pid > 2147483647)
		{
			ft_putstr("PID incorrect");
			exit (1);
		}
		str = av[2];
		msg(pid, str);
	}
	else
		ft_putstr("invalide input");
	return (0);
}
