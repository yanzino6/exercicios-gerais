#include "base_alunos.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BaseAlunos{
    tAluno **alunos;
    int cap;
};

/**
 * @brief Função para criar uma nova base de alunos.
 * 
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos* CriarBaseAlunos()
{
    tBaseAlunos *createdBase=(tBaseAlunos*)malloc(sizeof(tBaseAlunos));
    return createdBase;
}

/**
 * @brief Função para destruir uma base de alunos.
 * 
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos* baseAlunos)
{
    for (int i = 0; i < baseAlunos->cap; i++)
    {
        DestruirAluno(baseAlunos->alunos[i]);
    }
    free(baseAlunos->alunos);
    free(baseAlunos);
}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 * 
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo)
{
    FILE *arq = fopen(nomeArquivo,"rb");
    int cap;
    fread(&cap,sizeof(int),1,arq);
    baseAlunos->cap=cap;
    baseAlunos->alunos=(tAluno**)malloc(baseAlunos->cap*sizeof(tAluno*));
    for (int i = 0; i < baseAlunos->cap; i++)
    {
        baseAlunos->alunos[i]=LeAluno(arq);
    }
    fclose(arq);
}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 * 
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos)
{   
    float coefmedio=0;
    for (int i = 0; i < baseAlunos->cap; i++)
    {
        coefmedio+=GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);
    }
    return coefmedio/=baseAlunos->cap;
}