#include "Miniheader.h"

void handle_signal(int sig) 
{
    int n;
    static char c = 0;
    static int count = 0;
    if (sig == SIGUSR1)
        n = 1;
    else if (sig == SIGUSR2)
        n = 0;
    c = c << 1 | n;
    count++;
    if (count == 8)
    {
        ft_printf("%c", c);
        count = 0;
        c = 0;
    }
}

int main()
{
    ft_printf("The server's running with PID: %d\n", getpid());
    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);
    while (1)
        pause();
    return 0;
}