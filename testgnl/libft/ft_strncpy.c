/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:51:50 by akorol            #+#    #+#             */
/*   Updated: 2018/11/26 15:57:46 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(str2);
	i = 0;
	while (i < len)
	{
		if (i > j)
			str1[i] = '\0';
		else
		{
			str1[i] = str2[i];
		}
		i++;
	}
	return (str1);
}
