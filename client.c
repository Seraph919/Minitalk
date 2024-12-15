#include "Miniheader.h"

void foo(int sig)
{
    (void) sig;
    return;
}
void foo2(int sig)
{
    (void) sig;
    return;
}
int main(int ac, char **av)
{
    int d;
    int n = 0;
    int i = 7;

    if (ac == 3)
    {
        int PID = atoi(av[1]);
        signal(SIGUSR1, foo);
        signal(SIGUSR2, foo2);
        while(av[2][n])
        {
            while (i >= 0)
            {
                d = (av[2][n] >> i) & 1;
                if (d == 0)
                {
                    kill(PID, SIGUSR2);
                    printf("THE SIGUSR2 HAS BEEN SENT TO %d\n", PID);
                }
                else
                {
                    kill(PID, SIGUSR1);
                    printf("THE SIGUSR1 HAS BEEN SENT TO %d\n", PID);
                }
                usleep(100);
                i--;
            }
            n++;
        }
    }
}
