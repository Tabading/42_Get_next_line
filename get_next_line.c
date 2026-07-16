/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabading <tabading@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:14:23 by tabading          #+#    #+#             */
/*   Updated: 2024/07/31 13:49:42 by tabading         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
read a text file line by line, no mater how big the buffer is.
--------------------------------------------------------------
read remembers where it is, and is always reading until BUFFER_SIZE if
possible. saving that in a temp_buffer(size buffer_size + 1) to then 
str_join to the static holding everything alows us to read 
until a \n or \0 (acually until read gives out 0 byts read, since we
have to null terminate the temp and stach).
after saving one line in a variable to return, we nead to shorten the 
stach of that part, do not forget to free stach befor returning the 
new one !!
passes paco, not strict (problems with tester ?? who knows \('^')/ )
*/

/*
joins stach and temp saving the malloced result in new. have to free
old stach since new is returned back into stach, so it has to be empty
*/
char	*join_free(char *stach, char *temp_buffer)
{
	char	*new;

	new = ft_strjoin(stach, temp_buffer);
	free(stach);
	return (new);
}

/*
first 'helper function' that is entered. it turns stach from a 0x0 to
"\0" so joinfree/strjoin/strlen doesn't get problems. initilizes a temp
the size of buffer_size to save read into, freed after read isn't 
nessesary anymore. temp[byts] is set to \0 to avoid leftover read on next
loop.
*/
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

/*
fills line by copyig stach until \n or end. that difference is 
important for size "a\n\0"=3 "a\0"=2. no free since return is to 
an uninitilized value, and stach is still needed.
*/
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

/*
reduces stach of first output line. if nothing is behind that, 
returns null after free. always free stach because new one is 
returned into it!!
*/
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
fills stach by reading until \n or end of file.
fills line from buffer until \n or end of stach.
delet stach until line output, if nothig after return 0x0.
*/
char	*get_next_line(int fd)
{
	static char	*stach;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stach = fill_stach(fd, stach);
	if (!stach)
		return (NULL);
	line = fill_line(stach);
	stach = reduce_buffer(stach);
	if (!stach)
		free(stach);
	return (line);
}

// int main(void)
// {
// 	int fd;
// 	char *res;
// 	int i = 0;
// 	fd = open("text.txt", O_RDONLY);
// 	while (i < 10)
// 	{
// 		res = get_next_line(fd);
// 		printf("%s", res);
// 		free(res);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }