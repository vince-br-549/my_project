/* Print PID and loop. */

#include <stdio.h>
#include <unistd.h>

void infinite_loop(void)
{
    while(1);
}

int main(void)
{
    printf("PID: %d\n", getpid());
    fflush(stdout);

    infinite_loop();

    return 0;
}
