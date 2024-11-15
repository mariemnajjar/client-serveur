#include "test.h"
#include "Handlers_Serv.h"
#include "unity.h"
#define MAX_POSIX_SIG 32

void test_serveur(int n, int *arr){
int fd_request, fd_response;
    Question question;
    Reponse reponse;


    
    mkfifo(FIFO_TEST, 0666);
    mkfifo(FIFO2_TEST, 0666);


    // handle all the signals provided by POSIX   
    struct sigaction sa; 
    sigset_t set; 
    sa.sa_handler = main_handler; 
    sa.sa_flags = 0 ; 
    sigemptyset(&set); 
    sa.sa_mask =set ; 
    for ( int i=1 ; i< MAX_POSIX_SIG ; i++){ 
        if ( i!=SIGKILL && i!=SIGSTOP){ 
            if ( sigaction(i,&sa,NULL)==-1){ 
                printf("error sigaction %d \n",  i );
                fflush(stdout);

            }
        }
    }
    printf("Serveur démarré, en attente de clients...\n");

    while (1) {
        printf("------------------------ Begin -----------------------------\n");
        fd_request = open(FIFO_TEST, O_RDONLY);
        read(fd_request, &question, sizeof(Question));
        close(fd_request);

        printf("Requête reçue de client %d demandant %d nombres.\n", question.client_id, question.n);

        
        reponse.serveur_id = getpid();
        reponse.client_id = question.client_id;
        reponse.n = question.n;
        TEST_ASSERT_EQUAL_INT(n,question.n);
        for (int i = 0; i < question.n; i++) {
            reponse.numbers[i] = arr[i]; 
        }

        //la réponse dans fifo2
        fd_response = open(FIFO2_TEST, O_WRONLY);
        write(fd_response, &reponse, sizeof(Reponse));
        close(fd_response);

        // Envyer le signal au client
        kill(question.client_id, SIGUSR1);
        pause(); // wait server response

        printf("------------------------ end -----------------------------\n\n");
        fflush(stdout);
    }   

  
}
