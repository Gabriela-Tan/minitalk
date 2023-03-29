/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtan <gabtan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:06:18 by gabtan            #+#    #+#             */
/*   Updated: 2023/01/20 13:01:06 by gabtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*ptr;
	int			i;

	if (s == NULL)
		return (NULL);
	i = 0;
	ptr = s;
	while (ptr[i])
	{
		if (ptr[i] == (char) c)
			return ((char *)&ptr[i]);
		i++;
	}
	if ((char) c == ptr[i])
		return ((char *)&ptr[i]);
	return (NULL);
}
