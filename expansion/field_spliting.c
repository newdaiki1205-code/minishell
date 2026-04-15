#include "expansion.h"

t_narg *field_splitiing(t_narg *src)
{
    int i;

    i = 0;
    while(src->val[i])
    {
        if(is_IFS(src->val[i]))
        {
            src = mod_list(src);
            break;
        }
        i++;
    }
    return src;

    

}

int is_IFS(char c)
{
    if(c == 9 || c == 10 || c == 32)
        return 1;
    return 0;
}

static int	isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	strlen;

	if (!s1 || !set)
		return (ft_strdup(""));
	len = ft_strlen(s1);
	i = 0;
	while (s1[i] && isset(s1[i], set))
		i++;
	while (len > i && s1[len - 1] && isset(s1[len - 1], set))
		len--;
	strlen = len - i;
	str = (char *)malloc(sizeof(char) * (strlen + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1 + i, strlen);
	str[strlen] = '\0';
	return ((char *)str);
}