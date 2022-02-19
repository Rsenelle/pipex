#include <stdio.h>
#include "include/pipex.h"

char	**put_str_to_arr(char **arr, int size, char *s)
{
	int		i;
	char	**res;

	if (arr && s)
	{
		res = malloc(sizeof(char *) * (size + 1) + 1);
		if (!res)
			return (NULL);
		i = 0;
		while (arr[i++])
			res[i] = arr[i];
		res[i] = s;
		i++;
		res[i] = NULL;
		free (arr);
		return (res);
	}
	else if (s && !arr)
	{
		if (!(res = malloc(sizeof(char *) + 1)))
			return (NULL);
		res[0] = s;
		res[1] = NULL;
		free (arr);
		return (res);
	}
	return (NULL);
}
int main()
{
	char	**arr1;
	char	**arr2;
	char	*s;

	


}
