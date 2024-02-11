#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>


#define START_ON 1
#define START_OFF 0
#define PORT 8765

void sig1_handler (int signo);

void sig2_handler (int signo);

int get_max (int n1, int n2);

int get_max_three (int n1, int n2, int n3);

int piped[2];

int start = START_OFF;

int main() {
    int length, P, Q, val_max;
    int val_max_glob = 0;
    struct sockaddr_in server;
    int sock, msgsock;
    char buffer[256];
    char msg[256];

    struct sigaction sig1, sig2;
    sigset_t sigmask, zeromask;

    // Inizializzazione di sig1

    sig1.sa_handler = sig1_handler;
    sig1.sa_flags = SA_RESTART;
    sigemptyset(&sig1.sa_mask);

    sigaction(SIGUSR1, &sig1, NULL);

    // Inizializzazione di sig2

    sig2.sa_handler = sig2_handler;
    sig2.sa_flags = SA_RESTART;
    sigemptyset(&sig2.sa_mask);

    sigaction(SIGUSR2, &sig2, NULL);

    printf("SERVER: PID %d\n", getpid());

    // inizializzazione della pipe

    if (pipe(piped) < 0) {
        perror("pipe error");
        exit(1);
    }

    write(piped[1], &val_max_glob, sizeof(val_max_glob));

    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_family = AF_INET;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        perror("socket error");
        exit(2);
    }

    if (bind(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("binding error");
        exit(3);
    }

    length = sizeof(server);

    if (getsockname(sock, (struct sockaddr*)&server, &length) < 0) {
        perror("getting sock name");
        exit(4);
    }

    listen(sock, 2);

    do {
        msgsock = accept(sock, (struct sockaddr*)&server, &length);
        if (msgsock == -1) {
            perror("accept");
            exit(5);
        }
        else {
            if (fork() == 0) {
                close(sock);
                read(msgsock, msg, sizeof(msg));
                sscanf(msg, "%d%d", &P, &Q);
                printf("SERVER: P: %d Q: %d\n", P, Q);

                if (start == START_ON) {
                    read(piped[0], &val_max_glob, sizeof(val_max_glob));

                    val_max = get_max_three(P, Q, val_max_glob);
                    val_max_glob = val_max;

                    sprintf(buffer, "VAL MAX GLOBALE %d\n", val_max_glob);
                    write(msgsock,buffer, strlen(buffer)+1);

                    write(piped[1], &val_max_glob, sizeof(val_max_glob));

                } else {
                    val_max = get_max(P, Q);
                    sprintf(buffer, "VAL MAX: %d\n", val_max);
                    write(msgsock, buffer, strlen(buffer)+1);
                }
                close(msgsock);
                exit(0);
            }
            else {
                close(msgsock);
            }
        }
    } while (1);
}

void sig1_handler (int signo) {
    printf("SERVER: Ricevuto SIGUSR1, PID: %d\n", getpid());

    start = !start;

    printf("SERVER: Inizio a conteggiare il valore massimo globale\n");
}

void sig2_handler (int signo) {
    int val_max;
    printf("SERVER: Ricevuto SIGUSR2, PID: %d\n", getpid());
    read(piped[0], &val_max, sizeof(val_max));

    val_max = 0;

    write(piped[1], &val_max, sizeof(val_max));
    printf("SERVER: VAL_MAX resettato\n");
}

int get_max (int n1, int n2) {
    if (n1 >= n2) { return n1; }
    else { return n2; }
}

int get_max_three (int n1, int n2, int n3) {
    int temp1 = get_max(n1, n2);
    int temp2 = get_max(n3, temp1);
    return temp2;
}