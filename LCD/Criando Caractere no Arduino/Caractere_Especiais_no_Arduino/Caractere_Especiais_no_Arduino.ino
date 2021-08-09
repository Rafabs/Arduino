/***********************************************************************************************
 * EXEMPLO DE APLICAÇÃO CRIANDO CARACTERE ESPECIAL                                             *
 * BY: LAB+ PROJETOS - 23.11.20 - UPDATE: 02.07.21                                             *
 * ><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><*
 * VARIÁVEL: byte = armazena valores numéricos de 8-bit sem sinal, de 0 a 255.                 *
 ***********************************************************************************************/
#include <LiquidCrystal.h>                                 //Biblioteca para uso do LCD 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7= 2; //Declaração dos pinos para serem usados no LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);                 //Declaração dos pinos para serem usados no LCD
byte metro[8] =                                            //Variável de 8 linhas com os pixels em 0/1
{
  B00100,
  B11111,
  B10101,
  B00100,
  B00100,
  B10101,
  B11111,
  B00100,
};

void setup() 
{
  lcd.begin(20, 4);                                        //Tipo de display LCD  
  lcd.createChar(0, metro);                                //Exibe o conteúdo dentro da variável 'metro'
  lcd.setCursor(0,1);                                      //Posição do texto a ser exibido
}

void loop() 
{ 
  lcd.write(1);                                            //Exibe o texto no LCD
  delay(1000);                                             //Aguarda 1s.
  lcd.clear();                                             //Limpa o display
}
