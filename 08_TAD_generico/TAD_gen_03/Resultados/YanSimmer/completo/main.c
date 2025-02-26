#include "relatorio.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main()
{
    int vecTam;
    scanf("%d\n",&vecTam);
    Vector *alunos;
    alunos=VectorConstruct();
    tAluno *aluno;
    
    for (int i = 0; i < vecTam; i++)
    {   aluno=CriaAluno();
        LeAluno(aluno);
        VectorPushBack(alunos,(tAluno*)aluno);
    }
    
    



    ImprimeRelatorio(alunos);
    VectorDestroy(alunos,(tAluno*)DestroiAluno);
    return 0;
}