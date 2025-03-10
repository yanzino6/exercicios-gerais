#include "aluno.h"
#include <stdlib.h>
#include <string.h>

struct Aluno{
    char nome[100];
    char dataNasc[11];
    char curso[50];
    float cr;
    int periodo;
};

/**
 * @brief Função para criar um novo aluno.
 * 
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso em que o aluno está matriculado.
 * @param periodo Período do curso em que o aluno está.
 * @param coeficienteRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para o aluno recém-criado. Se houver erro na alocação de memória, o programa é encerrado.
 */
tAluno* CriarAluno(char* nome, char* dataNascimento, char* curso, int periodo, float coeficienteRendimento)
{
    tAluno *createdAluno = (tAluno*)malloc(sizeof(tAluno));
    createdAluno->cr=coeficienteRendimento;;
    strcpy(createdAluno->curso,curso);
    strcpy(createdAluno->nome,nome);
    strcpy(createdAluno->dataNasc,dataNascimento);
    createdAluno->periodo=periodo;
    return createdAluno;
}

/**
 * @brief Função para destruir um aluno.
 * 
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno* aluno)
{
    free(aluno);
}

/**
 * @brief Função para ler um aluno de um arquivo binário.
 * 
 * @param arquivo_binario O arquivo binário para ler o aluno.
 * @return Um ponteiro para o aluno lido.
 */
tAluno *LeAluno(FILE *arquivo_binario)
{
    tAluno *read = CriarAluno("","","",0,0);
    fread (read->nome,sizeof(char),100,arquivo_binario);
    fread (read->dataNasc,sizeof(char),11,arquivo_binario);
    fread (read->curso,sizeof(char),50,arquivo_binario);
    int periodo;
    float cr;
    fread (&periodo,sizeof(int),1,arquivo_binario);
    fread (&cr,sizeof(float),1,arquivo_binario);
    read->cr=cr;
    read->periodo=periodo;
    return read;
}

/**
 * @brief Função para obter o coeficiente de rendimento de um aluno.
 * 
 * @param aluno O aluno para obter o coeficiente de rendimento.
 * @return O coeficiente de rendimento do aluno.
 */
float GetCoeficienteRendimentoAluno(tAluno* aluno)
{
    return aluno->cr;
}