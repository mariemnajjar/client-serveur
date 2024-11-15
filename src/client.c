// client.c
#include "serv_cli_fifo.h"
#include <time.h>
#include "Handlers_Serv.h"

int main() {
    int fd_request, fd_response;
    Question question;
    Reponse reponse;
    int n;

    srand(time(NULL));
    n = rand() % NMAX + 1;  
    question.client_id = getpid();
    question.n = n;

    
    signal(SIGUSR1, hand_reponse);

    
    fd_request = open(FIFO_REQUEST, O_WRONLY);
    write(fd_request, &question, sizeof(Question));
    close(fd_request);

    printf("Client %d : Requête envoyée pour %d nombres.\n", question.client_id, question.n);

    // /////////////////////////////////////réponse dans fifo2
    fd_response = open(FIFO_RESPONSE, O_RDONLY);
    pause(); // attente du signal server
    read(fd_response, &reponse, sizeof(Reponse));
    close(fd_response);

    if (reponse.client_id == question.client_id) {
        printf("Serveur %d : Nombres reçus : ", reponse.serveur_id);
        fflush(stdout);
        for (int i = 0; i < reponse.n; i++) {
            printf("%d ", reponse.numbers[i]);
        }
        printf("\n");
        fflush(stdout);
    }

    
    kill(reponse.serveur_id, SIGUSR1);

    return 0;
}
