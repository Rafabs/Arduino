/***********************************************************************************************
 * EXEMPLO DE APLICAÇÃO USANDO  Sensor HC-SR04                                                 *
 * BY: LAB+ PROJETOS - 22.01.21 - UPDATE: 02.07.21                                             *
 ***********************************************************************************************/
#include <Ultrasonic.h>                                                 //Biblioteca para uso do LCD 
#define pino_trigger 4                                                  //Define o pino 4 como trigger
#define pino_echo 5                                                     //Define o pino 5 como cho
Ultrasonic ultrasonic(pino_trigger, pino_echo);                         //Cria objeto ulstrassic e inicializa nos pinos definidos.
float cmMsec, inMsec;                                                   //Variável para ler as informações do sensor, em cm e pol
 
void setup()
{
  Serial.begin(9600);                                                   //Monitor Serial
  Serial.println("Lendo dados do sensor...");                           //Exibe o texto na Serial
}
 
void loop()
{
  long microsec = ultrasonic.timing();                                  //Variável para definir o tempo em ms igual o do sensor
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);                //Converte os dados em ms para cm
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);                //Converte os dados em ms para pol
  Serial.print("Distancia em cm: ");                                    //Exibe o texto na Serial
  Serial.print(cmMsec);                                                 //Exibe a variável na Serial
  Serial.print(" - Distancia em polegadas: ");                          //Exibe o texto na Serial
  Serial.println(inMsec);                                               //Exibe a variável na Serial
  delay(1000);                                                          //Aguarda 1s
}
  
