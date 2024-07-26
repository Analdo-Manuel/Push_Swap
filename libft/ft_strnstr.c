/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 02:35:31 by almanuel          #+#    #+#             */
/*   Updated: 2024/05/20 02:35:33 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *grand, const char *petit, size_t len)
{
	size_t	n;

	if (*petit == 0)
		return ((char *)grand);
	n = ft_strlen(petit);
	if (len == 0)
		return (0);
	while (*grand && n <= len)
	{
		if (*grand == *petit && ft_strncmp(grand, petit, n) == 0)
			return ((char *)grand);
		++grand;
		--len;
	}
	return (NULL);
}
