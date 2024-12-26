#include "servidor.h"
#include <stdio.h>
#include <stdlib.h>



Servidor leRegistrosServidor() 
{   Servidor servidor;
    servidor.nPartidas=0;
    int id=0;
    for (int i = 0; i >= 0; i++)
    {      
        scanf("%d\n",&id);
        if (id==-1)
    {
        break;
    }

    servidor.partidas[i]=leRegistro(id);
    servidor.nPartidas++;
    }
    
    return servidor;
       
}

Jogador buscaDadosJogadorServidor(Servidor s, int idJog)
{   Jogador jogador,referencia;
    jogador=inicializaJogador(idJog);
    for (int i = 0; i < s.nPartidas; i++)
    {   referencia=buscaJogadorRegistro(s.partidas[i],idJog);
        if (referencia.id!=-1)
        {
            jogador=atualizaJogador(jogador,referencia.id,referencia.kills,referencia.deaths,referencia.assists);

        }
        
    }
    return jogador;
}

void criaRelatorioServidor(Servidor s)
{   
    int nJogadores,id;
    Jogador jog;
    scanf("%d\n",&nJogadores);
    
    for (int i = 0; i < nJogadores; i++)
    {
        scanf("%d",&id);
        jog=buscaDadosJogadorServidor(s,id);
        if (jog.valorKDA!=-1)
        {
            printaJogador(jog);
        }
        else
        {
            printf("Jogador %d: -\n",id);
        }
        
    }
    

}

