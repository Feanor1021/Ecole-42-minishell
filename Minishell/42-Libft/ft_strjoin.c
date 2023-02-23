#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	int		index_join;
	char	*join;

	if (!s1 || !s2)
		return (0);
	join = \
	malloc(sizeof(char) * (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (!s1 || !s2 || !(join))
		return (NULL);
	index = 0;
	index_join = 0;
	while (s1[index] != 0)
		join[index_join++] = s1[index++];
	index = 0;
	while (s2[index] != 0)
	join[index_join++] = s2[index++];
	join[index_join] = '\0';
	return (join);
}
