#include "vector.h"
#include <stdio.h>

struct Vector{
    DataType *data;
    int tam;
    int cap;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct()
{
    Vector *vetorCriado;
    vetorCriado=(Vector*)malloc(sizeof(Vector));
    vetorCriado->tam=0;
    vetorCriado->cap=4;
    vetorCriado->data=(DataType*)malloc(vetorCriado->cap*sizeof(DataType));
    return vetorCriado;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val)
{
    if (v->cap==v->tam)
    {
        v->cap*=2;
        v->data=(DataType*)realloc(v->data,v->cap*sizeof(DataType));
    }
    v->data[v->tam]=val;
    v->tam++;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i)
{
    return v->data[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v)
{
    return v->tam;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType))
{
    for (int i = 0; i < v->tam; i++)
    {
        destroy(v->data[i]);
    }
    free(v->data);
    free(v);
}