#include "libft.h"

int ft_isspace(char chr)
{
	return (chr == ' ' || (chr >= 9 && chr <= 13));
}
