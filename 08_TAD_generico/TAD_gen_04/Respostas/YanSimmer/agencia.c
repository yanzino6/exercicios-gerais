#include "agencia.h"
#include <stdio.h>

struct Agencia
{
    Vector *contas;
    int numAgencia;
    char nomeAgencia[51];
};

/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia()
{
    tAgencia *agenciaCriada = (tAgencia*)malloc(sizeof(tAgencia));
    if (agenciaCriada==NULL)
    {
        printf("Erro de alocação");
        exit(1);
    }
    agenciaCriada->contas=VectorConstruct();
    return agenciaCriada;
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia)
{
    tAgencia *destruidorDeAgencias = (tAgencia*)agencia;
    
    VectorDestroy(destruidorDeAgencias->contas, (tConta*)DestroiConta);
    
    
    free(destruidorDeAgencias);
}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia)
{
    scanf("%d;%[^\n]\n",&agencia->numAgencia,agencia->nomeAgencia);
}

/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta)
{
    VectorPushBack(agencia->contas,(tConta*)conta);
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2)
{
    if (numAgencia==agencia2->numAgencia)
    {
        return 1;
    }
    return 0;
}

/**
 * @brief Função para obter o saldo médio das contas de uma agência bancária.
 * @param agencia A agência bancária.
 * @return O saldo médio das contas da agência.
 */
float GetSaldoMedioAgencia (tAgencia *agencia)
{
    float media=0;
    for (int i = 0; i < VectorSize(agencia->contas); i++)
    {
        media+=GetSaldoConta(VectorGet(agencia->contas,i));
    }
    
    return media/VectorSize(agencia->contas);
}

/**
 * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
 * @param agencia A agência bancária.
 */

 /* Nome: Jardim da Penha
 Numero: 110
 Numero de contas cadastradas: 2
 Saldo médio: R$9543.11 */
void ImprimeDadosAgencia(tAgencia *agencia)
{
    printf("    Nome: %s\n",agencia->nomeAgencia);
    printf("    Numero: %d\n",agencia->numAgencia);
    printf("    Numero de contas cadastradas: %d\n",VectorSize(agencia->contas));
    printf("    Saldo médio: R$%.2f\n\n",GetSaldoMedioAgencia(agencia));
}