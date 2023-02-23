#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;

	a = b;
	while (len > 0)
	{
		*a = c;
		a++;
		len--;
	}
	return (b);
}
