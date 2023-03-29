/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:05:27 by gabtan            #+#    #+#             */
/*   Updated: 2023/03/16 16:46:20 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_match_printf(char c, va_list *args, int *len, int *i)
{
	if (c == 'c')
		ft_putchar(va_arg(*args, int), len);
	else if (c == 's')
		ft_puts(va_arg(*args, char *), len);
	else if (c == 'p')
		ft_putptr(va_arg(*args, size_t), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*args, int), len);
	else if (c == 'u')
		ft_putu(va_arg(*args, unsigned int), len);
	else if (c == 'x')
		ft_puthex(va_arg(*args, unsigned int), len);
	else if (c == 'X')
		ft_puthexup(va_arg(*args, unsigned int), len);
	else if (c == '%')
		ft_putchar('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_match_printf(string[i], &args, &len, &i);
			i++;
		}
		else
		{
			ft_putchar((char)string[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}
