#include "conta.h"
#include <stdio.h>

struct Conta
{
    int nConta;
    char nome[51];
    float saldo;

};


/**
 * @brief Função para criar uma nova conta bancária.
 * @return Um ponteiro para a nova conta bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tConta *CriaConta()
{
    tConta *contaCriada = (tConta*) malloc(sizeof(tConta));
    if (contaCriada==NULL)
    {
        printf("Erro de alocação");
        exit(1);
    }
    
    return contaCriada;
}

/**
 * @brief Função para destruir uma conta bancária.
 * @param conta A conta bancária a ser destruída.
 */
void DestroiConta(DataType conta)
{   
    tConta *destroiConta = (tConta*)conta;

    
    free(destroiConta);
}

/**
 * @brief Função para ler uma conta bancária no formato "numero;nome do cliente;saldo inicial".
 * @param conta A conta bancária a ser lida.
 */
//1;Goku;1500.21
void LeConta(tConta *conta)
{
    scanf("%d;%[^;];%f\n",&conta->nConta,conta->nome,&conta->saldo);
}

/**
 * @brief Função para obter o saldo de uma conta bancária.
 * @param conta A conta bancária.
 * @return O saldo da conta bancária.
 */
float GetSaldoConta(tConta *conta)
{
    return conta->saldo;
}