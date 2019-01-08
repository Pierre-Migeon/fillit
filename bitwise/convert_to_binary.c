#include <stdlib.h>
#include "../libft/libft.h"

void		convert_to_binary(char *str, uint16_t number)
{
	int bit;
	int i;

	bit = 32768;
	i = 0;
	while (bit && str[i])
	{
		if (str[i] != '\n')
		{
			if (str[i] == '#')
				number |= bit;
			bit >>= 1;
		}
		i++;
	}
	printf("%hu", number);
}

int		main(int argc, char **argv)
{
	uint16_t number = 0;
	char *piece = "#...\n###.\n....\n....\n";
	
	convert_to_binary(piece, number);
	return (0);
}
