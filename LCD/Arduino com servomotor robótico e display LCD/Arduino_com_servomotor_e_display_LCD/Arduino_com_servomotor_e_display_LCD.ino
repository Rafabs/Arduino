/***********************************************************************************************
 * EXEMPLO DE APLICAÇÃO USANDO SERVO COM DISPLAY LCD                                           *
 * BY: LAB+ PROJETOS - 18.04.18 - UPDATE: 05.07.21                                             *
 * ><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><*
 * VARIÁVEL: const = define = const int (VARIÁVEL QUE POSSUI UM VALOR FIXO, "APENAS-LEITURA".) *
 ***********************************************************************************************/
#include "LiquidCrystal.h"                                      //Biblioteca para uso do LCD 
#include "Servo.h"                                              //Biblioteca para uso do Servo
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7= 2;      //Declaração dos pinos para serem usados no LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);                      //Declaração dos pinos para serem usados no LCD
Servo servoMotorObj;                                            //Cria o objeto servo
int const potenciometroPin = 0;                                 //Variável para ajustar o ângulo inicial com o Potenciômetro
int const servoMotorPin = 12;                                   //Variável para o pino do Servo
int valPotenciometro;                                           //Variável usada para armazenar o valor lido no potenciômetro
 
void setup() 
{
  lcd.begin(20, 4);                                             //Tipo de display LCD  
  servoMotorObj.attach(servoMotorPin);                          //Declara o pino do servo
}
 
void loop() 
{   
  valPotenciometro = analogRead(potenciometroPin);              //Lendo o valor do potenciômetro (intervalo entre 0 e 1023)
  valPotenciometro = map(valPotenciometro, 0, 1023, 0, 180);    //Re-mapeia um número de um intervalo para outro (value, fromLow, fromHigh, toLow, toHigh)
  servoMotorObj.write(valPotenciometro);                        //Escreve e atualiza na variável o valor atual  
  lcd.clear();                                                  //Limpa o display  
  lcd.setCursor(0,1);                                           //Posição do texto a ser exibido
  lcd.print("Servomotor");                                      //Exibe o texto no LCD
  if (valPotenciometro < 90)                                    //Se o valor lido na variável for menor do que 90:
  {
    lcd.print("Lado direito");                                  //Exibe o texto no LCD
  }   
  if (valPotenciometro == 90)                                   //Se o valor lido na variável for 90:
  {
    lcd.print("Centro");                                        //Exibe o texto no LCD
  }     
  if (valPotenciometro > 90)                                    //Se o valor lido na variável for maior do que 90:
  {
    lcd.print("Lado esquerdo");                                 //Exibe o texto no LCD
  }  
  delay(30);                                                    //Aguarda 30ms.
}
