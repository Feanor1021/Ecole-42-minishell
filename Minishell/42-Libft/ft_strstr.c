#include "libft.h"

char	*ft_strstr(char *haystack, char *needle)
{
	int	i;
	int	j;

	if (!*needle)
		return (haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j])
			j++;
		if (!needle[j])
			return (haystack + i);
		i++;
	}
	return (NULL);
}
