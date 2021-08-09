/***********************************************************************************************
 * EXEMPLO DE APLICAÇÃO USANDO LCD ALFANUMÉRICO                                                *
 * BY: LAB+ PROJETOS - 14.12.20 - UPDATE: 02.07.21                                             *
 * ><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><*
 * VARIÁVEL: const = define = const int (VARIÁVEL QUE POSSUI UM VALOR FIXO, "APENAS-LEITURA".) *
 ***********************************************************************************************/
#include <LiquidCrystal.h>                                 //Biblioteca para uso do LCD 

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7= 2; //Declaração dos pinos para serem usados no LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);                 //Declaração dos pinos para serem usados no LCD

void setup() 
{
  lcd.begin(16,2);                                         //Tipo de display LCD  
}

void loop() 
{
  lcd.setCursor(0,1);                                      //Posição do texto a ser exibido
  lcd.print("LAB+ PROJETOS");                              //Exibe o texto no LCD
  delay (2000);                                            //Aguarda 2s.
  lcd.clear();                                             //Limpa o display
  lcd.setCursor(0,1);                                      //Posição do texto a ser exibido
  lcd.print("");                                           //Exibe o texto no LCD
  delay (500);                                             //Aguarda 500ms.
}
