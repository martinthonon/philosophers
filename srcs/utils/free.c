#include "philo.h"

int	ft_free(const char *formats, ...)
{
	va_list	ap;
	int		i;
	void	**dptr;

	va_start(ap, formats);
	while (*formats != '\0')
	{
		if (*formats == '%')
		{
			++formats;
			if (*formats == 'p')
				free(va_arg(ap, void *));
			else if (*formats == 'P')
			{
				dptr = va_arg(ap, void **);
				i = 0;
				while (dptr[i] != NULL)
					free(dptr[i++]);
				free(dptr);
			}
		}
		++formats;
	}
	va_end(ap);
    return (0);
}
	