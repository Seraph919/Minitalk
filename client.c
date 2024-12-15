#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void foo(int sig)
{
    printf("1");
}

void foo2(int sig)
{
    printf("0");
}



int binaryconv(char *s)
{
    int returned = 0;
    for (int i = 0; i < 8; i++)
    {
        returned = returned * 2 + (s[i] - '0');
    }
    return returned;
}

int main(int ac, char **av)
{
    int d;
    if (!av[1] || !av[2])
        return 0;
    char binary[8] = "\0";
    int PID = atoi(av[1]);
    signal(SIGUSR1, foo);
    signal(SIGUSR2, foo2);

    (void) ac;
    printf("----------------------\n");
    for (int k = 2; av[k]; k++)
    {
        for (int n = 0; av[k][n]; n++)
        {
            for (int i = 7, index = 0; i >= 0, index < 8; i--, index++)
            {
                d = (av[k][n] >> i) & 1 ;
                if (d == 0)
                    kill(PID, SIGUSR2);
                else
                    kill(PID, SIGUSR1);
                binary[index] = d + '0';
                usleep(50);
            }
            printf("\n------------^^^---------\n");
            printf("The %%c of the binary above is : %c", binaryconv(binary));
                printf("\n----------------------\n");
        }
        printf("\n");
    }
    printf("----------------------");
}
