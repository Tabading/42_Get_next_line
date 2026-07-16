/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabading <tabading@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:31:49 by tabading          #+#    #+#             */
/*   Updated: 2024/07/15 13:47:46 by tabading         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t n, size_t size);

char	*get_next_line(int fd);
char	*fill_stach(int fd, char *buffer);
char	*fill_line(char *stach);
char	*reduce_buffer(char *buffer);
char	*join_free(char *stach, char *temp_buffer);

#endif