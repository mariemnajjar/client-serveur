// serv_cli_fifo.h
#ifndef SERV_CLI_FIFO_H
#define SERV_CLI_FIFO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#define NMAX 100       
#define FIFO_REQUEST "fifo1" 
#define FIFO_RESPONSE "fifo2" 
// question //////////////////////////////////////////////////////
typedef struct {
    int client_id;  
    int n;          
} Question;

// Structure  réponse ////////////////////////////////////////
typedef struct {
    int client_id;       
    int numbers[NMAX];   
    int n;               
} Reponse;

#endif
