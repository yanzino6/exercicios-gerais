#include "registro.h"
#include <stdio.h>
#include <stdlib.h>


Registro leRegistro(int idPartida)
{   
    Registro partida;
    partida.idPartida=idPartida;
    for (int i = 0; i < MAX_JOGADOR_PARTIDA; i++)
    {   
        scanf("%d:",&partida.jogadores[i].id);
        partida.jogadores[i]=leJogador(partida.jogadores[i].id);
    }
    
    return partida;
}

Jogador buscaJogadorRegistro(Registro r, int idJog)
{
    for (int i = 0; i < MAX_JOGADOR_PARTIDA; i++)
    {
        if (r.jogadores[i].id==idJog)
        {
            return r.jogadores[i];
        }
        else
        {
            if (i==4)
            {
                Jogador novoJog;
                novoJog=inicializaJogador(novoJog.id);
                novoJog.id=-1;
                return novoJog;
            }
            
        }
    }
    
}
