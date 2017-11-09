#include "sigfigs.h"

static void sighandler(int signo) {
    if (signo == SIGINT) {
        int fd = open("errorlog", O_CREAT | O_WRONLY | O_APPEND, 0644);
        char entry[128] = "Terminated Program: Signal Interrupt (SIGINT) received.\n";
        write(fd, entry, sizeof(entry));
        printf("%s", entry);
        close(fd);
        exit(1);
    } else if (signo == SIGUSR1) {
        printf("SIGUSR1 means you get the Parent PID: %d\n", getppid());
    }
}

int main() {
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);

    while (42) {
        printf("Process ID: %d\n", getpid());
        usleep(1420000);
    }

    return 0;
}