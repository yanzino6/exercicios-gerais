#include "banco.h"
#include <stdio.h>
#include <stdlib.h>
#include "conta.h"
struct Banco
{
    Vector *Agencias;
    char nome[51];
};

/**
 * @brief Função para criar um novo banco.
 * @return Um ponteiro para o novo banco criado. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tBanco *CriaBanco()
{
    tBanco *bancoCriado = (tBanco*)malloc(sizeof(tBanco));
    if (bancoCriado==NULL)
    {
        printf("Erro de alocação");
        exit(1);
    }
    bancoCriado->Agencias=VectorConstruct();
    return bancoCriado;
}

/**
 * @brief Função para destruir um banco.
 * @param banco O banco a ser destruído.
 */
void DestroiBanco(tBanco *banco)
{
    VectorDestroy(banco->Agencias,DestroiAgencia);
    free(banco);
}

/**
 * @brief Função para ler o nome de um banco.
 * @param banco O banco a ser lido.
 */
void LeBanco(tBanco *banco)
{
    scanf("%[^\n]\n",banco->nome);
}

/**
 * @brief Função para adicionar uma agência a um banco.
 * @param banco O banco.
 * @param agencia A agência a ser adicionada.
 */
void AdicionaAgencia(tBanco *banco, tAgencia *agencia)
{
    VectorPushBack(banco->Agencias,(tAgencia *)agencia);
}

/**
 * @brief Função para inserir uma conta em uma agência pertencente ao banco.
 * @param banco O banco.
 * @param numAgencia O número da agência.
 * @param cliente A conta a ser inserida.
 * @pre A agência deve pertencer ao banco.
*/
void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente)
{
    for (int i = 0; i < VectorSize(banco->Agencias); i++)
    {
        if (ComparaAgencia(numAgencia,(tAgencia*)VectorGet(banco->Agencias,i))==1)
        {
            AdicionaConta((tAgencia*)VectorGet(banco->Agencias,i),cliente);
        }
        
    }
    
}

/**
 * @brief Função para imprimir o relatório de um banco, com o nome do banco e a lista de agências.
 * @param banco O banco.
 */
void ImprimeRelatorioBanco(tBanco *banco)
{
    printf("%s\n",banco->nome);
    printf("Lista de agencias:\n");
    for (int i = 0; i < VectorSize(banco->Agencias); i++)
    {
        ImprimeDadosAgencia((tAgencia*)VectorGet(banco->Agencias,i));
    }
    
}
