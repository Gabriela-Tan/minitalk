/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtan <gabtan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:48:24 by gabtan            #+#    #+#             */
/*   Updated: 2023/01/24 16:16:09 by gabtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ptr;

	i = ft_strlen(s);
	ptr = (char)c;
	while (i > 0)
	{
		if (s[i] == ptr)
			return ((char *)&s[i]);
		i--;
	}
	if (s[i] == ptr)
		return ((char *)&s[i]);
	return (NULL);
}
