#include "philo.h"

bool ft_mutex_init(size_t size, pthread_mutex_t *mutex);
bool ft_mutex_destroy(size_t size, pthread_mutex_t *mutex);

bool ft_mutex_init(size_t size, pthread_mutex_t *mutex)
{
    size_t i;

    i = 0;
    while (i < size)
    {
        if (pthread_mutex_init(&mutex[i++], NULL) != 0)
            return (true);
    }
    return (false);
}

bool ft_mutex_destroy(size_t size, pthread_mutex_t *mutex)
{
    size_t i;

    i = 0;
    while (i < size)
    {
        if (pthread_mutex_destroy(&mutex[i++]) != 0)
            return (true);
    }
    return (false);
}

bool ft_mutex_init(size_t size, ...)
{
    pthread_mutex_t *mutex_ptr;
    pthread_mutex_t mutex;
    va_list ap;
    size_t i;

    va_start(ap, size);
    while (size-- > 0)
    {
        mutex_ptr = va_arg(ap, pthread_mutex_t *);
        if (mutex_ptr != NULL)
        {
            i = 0;
            while (i < sizeof(mutex_ptr) / 40)
                if (pthread_mutex_init(&mutex_ptr[i], NULL) != 0)
                    return (va_end(ap),true); 
        }
        else
        {
            mutex = va_arg(ap, pthread_mutex_t);
            if (pthread_mutex_init(&mutex, NULL) != 0)
                return (va_end(ap),true);
        }
    }
    return (va_end(ap), false);
}