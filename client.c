#include "Miniheader.h"

void foo(int sig)
{
    return;
}
void foo2(int sig)
{
    return;
}
int main(int ac, char **av)
{
    int d;
    if (ac == 3)
    {
        char binary[8] = "\0";
        int PID = atoi(av[1]);
        signal(SIGUSR1, foo);
        signal(SIGUSR2, foo2);

        (void) ac;
        for (int k = 2; av[k]; k++)
        {
            for (int n = 0; av[k][n]; n++)
            {
                for (int i = 7, index = 0; i >= 0, index < 8; i--, index++)
                {
                    d = (av[k][n] >> i) & 1;
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
                    binary[index] = d + '0';
                    usleep(100);
                }
            }
        }
    }
}
