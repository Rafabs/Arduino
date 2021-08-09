/***********************************************************************************************
 * EXEMPLO DE APLICAÇÃO Caracteres Especials no LCD                                            *
 * BY: LAB+ PROJETOS - 20.10.21 - UPDATE: 05.07.21                                             *
 * ><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><*
 * VARIÁVEL: int (Um tipo de dados de número inteiros de até 16 bits)                          *
 ***********************************************************************************************/
#include <LiquidCrystal.h>                                 //Inclui a biblioteca do LCD 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7= 2; //Declaração dos pinos para serem usados no LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);                 //Declaração dos pinos para serem usados no LCD
int i;                                                     //Variável para fazer o deslocamento do conteúdo do LCD

void setup() 
{   
  lcd.begin(20, 4);                                        //Tipo de display LCD  
} 

void loop() 
{   
  lcd.setCursor(0, 3);                                     //Posição do texto a ser exibido
  lcd.print("BUS BRASIL FEST");                            //Exibe o texto no LCD
  lcd.setCursor(0, 2);                                     //Posição do texto a ser exibido   
  lcd.print("#EuUsoEuCuido");                              //Exibe o texto no LCD
  delay(1000);                                             //Aguarda 1s.
  for (i = 0; i < 20; i++)                                 //i começa em 0 e vai adicionando 1 se 'i' for menor que 20
  {     
    lcd.scrollDisplayLeft();                               //Rolamento do texto no LCD para esquerda <--
    delay(20);                                             //Aguarda 20ms.
  }   
  delay(1400);                                             //Aguarda 1,4s.
  lcd.noDisplay();                                         //Não exibe o texto no LCD
  delay(400);                                              //Aguarda 400ms.
  lcd.display();                                           //Exibe o texto no LCD
  delay(400);                                              //Aguarda 400ms.
  lcd.noDisplay();                                         //Não exibe o texto no LCD
  delay(400);                                              //Aguarda 400ms.
  lcd.display();                                           //Exibe o texto no LCD
  delay(400);                                              //Aguarda 400ms.
  lcd.display();                                           //Não exibe o texto no LCD
  delay(400);                                              //Aguarda 400ms.
  for (i = 0; i < 20; i++)                                 //i começa em 0 e vai adicionando 1 se 'i' for menor que 20
  {     
    lcd.scrollDisplayLeft();                               //Rolamento do texto no LCD para esquerda <--
    delay(20);                                             //Aguarda 20ms.
  }  
  lcd.clear();                                             //Limpa o display
}
