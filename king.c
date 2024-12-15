#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int binaryconv(char *s)
{
    int returned = 0;
    for (int i = 0; i < 8; i++)
    {
        returned = returned * 2 + (s[i] - '0');
    }
    return returned;
}


void handle_signal(int sig) 
{
    static char *binary;
    static int i = 0;
    if (sig == SIGUSR1)
        binary[i++] = '1';
    else if (sig == SIGUSR2)
        binary[i++] = '0';
    if (i == 8)
        i = 0;
}

int main()
{
    printf("King running with PID: %d\n", getpid());
    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);
    int i = 0;
    while (1)
    {
        pause();
        char s[8] = "\0";
 
    }
    return 0;
}