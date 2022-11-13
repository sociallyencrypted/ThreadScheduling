#include <stdio.h>
#include <pthread.h>
#include <sched.h>
#include <time.h>
#include <unistd.h>

void countA()
{
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (long long i = 1; i <= 1L << 32; i++)
    {
        continue;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("Time taken by countA: %lf\n", (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0);
}
void countB()
{
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (long long i = 1; i <= 1L << 32; i++)
    {
        continue;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("Time taken by countB: %lf\n", (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0);
}
void countC()
{
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (long long i = 1; i <= 1L << 32; i++)
    {
        continue;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("Time taken by countC: %lf\n", (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0);
}

int main()
{
    pthread_t threadA, threadB, threadC;
    pthread_create(&threadA, NULL, countA, NULL);
    pthread_create(&threadB, NULL, countB, NULL);
    pthread_create(&threadC, NULL, countC, NULL);
    sched_setscheduler(threadA, SCHED_OTHER, NULL);
    sched_setscheduler(threadB, SCHED_RR, NULL);
    sched_setscheduler(threadC, SCHED_FIFO, NULL);
    struct sched_param param;
    param.sched_priority = 0;
    pthread_setschedparam(threadA, SCHED_OTHER, &param);
    pthread_setschedparam(threadB, SCHED_RR, &param);
    pthread_setschedparam(threadC, SCHED_FIFO, &param);
    pthread_join(threadA, NULL);
    pthread_join(threadC, NULL);
    pthread_join(threadB, NULL);
    return 0;
}