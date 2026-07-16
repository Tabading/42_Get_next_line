/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabading <tabading@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:43:23 by tabading          #+#    #+#             */
/*   Updated: 2024/07/15 14:59:38 by tabading         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == 0)
		return (0);
	while (*s != (unsigned char)c)
	{
		if (!*s++)
			return (0);
	}
	return ((char *)s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;
	char	*new_stach;

	new_stach = NULL;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len + s2_len == 0)
		return (NULL);
	new_stach = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!new_stach || !s1 || !s2)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != 0)
		new_stach[i] = s1[i];
	while (s2[j] != 0)
		new_stach[i++] = s2[j++];
	new_stach[s1_len + s2_len] = 0;
	return (new_stach);
}

void	ft_bzero(void *str, size_t n)
{
	size_t			i;

	i = 0;
	while (i != n)
	{
		*(unsigned char *)(str + i) = '\0';
		i++;
	}
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	if ((int)n * size > 2147483647)
		return (NULL);
	ptr = malloc(n * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n * size);
	return (ptr);
}
