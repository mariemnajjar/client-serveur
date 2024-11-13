// Handlers_Serv.h
#ifndef HANDLERS_SERV_H
#define HANDLERS_SERV_H
#include "serv_cli_fifo.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>


void hand_reveil(int sig) ;

void fin_serveur(int sig) ;
#endif
