// serveur.c
#include "serv_cli_fifo.h"
#include "Handlers_Serv.h"
#include <time.h>

int main() {
    int fd_request, fd_response;
    Question question;
    Reponse reponse;
    srand(time(NULL));

    
    mkfifo(FIFO_REQUEST, 0666);
    mkfifo(FIFO_RESPONSE, 0666);

    
    signal(SIGUSR1, hand_reveil);
    signal(SIGINT, fin_serveur);  

    printf("Serveur démarré, en attente de clients...\n");

    while (1) {
        fd_request = open(FIFO_REQUEST, O_RDONLY);
        read(fd_request, &question, sizeof(Question));
        close(fd_request);

        printf("Requête reçue de client %d demandant %d nombres.\n", question.client_id, question.n);

        
        reponse.serveur_id = getpid();
        reponse.n = question.n;
        for (int i = 0; i < question.n; i++) {
            reponse.numbers[i] = rand() % 1000; 
        }

        //la réponse dans fifo2
        fd_response = open(FIFO_RESPONSE, O_WRONLY);
        write(fd_response, &reponse, sizeof(Reponse));
        close(fd_response);

        // Envyer le signal au client
        kill(question.client_id, SIGUSR1);
    }
    return 0;
}
