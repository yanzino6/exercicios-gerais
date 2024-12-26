#include "servidor.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    Servidor server;
    server=leRegistrosServidor();

    criaRelatorioServidor(server);
}