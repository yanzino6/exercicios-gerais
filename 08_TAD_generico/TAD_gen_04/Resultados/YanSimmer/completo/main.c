#include "banco.h"
#include "conta.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    tBanco *banco=CriaBanco();
    tAgencia *agencia;
    
    tConta *conta;
    LeBanco(banco);
    int numAgencia;
    char op;
    while (1)
    {
        scanf("%c\n",&op);
        if (op=='F')
        {
            break;
        }
        else if (op=='A')
        {   agencia=CriaAgencia();
            LeAgencia(agencia);
            AdicionaAgencia(banco,agencia);
        }
        else if (op=='C')
        {   conta=CriaConta();
            LeConta(conta);
            scanf("%d\n",&numAgencia);
            InsereContaBanco(banco,numAgencia,conta);
        }
        
    }
    
    ImprimeRelatorioBanco(banco);

    DestroiBanco(banco);
    return 0;
}