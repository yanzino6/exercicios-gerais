#include "jogador.h"
#include <stdio.h>
#include <stdlib.h>

//bunda cagada


Jogador inicializaJogador(int id)
{
    Jogador jogador1;
    jogador1.id=id;
    jogador1.valorKDA=-1;
    jogador1.assists=0;
    jogador1.deaths=0;
    jogador1.kills=0;

    return jogador1;
}

Jogador leJogador(int id)
{
    Jogador Jogador1;
    Jogador1=inicializaJogador(id);
    scanf(" %d %d %d\n",&Jogador1.kills,&Jogador1.deaths,&Jogador1.assists);
   Jogador1.valorKDA= calculaKDA(Jogador1);
    
    return Jogador1;
}
float calculaKDA(Jogador j)
{   float mortes=j.deaths,baixas=j.kills,assistencias=j.assists;

    if (j.deaths>0)
    {
        j.valorKDA=(baixas+assistencias)/mortes;
    }

    else
    {
        j.valorKDA=baixas+assistencias;
    }

    return j.valorKDA;
}

Jogador atualizaJogador(Jogador j, int id, int k, int d, int a)
{  
    j.id=id;
    j.assists+=a;
    j.deaths+=d;
    j.kills+=k;
    j.valorKDA=calculaKDA(j);
    return j;
}

int getKillsJogador(Jogador j)
{
    return j.kills;
}

int getDeathsJogador(Jogador j)
{
    return j.deaths;
}

int getAssistsJogador(Jogador j)
{
    return j.assists;
}

int getIdJogador(Jogador j)
{
    return j.id;
}

void printaJogador(Jogador j)
{
    printf("Jogador %d: %d/%d/%d (%.2f)\n",j.id,j.kills,j.deaths,j.assists,j.valorKDA);
}
