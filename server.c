/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:16:36 by akemmoun          #+#    #+#             */
/*   Updated: 2025/01/23 10:43:12 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receiver(int signal)
{
	static int	a;
	static char	msg;

	if (signal == SIGUSR1)
		msg = (msg << 1) | 1;
	else if (signal == SIGUSR2)
		msg = (msg << 1);
	a++;
	if (a == 8)
	{
		write(1, &msg, 1);
		a = 0;
		msg = 0;
	}
}

int	main(void)
{
	int	id;

	id = getpid();
	ft_putnbr(id);
	write(1, "\n", 1);
	signal(SIGUSR2, receiver);
	signal(SIGUSR1, receiver);
	while (1)
		pause();
}
