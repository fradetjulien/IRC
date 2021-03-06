/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** get_next_line.c
*/

#include "../../../Includes/library.h"

void			charact(char c, char *str)
{
	if (c == '\n') {
		*str = '\0';
	}
	else {
		*str = c;
		*(str + 1) = 0;
	}
}

int			select_c(const int fd, char *str)
{
	static char	buffer[READ_SIZE];
	static int	nbr = READ_SIZE;
	static int	i = 0;

	if (i >= nbr || i == 0)	{
		i = 0;
		if ((nbr = read(fd, buffer, READ_SIZE)) <= 0)
			return (0);
	}
	if (nbr == 0) {
		*str = '\0';
		i = -1;
	}
	else {
		charact(buffer[i], str);
		i++;
	}
	return (nbr);
}

char		*my_realloc(char *old, int size)
{
	char	*new;
	int	i = 0;

	if ((new = malloc(sizeof(char) * (strlen(old) + size))) == NULL)
		return (NULL);
	while (old[i] != '\0') {
		new[i] = old[i];
		i++;
	}
	free(old);
	new[i] = 0;
	return (new);
}

char		*get_next_line(const int fd)
{
	char	*str;
	int	nbr = 1;
	int	i = 0;

	if ((str = malloc((READ_SIZE + 1) * sizeof(*str))) == NULL)
		return (NULL);
	nbr = select_c(fd, &str[i]);
	if (nbr == 0) {
		free(str);
		return (NULL);
	}
	while (str[i]) {
		if (i % READ_SIZE == 0)
			if ((str = my_realloc(str, i + READ_SIZE + 1)) == NULL)
				return (NULL);
		nbr = select_c(fd, &str[++i]);
	}
	str[++i] = '\0';
	return (str);
}
