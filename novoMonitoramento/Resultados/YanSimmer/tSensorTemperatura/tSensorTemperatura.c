#include <stdio.h>
#include "tSensorTemperatura.h"
#include <stdlib.h>
#include "tMonitorador.h"
struct _tSensorTemperatura
{   
    int id;
    int tempMin;
    int tempMax;
    int onOff;
};

/***
Le as configuracoes de um sensor de temperatura da entrada padrao e retorna um sensor valido com
o id recebido como parametro. O sensor servira para controlar um ar que inicialmente esta desligado.
Configuracoes serao dadas em uma linha seguindo "#MIN #MAX"
#MIN sendo a temperatura limite minima para desligar o AR ao ficar abaixo dela
#MAX sendo a temperatura limite maxima para ligar o AR ao ficar acima dela
*/
tSensorTemperatura *leSensorTemperatura(int id)
{
    tSensorTemperatura *createdSensor = (tSensorTemperatura*)malloc(sizeof(tSensorTemperatura));
    createdSensor->id=id;
    createdSensor->onOff=0;
    scanf("%d %d\n",&createdSensor->tempMin,&createdSensor->tempMax);
    return createdSensor;
}

/***
Dado um sensor de temperatura valido, libera sua memoria
*/
void liberaSensorTemperatura(void *s)
{
    tSensorTemperatura *destruidorTemp =(tSensorTemperatura*)s;
    
    free(destruidorTemp);
}

/***
Dado um sensor de temperatura valido, faz a leitura da temperatura ambiente do sensor fisico e
controla o estado do ar condicionado
A leitura do sensor de temperatura sera simulada aqui por uma leitura de um inteiro da entrada padrao
O controle do estado do ar condicionado sera simulado aqui com uma impressao em uma linha da saida padrao sendo
    "SENSOR(#ID)[#MIN-#MAX] processando TEMP:#T\n" em que #ID eh o id do sensor,
    #MIN e #MAX sao conforme definidos acima e #T eh a temperatura lida do sensor fisico, seguida de
    "(DESLIGANDO AR)" para representar que o ar deve desligar ao ficar abaixo da temperatura minima e estava ligado
    "(LIGANDO AR)" para representar que o ar deve ligar ao ficar acima da temperatura maxima e estiver desligado
    "(MANTEM AR)" caso contrario
*/
void processaSensorTemperatura(void *s)
{   int tempatual;
    tSensorTemperatura *sensor=(tSensorTemperatura*)s;
    scanf("%d\n",&tempatual);
    printf("SENSOR(%d)[%d-%d] processando TEMP:%d",sensor->id,sensor->tempMin,sensor->tempMax,tempatual);
    if (tempatual>sensor->tempMax&&sensor->onOff==0)
    {
        printf("(LIGANDO AR)\n");
        sensor->onOff=1;
    }
    else if (tempatual<sensor->tempMin&&sensor->onOff==1)
    {
        printf("(DESLIGANDO AR)\n");
        sensor->onOff=0;
    }
    else
    {
        printf("(MANTEM AR)\n");
    }
}