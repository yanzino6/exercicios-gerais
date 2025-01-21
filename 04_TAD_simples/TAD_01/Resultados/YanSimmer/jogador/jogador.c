#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"
#include "jogada.h"
/**
 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 * 
 * @param idJogador o id do jogador (1 ou 2).
 * 
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador)
{
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}


/**
 * Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada do jogador.
 * 
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return o tabuleiro atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro)
{   printf("Jogador %d\n", jogador.id);
    tJogada jogada = LeJogada();
    if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, jogada.x, jogada.y, jogador.id)==1)
    {
        printf("Posicao invalida (OCUPADA - [%d,%d] )!", jogada.x, jogada.y);
        printf("\n");
    }
    else if (EhPosicaoValidaTabuleiro(jogada.x, jogada.y) == 0)
    {
        printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!", jogada.x, jogada.y);
        printf("\n");
    }
    else  if (jogada.sucesso == 0)
    {
        printf("Jogada invalida!");
        printf("\n");
    }
    else
    {
    printf("Jogada [%d,%d]!", jogada.x, jogada.y);
    printf("\n");
    tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, jogada.x, jogada.y);
    }
    return tabuleiro;
}


/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso contrário.
 * 
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j, i, jogador.id))
            {
                if (i == 0)
                {
                    if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j, i+1, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j, i+2, jogador.id))
                    {
                        return 1;
                    }
                }   
                if (j == 0)
                {
                    if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j+1, i, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j+2, i, jogador.id))
                    {
                        return 1;
                    }
                }
                if (i == 0 && j == 0)
                {
                    if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j+1, i+1, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j+2, i+2, jogador.id))
                    {
                        return 1;
                    }
                }
                if (i == 0 && j == 2)
                {
                    if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j-1, i+1, jogador.id) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j-2, i+2, jogador.id))
                    {
                        return 1;
                    }
                }
                
                
                
                
            }
        }
        
        return 0;
    }
    
    
    
}
