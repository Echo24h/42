/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:20:44 by ydanset           #+#    #+#             */
/*   Updated: 2021/10/18 12:58:09 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{	
	while (n--)
	{
		*((unsigned char *)(dst++)) = *(unsigned char *)src;
		if (*(unsigned char *)src == (unsigned char)c)
			return (dst);
		src++;
	}
	return (NULL);
}
