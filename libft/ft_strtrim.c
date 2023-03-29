/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtan <gabtan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:18:55 by gabtan            #+#    #+#             */
/*   Updated: 2023/01/19 15:16:57 by gabtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = 0;
	i = 0;
	j = ft_strlen(s1);
	if (s1 != 0 && set != 0)
	{
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && (j > i))
			j--;
		str = (char *)malloc(sizeof(char) * (j - i + 1));
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, &s1[i], j - i + 1);
	}
	else
	{
		str = (char *)malloc(sizeof(char));
		if (str == NULL)
			return (NULL);
	}
	return (str);
}
