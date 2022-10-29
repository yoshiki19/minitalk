#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

static void handler(int signo)
{
    /* 
     * 本来ハンドラ内では、非同期シグナルセーフな関数を使用するべきですが、
     * ここでは、そうでない printf()、exit() などの関数を使用しています。
     * 非同期シグナルセーフについては $ man 7 signal をご参照ください。
     */
    printf(" ... Caught the SIGINT (%d)\n", signo);
    exit(EXIT_SUCCESS);
}

int main(void)
{
    unsigned int sec = 1;
    struct sigaction act;

    // SIGINT 受信時に handler() を実行するように設定。
    memset(&act, 0, sizeof act);
    act.sa_handler = handler;
    sigaction(SIGINT, &act, NULL);

    // Ctrl + C などで終了されるまで、1 秒ごとにメッセージを出力する。
    for (;;) {
        sleep(sec);
        printf("Stop me !\n");
    }
    return 0;
}