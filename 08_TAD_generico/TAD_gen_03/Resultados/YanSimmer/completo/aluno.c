#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
struct Aluno{
    float nota;
    char nome[51];
    char genero;
};

/**
 * @brief Aloca memoria para um aluno
 * 
 * @return A estrutura tAluno inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
tAluno *CriaAluno()
{
    tAluno *alunoCriado=(tAluno*) malloc(sizeof(tAluno));
    if (alunoCriado==NULL)
    {
        exit(1) ;
    }
    
    return alunoCriado;
}

/**
 * @brief Libera a memoria alocada para um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * Dica: Foi usado data_type para generalizar a funcao e usar na estrutura Vector. Por isso, é necessário fazer um cast para tAluno* dentro da função.
*/
void DestroiAluno(data_type aluno)
{
    tAluno *aluno_ptr = (tAluno *) aluno;
    free(aluno_ptr);
}

/**
 * @brief Le os dados de um aluno
 * 
 * @param aluno Ponteiro para o aluno
*/
//Goku;M;3
void LeAluno(tAluno *aluno)
{
    scanf("%[^;];%c;%f\n",aluno->nome,&aluno->genero,&aluno->nota);
}

/**
 * @brief Retorna o genero de um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * @return char Genero do aluno
*/
char GetGeneroAluno(tAluno *aluno)
{
    return aluno->genero;
}

/**
 * @brief Retorna a nota de um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * @return float Nota do aluno
*/
float GetNotaAluno(tAluno *aluno)
{
    return aluno->nota;
}
