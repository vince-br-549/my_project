/* Print PID and loop. */

#include <stdio.h>
#include <unistd.h>

void infinite_loop(void)
{
    while(1);
}

int main(int argc, char **argv)
{
    printf("PID: %d\n", getpid());
    fflush(stdout);

    infinite_loop();

    return 0;
}
