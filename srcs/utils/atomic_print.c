#include "philo.h"

void atomic_print(char *str, pthread_mutex_t *lock_print);

void atomic_print(char *str, pthread_mutex_t *lock_print)
{
    pthread_mutex_lock(lock_print);
    printf("->%s\n", str);
    pthread_mutex_unlock(lock_print);
}