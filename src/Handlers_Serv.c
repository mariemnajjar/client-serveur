#include "Handlers_Serv.h"
void hand_reveil(int sig) {
    printf("Serveur réveillé par SIGUSR1\n");
}


void fin_serveur(int sig) {
    printf("Serveur en cours de fermeture...\n");
    unlink(FIFO_REQUEST);
    unlink(FIFO_RESPONSE);
    exit(0);
}
void main_handler(int sigint){ 
    if ( sigint == SIGUSR1){ 
        printf("%d \n", sigint);
        fflush(stdout);
        hand_reveil(sigint);
    }else { 
        // handle du signal quelconque 
        fin_serveur(sigint);
    }
}
void hand_reponse(int sig) {
    printf("Client %d : Réponse reçue du serveur\n", getpid());
}


