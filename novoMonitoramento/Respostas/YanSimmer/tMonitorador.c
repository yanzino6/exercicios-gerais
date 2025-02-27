#include "tMonitorador.h"
#include <stdio.h>
#include <stdlib.h>

/*  typedef void (*FptrProcessaElemento)(void *e);
    typedef void (*FptrLiberaElemento)(void *e); */


struct _tMonitorador{

    void **monitor;
    int tam;
    int cap;
    FptrLiberaElemento freeElement;
    FptrProcessaElemento processElement;

};



/***
Cria um monitorador valido definindo, de acordo com o tipo de elemento, suas funcoes de
Processar elemento e Liberar elemento
*/
tMonitorador *criaMonitorador(FptrProcessaElemento funcPE, FptrLiberaElemento funcLE)
{
    tMonitorador *createdMonitor = (tMonitorador*)malloc(sizeof(tMonitorador));
    createdMonitor->tam=0;
    createdMonitor->cap=4;
    createdMonitor->freeElement=funcLE;
    createdMonitor->processElement=funcPE;
    createdMonitor->monitor=(void**)malloc(createdMonitor->cap*sizeof(void*));
    return createdMonitor;
}

/***
Dado um monitorador valido, libera sua memoria incluindo a de cada um de seus elementos adicionados
*/
void liberaMonitorador(tMonitorador *m)
{
    for (int i = 0; i < m->tam; i++)
    {
        m->freeElement((m->monitor[i]));
    }
    free(m->monitor);
    free(m);
}

/***
Dado um monitorador valido e um elemento, adiciona o elemento ao cojunto a ser monitorado
*/
void adicionaElementoMonitorador(tMonitorador *m, void *e)
{
    if (m->cap==m->tam)
    {
        m->cap*=2;
        m->monitor=(void**)realloc(m->monitor,m->cap*sizeof(void*));
    }
    m->monitor[m->tam]=e;
    m->tam++;
}

/***
Dado um monitorador valido, inicia o monitoramento que durara pelo numero de ciclos informado em numeroDeCiclos
Se numeroDeCiclos for negativo, o monitoramento sera infinito.
O monitoramento consiste em, a cada ciclo, processar cada elemento registrado para monitoramento
*/
int iniciaMonitoramentotMonitorador(tMonitorador *m, int numeroDeCiclos)
{
    if (numeroDeCiclos>0)
    {
        for (int i = 0; i < numeroDeCiclos; i++)
        {
            for (int j = 0; j < m->tam; j++)
            {
                m->processElement(m->monitor[j]);
            }
            
        }
        
    }
    else if (numeroDeCiclos < 0) {
        while (1) { 
            for (int i = 0; i < m->tam; i++) {
                m->processElement(m->monitor[i]);
            }
        }
    }
    return 0; 
}