/*This part of the exercise, involves creating three process, instead of the three threads. Each of these process should involve compiling a copy of the Linux ker nel source (with the minimal config shared by the TAs earlier). The three pro cesses should be created with fork() and thereafter the child processes should use execl() family system calls to run a different a different bash script, each of which should be having the commands to compile a copy of the kernel. To time the execution, the parent process could get the clock timestamp (using clock gettime()) before the fork and after each process terminates (the event of which could be identified when the blocking system call waitpid()) returns.
 */
#include <stdio.h>
#include <time.h>

void processA()
{
    pid_t pid;
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    pid = fork();
    if (pid == 0)
    {
        execl("/bin/bash", "bash", "kernelCompile.sh", NULL);
    }
    else if (pid > 0)
    {
        waitpid(pid, NULL, 0);
    }
    else
    {
        printf("Fork failed");
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("Time taken by child process A: %lf\n", (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0);
}

void processB()
{
    pid_t pid;
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    pid = fork();
    if (pid == 0)
    {
        execl("/bin/bash", "bash", "kernelCompile.sh", NULL);
    }
    else if (pid > 0)
    {
        waitpid(pid, NULL, 0);
    }
    else
    {
        printf("Fork failed");
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("Time taken by child process B: %lf\n", (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0);
}

void processC()
{
    pid_t pid;
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    pid = fork();
    if (pid == 0)
    {
        execl("/bin/bash", "bash", "kernelCompile.sh", NULL);
    }
    else if (pid > 0)
    {
        waitpid(pid, NULL, 0);
    }
    else
    {
        printf("Fork failed");
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("Time taken by child process C: %lf\n", (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0);
}

int main()
{
    processA();
    processB();
    processC();
    return 0;
}