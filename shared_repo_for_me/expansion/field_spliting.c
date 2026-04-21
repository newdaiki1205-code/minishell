#include "expansion.h"

t_narg *field_splitiing(t_narg *src, t_env *env)
{
	char **tab;
	int size;
	t_narg *re;
	char *ifs_val;
	
	ifs_val = search_env(env, "IFS");
	if(!ifs_val)
		return NULL;
	if(*ifs_val)
		tab = ifs_split(src->val, ifs_val);
	else if(is_IFS(src->val))
		tab = ft_split(src->val);
	else
		return free(ifs_val), src;
	if(!tab)
		return free(ifs_val), NULL;
	free(ifs_val);
	size = 0;
	while(tab[size])
		size++;
	re = expand_list(src, tab, size);
	if(!re)
		return free_tab(tab), NULL;
	free_tab(tab);
	return re;
}

void free_tab(char **tab)
{
	int i;

	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}


t_narg *expand_list(t_narg *src, char **tab, int size)
{
	t_narg *new;
	t_narg *tmp;
	t_narg *current;
	int i;
	int j;
	char *trimed;

	i = 0;
	j = 0;
	current = src;
	while(i < size)
	{
		if(i == 0)
		{
			trimed = ft_strdup(tab[j]);
			if(!trimed)
				return NULL;
			free(src->val);
			src->val = trimed;
		}
		else
		{
			new = gen_expanded_arg(tab[j]);
			if(!new)
				return NULL;
			tmp = current->next;
			current->next = new;
			new->next = tmp;
			current = current->next;
		}
		i++;
		j++;
	}
	return current;
}

t_narg *gen_expanded_arg(char *str)
{
	t_narg *new;

	new = (t_narg*)malloc(sizeof(t_narg));
	if(!new)
		return NULL;
	new->val = ft_strdup(str);
	new->flag_cat = 0;
	new->q_state = ND_DEF;
	return new;
}

int is_IFS(char* str)
{
    if(ft_strchr(str, 9))
		return 1;
	if(ft_strchr(str, 10))
		return 1;
	if(ft_strchr(str, 32))
		return 1;
	return 0;
}

// static int	isset(char c, char const *set)
// {
// 	int	i;

// 	i = 0;
// 	while (set[i])
// 	{
// 		if (c == set[i])
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	char	*str;
// 	size_t	len;
// 	size_t	i;
// 	size_t	strlen;

// 	if (!s1 || !set)
// 		return (ft_strdup(""));
// 	len = ft_strlen(s1);
// 	i = 0;
// 	while (s1[i] && isset(s1[i], set))
// 		i++;
// 	while (len > i && s1[len - 1] && isset(s1[len - 1], set))
// 		len--;
// 	strlen = len - i;
// 	str = (char *)malloc(sizeof(char) * (strlen + 1));
// 	if (!str)
// 		return (NULL);
// 	ft_memcpy(str, s1 + i, strlen);
// 	str[strlen] = '\0';
// 	return ((char *)str);
// }