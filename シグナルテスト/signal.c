#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void signal_hundler(int signo)
{
    printf("%s", "you died!");
    exit(1);
}

int main(void)
{
    signal(SIGINT, signal_hundler);

    while(1){
    }
    return 0;
}