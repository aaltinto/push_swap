/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:37:42 by aaltinto          #+#    #+#             */
/*   Updated: 2023/12/13 17:29:38 by aaltinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		counter;
	char	*str;

	counter = 0;
	str = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (s1[counter] != '\0')
	{
		str[counter] = s1[counter];
		counter++;
	}
	str[counter] = '\0';
	return (str);
}
