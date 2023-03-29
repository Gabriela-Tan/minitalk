/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:33:07 by gabtan            #+#    #+#             */
/*   Updated: 2023/03/29 07:59:52 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

static void	send_bit(int pid, int bit)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

void	send_str(int pid, char *str)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (i <= len)
	{
		j = 0;
		while (j < 8)
		{
			send_bit(pid, (str[i] >> j) & 1);
			j++;
			usleep(600);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		send_str(ft_atoi(argv[1]), argv[2]);
	else
		ft_printf("Error! Check number of parameters and pid");
	return (0);
}
