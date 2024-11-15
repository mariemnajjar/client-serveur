// Handlers_Serv.h
#ifndef HANDLERS_SERV_H
#define HANDLERS_SERV_H
#include "serv_cli_fifo.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void main_handler(int sigint); 
void hand_reveil(int sig) ;
void hand_reponse(int sig) ;


void fin_serveur(int sig) ;
#endif
