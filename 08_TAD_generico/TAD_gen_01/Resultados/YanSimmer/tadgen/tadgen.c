#include "tadgen.h"
#include <stdio.h>
struct generic{
    Type type;     
    int numElem;   
    void* data;    
} ;

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 */
tGeneric* CriaGenerico(Type type, int numElem) {
    tGeneric* gen = (tGeneric*) malloc(sizeof(tGeneric));
    if (gen == NULL) {
        printf("Erro ao alocar memoria para tGeneric\n");
        exit(1);
    }

    gen->type = type;
    gen->numElem = numElem;

    // Alocação dinâmica com base no tipo
    if (type == INT) {
        gen->data = malloc(numElem * sizeof(int));
    } else {
        gen->data = malloc(numElem * sizeof(float));
    }

    if (gen->data == NULL) {
        printf("Erro ao alocar memoria para os dados\n");
        free(gen);
        exit(1);
    }

    return gen;
}

/**
 * @brief Destroi o vetor genérico e libera memória
 */
void DestroiGenerico(tGeneric* gen) {
    if (gen != NULL) {
        free(gen->data);
        free(gen);
    }
}

/**
 * @brief Lê o conteúdo do vetor genérico e armazena no local adequado
 */
void LeGenerico(tGeneric* gen) {
    if (gen == NULL || gen->data == NULL) return;

    printf("\nDigite o vetor:\n");

    if (gen->type == INT) {
        int* intData = (int*) gen->data;
        for (int i = 0; i < gen->numElem; i++) {
            scanf("%d", &intData[i]);
        }
    } else {
        float* floatData = (float*) gen->data;
        for (int i = 0; i < gen->numElem; i++) {
            scanf("%f", &floatData[i]);
        }
    }
}

/**
 * @brief Imprime o vetor genérico na tela
 */
void ImprimeGenerico(tGeneric* gen) {
    if (gen == NULL || gen->data == NULL) return;

    

    if (gen->type == INT) {
        int* intData = (int*) gen->data;
        for (int i = 0; i < gen->numElem; i++) {
            printf("%d ", intData[i]);
        }
    } else {
        float* floatData = (float*) gen->data;
        for (int i = 0; i < gen->numElem; i++) {
            printf("%.2f ", floatData[i]);
        }
    }
    printf("\n");
}