/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabading <tabading@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:00:32 by tabading          #+#    #+#             */
/*   Updated: 2024/07/31 13:58:31 by tabading         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
same but works with multiple file descriptors.
*/

char	*join_free(char *stach, char *temp_buffer)
{
	char	*new;

	new = ft_strjoin(stach, temp_buffer);
	free(stach);
	return (new);
}

char	*fill_stach(int fd, char *stach)
{
	char	*temp_buffer;
	int		byts;

	if (!stach)
		stach = ft_calloc(1, sizeof(char));
	temp_buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	byts = 1;
	while (byts > 0)
	{
		byts = read(fd, temp_buffer, BUFFER_SIZE);
		if (byts == -1)
		{
			free(temp_buffer);
			free (stach);
			return (NULL);
		}
		if (byts == 0)
			break ;
		temp_buffer[byts] = '\0';
		stach = join_free(stach, temp_buffer);
		if (ft_strchr(stach, '\n'))
			break ;
	}
	free(temp_buffer);
	return (stach);
}

char	*fill_line(char *stach)
{
	char	*line;
	int		i;

	i = 0;
	if (!stach[i] || !stach)
		return (NULL);
	while (stach[i] != '\n' && stach[i])
		i++;
	if (stach[i] == '\n')
		line = ft_calloc(i + 2, sizeof(char));
	else
		line = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (stach[i] && stach[i] != '\n')
	{
		line[i] = stach[i];
		i++;
	}
	if (stach[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*reduce_buffer(char *buffer)
{
	int		red_len;
	char	*new_stach;
	int		j;

	j = 0;
	red_len = 0;
	while (buffer[red_len] && buffer[red_len] != '\n')
		red_len++;
	if (!buffer[red_len])
	{
		free(buffer);
		return (NULL);
	}
	new_stach = ft_calloc((ft_strlen(buffer) - red_len + 1), sizeof(char));
	if (!new_stach)
		return (NULL);
	while (buffer[++red_len])
		new_stach[j++] = buffer[red_len];
	free(buffer);
	return (new_stach);
}

/*
function can work with 1024 file descriptors at once.
by making a static array each file descriptor has a designated
place to store a string. by specifying wich stached string is meant 
in this function, nothing needs to be changed elsewhere, since 
those functions still get the same arguments. 
*/
char	*get_next_line(int fd)
{
	static char	*stach[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stach[fd] = fill_stach(fd, stach[fd]);
	if (!stach[fd])
		return (NULL);
	line = fill_line(stach[fd]);
	stach[fd] = reduce_buffer(stach[fd]);
	return (line);
}

// int main(void)
// {
// 	int fd1;
// 	int fd2;
// 	int byts = 0;
// 	char *res1;
// 	char *res2;
// 	int i = 0;
// 	fd1 = open("text.txt", O_RDONLY);
// 	byts = read(fd1, 0, 0);
// 	printf("%d\n", byts);
// 	fd2 = open("t2.txt", O_RDONLY);
// 	// while (i < 4)
// 	// {
// 	// 	res1 = get_next_line(fd1);
// 	// 	res2 = get_next_line(fd2);
// 	// 	printf("|%s|", res1);
// 	// 	printf("|%s|", res2);
// 	// 	free(res1);
// 	// 	free(res2);
// 	// 	i++;
// 	// }
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }