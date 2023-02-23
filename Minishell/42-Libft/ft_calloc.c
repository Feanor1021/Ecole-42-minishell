#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buffer;

	buffer = (void *) malloc(size * nmemb);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, size * nmemb);
	return (buffer);
}

