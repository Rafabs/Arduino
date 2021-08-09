/***********************************************************************************************
 * EXEMPLO DE APLICAÇÃO USANDO Servo Motor SG90                                                *
 * BY: LAB+ PROJETOS - 22.01.21 - UPDATE: 02.07.21                                             *
 ***********************************************************************************************/
#include <Servo.h>                              //Biblioteca para uso do Servo
Servo meuservo;                                 //Cria o objeto servo
int angulo = 0;                                 //Variável para ajustar o ângulo inicial 

void setup() 
{
meuservo.attach(9);                            //Declara o pino do servo
}

void loop() 
{
  for (angulo = 0; angulo < 180; angulo += 1)   //Comando que muda a posição do servo de 0 para 180°
  { 
    meuservo.write(angulo);                     //Comando para angulo específico
    delay(15);                                  //Aguarda 15ms
  } 
delay(2000);                                    //Aguarda 2s
}
