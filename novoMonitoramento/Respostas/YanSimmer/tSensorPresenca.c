#include "tSensorPresenca.h"
#include <stdio.h>
#include <stdlib.h>

struct _tSensorPresenca{
    int tempoNoti;
    int id;
    int lastNoti;
    int notis;
};

/***
Le as configuracoes de um sensor de temperatura da entrada padrao e retorna um sensor valido com
o id recebido como parametro. O sensor servira para controlar um ar que inicialmente esta desligado.
Configuracoes serao dadas em uma linha seguindo "#MIN #MAX"
#MIN sendo a temperatura limite minima para desligar o AR ao ficar abaixo dela
#MAX sendo a temperatura limite maxima para ligar o AR ao ficar acima dela
*/
tSensorPresenca *leSensorPresenca(int id)
{
    tSensorPresenca *createdSensor=(tSensorPresenca*)malloc(sizeof(tSensorPresenca));
    createdSensor->id=id;
    scanf("%d\n",&createdSensor->tempoNoti);
    createdSensor->lastNoti=0;
    createdSensor->notis=0;
    return createdSensor;
}

/***
Dado um sensor de temperatura valido, libera sua memoria
*/
void liberaSensorPresenca(void *s)
{
    tSensorPresenca *destroiSensor = (tSensorPresenca*)s;
    free (destroiSensor);
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
void processaSensorPresenca(void *s)
{
    int time,presence;
    tSensorPresenca *sensor=(tSensorPresenca*)s;
    scanf("%d %d\n",&presence,&time);
    printf("SENSOR(%d)[%d] processando PRESENCA:%d e %d",sensor->id,sensor->tempoNoti,presence,time);

    if (sensor->notis==0&&presence==1)
    {
        printf("(NOTIFICA)\n");
        sensor->lastNoti=time;
        sensor->notis++;
    }
    

    else if (time-sensor->lastNoti>sensor->tempoNoti&&presence==1)
    {
        printf("(NOTIFICA)\n");
        sensor->lastNoti=time;
    }
    else
    {
        printf("(AGUARDA)\n");
    }
}