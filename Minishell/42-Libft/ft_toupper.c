#include "libft.h"

int	ft_toupper(int c)
{
	if (c <= 'z' && c >= 'a')
		c -= 32;
	return (c);
}
