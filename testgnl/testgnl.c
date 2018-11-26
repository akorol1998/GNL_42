/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testgnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:31:09 by akorol            #+#    #+#             */
/*   Updated: 2018/11/26 18:53:01 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
// Nedd a function to find a linebreak in the buffer
// condition: if a line break not found in the buffer - add amount of read bytes to the varibale
/*
void	ft_transfer(char **line, char *storage,  char *buf, int i)
{
	int	a;
	int	b;
	int index;

	index = -1;
	a = -1;
	while (++a < i)
	{
		b = -1;
		while (storage[a][++b] != '\0')
		{
			*line[++index] = storage[a][b]; 
		}
	}
	a = -1;
	while (buf[++a])
		*line[index] = buf[a];
}
*/
char	*super_function(char *arr, char *buffer, size_t *var, size_t r)
{
	char	*tmp;

	*var += r;
	tmp = ft_strjoin((const char *)arr, (const char *)buffer);
	free(arr);
	printf("%s and amount of bytes [%lu]\n", tmp, *var);
	return (tmp);
}

size_t	bytes_with_linebreak(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	char			*buf;
	char			*storage;
	char			*pointer;
	size_t			r;
	size_t 			bytes;

	buf = ft_strnew(BUFF_SIZE);
	storage = ft_strnew(0);
	bytes = 0;
	while ((r = read(fd, buf, BUFF_SIZE)))
	{
		if (bytes_with_linebreak(buf))
		{
			printf(" %lu, %lu", bytes, bytes_with_linebreak(buf));
			//*line = ft_strnew(bytes + bytes_with_linebreak(buf));	
			*line = ft_strjoin(storage, buf);
			free(buf);
		}
		else
		{
			pointer = super_function(storage, buf, &bytes, r);
		//	free(storage);
			storage = pointer;
		//	printf(" %s ", storage);
			free(pointer);
		}
	}
	if (r)
		return (1);
	return (0);
}


int main()
{
	char	*str;
	int		i;

	i = open("mark.txt", O_RDONLY|O_CREAT);
	if (i == -1)
		printf("Nope");
	get_next_line(i, &str);
	printf("%seto breakline\n", str);
	system("leaks a.out");
	return (0);
}


