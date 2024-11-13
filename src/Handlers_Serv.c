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