#include "test.h"
#include "Handlers_Serv.h"
#include "unity.h"
void test_client(int n , int* arr){ 

    int fd_request, fd_response;
    Question question;
    Reponse reponse;

    question.client_id = getpid();
    question.n = n;

    
    signal(SIGUSR1, hand_reponse);

    
    fd_request = open(FIFO_TEST, O_WRONLY);
    write(fd_request, &question, sizeof(Question));
    close(fd_request);

    printf("Client %d : Requête envoyée pour %d nombres.\n", question.client_id, question.n);

    // /////////////////////////////////////réponse dans fifo2
    fd_response = open(FIFO2_TEST, O_RDONLY);
    /* pause(); */
    read(fd_response, &reponse, sizeof(Reponse));
    close(fd_response);

    if (reponse.client_id == question.client_id) {
        printf("Serveur %d : Nombres reçus : ", reponse.serveur_id);
        fflush(stdout);
        for (int i = 0; i < reponse.n; i++) {
            printf("%d ", reponse.numbers[i]);
            
        TEST_ASSERT_EQUAL_INT(reponse.numbers[i],arr[i]);
        }
        printf("\n");
        fflush(stdout);
    }
}
