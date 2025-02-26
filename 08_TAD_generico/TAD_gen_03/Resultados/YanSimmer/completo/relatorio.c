#include "relatorio.h"
#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/
void ImprimeRelatorio(Vector *alunos)
{
    float media=0,percentAprov=0,percentMasc=0,percentFem=0,percentOther=0;
    for (int i = 0; i < VectorSize(alunos); i++)
    {
        media+=GetNotaAluno(VectorGet(alunos,i));
        if (GetGeneroAluno(VectorGet(alunos,i))=='F')
        {
            percentFem++;
        }
        else if (GetGeneroAluno(VectorGet(alunos,i))=='M')
        {
            percentMasc++;
        }
        else if (GetGeneroAluno(VectorGet(alunos,i))=='O')
        {
            percentOther++;
        }
        if (GetNotaAluno(VectorGet(alunos,i))>=6)
        {
            percentAprov++;
        }
        
        
    }
    media/=VectorSize(alunos);
    percentAprov= (percentAprov/VectorSize(alunos))*100;
    percentFem= (percentFem/VectorSize(alunos))*100;
    percentMasc= (percentMasc/VectorSize(alunos))*100;
    percentOther= (percentOther/VectorSize(alunos))*100;

/*     Media das notas: 5.44
    Porcentagem de alunos aprovados: 60.00%
    Porcentagem de cada genero:
    Masculino: 40.00%
    Feminino: 20.00%
    Outro: 40.00% */
    char percent='%';

    printf("Media das notas: %.2f\n",media);
    printf("Porcentagem de alunos aprovados: %.2f%c\n",percentAprov,percent);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%c\n",percentMasc,percent);
    printf("Feminino: %.2f%c\n",percentFem,percent);
    printf("Outro: %.2f%c\n",percentOther,percent);
}

