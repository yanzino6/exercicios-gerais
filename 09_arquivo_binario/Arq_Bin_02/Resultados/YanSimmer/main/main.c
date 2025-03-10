#include "base_alunos.h"
#include "aluno.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arquivo[100];
    scanf("%[^\n]\n", arquivo);
    tBaseAlunos *novaBase = CriarBaseAlunos();
    LerBaseAlunos(novaBase, arquivo);
    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f",GetCoeficienteRendimentoMedioBaseAlunos(novaBase));
    DestruirBaseAlunos(novaBase);
    return 0;
}