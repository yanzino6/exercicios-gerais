#include "tMonitorador.h"
#include "tSensorPresenca.h"
#include "tSensorTemperatura.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{   
    tMonitorador *sensores;
    int quantSensores,ciclos,comando;
    FptrLiberaElemento libera;
    FptrProcessaElemento processa;
    
    char tipoSensor;
    scanf("%c\n",&tipoSensor);
    scanf("%d\n",&quantSensores);
    if (tipoSensor=='P')
    {
        processa=processaSensorPresenca;
        libera=liberaSensorPresenca;
        sensores=criaMonitorador(processa,libera);
        for (int i = 0; i < quantSensores ; i++)
    {
        
        adicionaElementoMonitorador(sensores,leSensorPresenca(i+1));
    }
    }
    else if (tipoSensor='T')
    {
        processa=processaSensorTemperatura;
        libera=liberaSensorTemperatura;
        sensores=criaMonitorador(processa,libera);
        for (int i = 0; i < quantSensores ; i++)
    {
        
        adicionaElementoMonitorador(sensores,leSensorTemperatura(i+1));
    }
    }
    scanf("%d\n",&ciclos);
    iniciaMonitoramentotMonitorador(sensores,ciclos/quantSensores);
    liberaMonitorador(sensores);
    return 0;
    
    
    
    
}