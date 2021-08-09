/***********************************************************************************************
 * EXEMPLO DE APLICAÇÃO USANDO LCD COM MÓDULO I2C                                              *
 * BY: LAB+ PROJETOS - 06.01.21 - UPDATE: 02.07.21                                             *
 ***********************************************************************************************/
#include <Wire.h>                 //Biblioteca para uso geral   
#include <LiquidCrystal_I2C.h>    //Biblioteca para uso do LCD 
LiquidCrystal_I2C lcd(0x27,16,2); //Inicializa o display de 16x2 no endereco 0x27 e cria o objeto lcd
 
void setup()
{
  lcd.init();                     //Inicia o módulo LCD I2C
  lcd.setBacklight(HIGH);         //Ativa o backlight 
}
 
void loop()
{
  lcd.setCursor(0,0);             //Posição do texto a ser exibido
  lcd.print("LAB+ PROJETOS");     //Exibe o texto no LCD
  delay(1000);                    //Aguarda 1s
  lcd.clear();                    //Limpa o display
  lcd.setCursor(0,1);             //Posição do texto a ser exibido
  lcd.print("LCD e modulo I2C");  //Exibe o texto no LCD
  delay(1000);                    //Aguarda 1s
}
