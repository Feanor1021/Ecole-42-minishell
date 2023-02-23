#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c <= 'Z' && c >= 'A'))
		return (1);
	return (0);
}
