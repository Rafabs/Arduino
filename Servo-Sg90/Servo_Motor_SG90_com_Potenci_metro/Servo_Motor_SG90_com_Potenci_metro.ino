/***********************************************************************************************
 * EXEMPLO DE APLICAÇÃO USANDO Servo Motor SG90 com Potenciômetro                              *
 * BY: LAB+ PROJETOS - 22.01.21 - UPDATE: 02.07.21                                             *
 ***********************************************************************************************/
#include <Servo.h>                              //Biblioteca para uso do Servo
Servo meuservo;                                 //Cria o objeto servo
int angulo = 0;                                 //Variável para ajustar o ângulo inicial 
int potencio = A0;                              //Define a variável potencio como pino A0 
 
void setup() 
{ 
meuservo.attach(9);                             //Declara o pino do servo
}   
 
void loop() 

{
angulo = analogRead(potencio);                  //Faz a leitura do valor do potenciômetro
angulo = map(angulo, 0, 1023, 0, 179);          //Re-mapeia um número de um intervalo para outro (value, fromLow, fromHigh, toLow, toHigh)
meuservo.write(angulo);                         //Escreve na variável angulo o valor mapeado
delay(5);                                       //Aguarda 5ms.
} 
