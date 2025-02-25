#include "vector.h"
#include <stdio.h>

struct Vector{
    data_type *data;
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
    Vector *v = (Vector *) malloc(sizeof(Vector));
    if (v == NULL) {
        printf("Erro ao alocar memória para o vetor\n");
        exit(1);
    }
    v->cap=4;
    v->tam=0;
    v->data = (data_type *) malloc(v->cap * sizeof(data_type));
    if (v->data == NULL) {
        printf("Erro ao alocar memória para os dados do vetor\n");
        free(v);
        exit(1);
    }
    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, data_type val)
{
        if (v->tam == v->cap) {
        v->cap *= 2; 
        v->data = (data_type *) realloc(v->data, v->cap * sizeof(data_type));
        }
        v->data[v->tam] = val;
        v->tam++;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return data_type Elemento do vetor
*/
data_type VectorGet(Vector *v, int i)
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
void VectorDestroy(Vector *v, void (*destroy)(data_type))
{
    if (destroy != NULL) {
        for (int i = 0; i < v->tam; i++) {
            destroy(v->data[i]);
        }
    }
    
    free(v->data);
    free(v);
}
