#include "../microBash.h"

char	**basic_mult_arg(t_list_block *tmp, char **env)
{
	int		count;
	int		j;
	int		i;
	char	**res;
	char	*new;

	count = arg_count(tmp->arg) + 1;
	if (!(res = ft_calloc(count + 1, sizeof(char*))))
		return (NULL);
	if (!(res[0] = ft_strdup_pars(tmp->cmd)))
		return (char_free(res, 0));
	i = 0;
	j = 0;
	while (++j < count)
	{
		if (!(new = find_arg(tmp->arg, &i)))
			return (char_free(res, j));
		if (!(res[j] = string_refact(new, env)))
		{
			free(new);
			return (char_free(res, j));
		}
		free(new);
	}
	return (res);
}
