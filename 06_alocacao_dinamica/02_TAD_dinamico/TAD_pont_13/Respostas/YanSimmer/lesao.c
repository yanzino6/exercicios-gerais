#include "lesao.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Cria uma estrutura do tipo lesão
 * 
 * @return ponteiro para estrutura do tipo lesão
 */ 
tLesao* CriaLesao()
{
    tLesao *lesaoCriada = (tLesao*) malloc(sizeof(tLesao));
    if(lesaoCriada == NULL)
    {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
    lesaoCriada->id = (char*) malloc(TAM_ID * sizeof(char));
    lesaoCriada->diagnostico = (char*) malloc(TAM_DIAG * sizeof(char));
    lesaoCriada->regiao_corpo = (char*) malloc(TAM_REG * sizeof(char));
    return lesaoCriada;
}

/**
 * @brief Lê informações sobre uma lesão da entrada padrão.
 * 
 * @param l ponteiro para lesão que terá seus dados preenchidos
 */
void LeLesao(tLesao* l)
{
    scanf("%s\n", l->id);
    scanf("%[^\n]\n", l->diagnostico);
    scanf("%[^\n]\n", l->regiao_corpo);
    scanf("%d\n", &l->chance_malignidade);
}

/**
 * @brief Libera a memória alocada para uma estrutura de dados tLesao.
 * 
 * @param l Ponteiro para a estrutura de dados tLesao a ser liberada.
 */
void LiberaLesao(tLesao* l)
{
    free(l->id);
    free(l->diagnostico);
    free(l->regiao_corpo);
    free(l);
}

/**
 * @brief Retorna o identificador da lesão.
 * 
 * @param l Ponteiro para a estrutura de dados tLesao contendo as informações da lesão.
 * @return Retorna uma string contendo o identificador da lesão.
 */
char* GetIdLesao(tLesao* l)
{
    return l->id;
}

/**
 * @brief Verifica se a lesão precisa de cirurgia.
 * 
 * @param l Ponteiro para a estrutura de dados tLesao contendo as informações da lesão.
 * @return Retorna 1 se a lesão precisa de cirurgia e 0 caso contrário.
 */
int PrecisaCirurgiaLesao(tLesao* l)
{
    if(l->chance_malignidade > 50)
    {
        return 1;
    }
    return 0;
}