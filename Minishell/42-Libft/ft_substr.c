#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	index;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	dest = (char *)malloc(sizeof(*s) * (len + 1));
	if (!dest)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	index = 0;
	while (len--)
		dest[index++] = s[start++];
	dest[index] = '\0';
	return (dest);
}
