/***********************************************************************************************
 * EXEMPLO DE APLICAÇÃO USANDO MÓDULO RTC com o Display LCD 16x2 I2C                           *
 * BY: LAB+ PROJETOS - 22.01.21 - UPDATE: 02.07.21                                             *
 ***********************************************************************************************/
#include <Wire.h>                                                  //Biblioteca para uso geral   
#include <LiquidCrystal_I2C.h>                                     //Biblioteca para uso do LCD 
#define DS1307_ADDRESS 0x68                                        //Cria o objeto RTC no endereco 0x68
LiquidCrystal_I2C lcd(0x27,16,2);                                  //Inicializa o display de 16x2 no endereco 0x27 e cria o objeto lcd
byte zero = 0x00;                                                  //Variável do tipo byte com os dados zerados

void setup()
{
  Wire.begin();                                                    //Monitor Wire                         
  Serial.begin(9600);                                              //Monitor Serial
  lcd.begin (16,2);                                                //Tipo de display LCD  
  lcd.setBacklight(HIGH);                                          //Ativa o backlight 
}

void loop()
{  
  Wire.beginTransmission(DS1307_ADDRESS);                           //Lê os valores (data e hora) do módulo DS1307
  Wire.write(zero);                                                 //Escreve na variável byte os dados lidos no módulo DS1307
  Wire.endTransmission();                                           //Encerra ação
  Wire.requestFrom(DS1307_ADDRESS, 7);                              //Define a solicitação pelo pino 7
  int segundos = ConverteparaDecimal(Wire.read());                  //Variável int para segundos (lido pelo wire na função Conv. p/ dec.)
  int minutos = ConverteparaDecimal(Wire.read());                   //Variável int para minutos (lido pelo wire na função Conv. p/ dec.)
  int horas = ConverteparaDecimal(Wire.read() & 0b111111);          //Variável int para horas (lido pelo wire na função Conv. p/ dec.)
  int diadasemana = ConverteparaDecimal(Wire.read());               //Variável int para diasdasemana (lido pelo wire na função Conv. p/ dec.)
  int diadomes = ConverteparaDecimal(Wire.read());                  //Variável int para diadomes (lido pelo wire na função Conv. p/ dec.)
  int mes = ConverteparaDecimal(Wire.read());                       //Variável int para mes (lido pelo wire na função Conv. p/ dec.)
  int ano = ConverteparaDecimal(Wire.read());                       //Variável int para ano (lido pelo wire na função Conv. p/ dec.)
  lcd.setCursor(0,0);                                               //Posição do texto a ser exibido
  lcd.print("     ");                                               //Exibe o texto no LCD
  if (horas <10)                                                    //Acrescenta o 0 (zero) se a hora for menor do que 10
  {                                                   
    lcd.print("0");                                                 //Exibe o texto no LCD
    lcd.print(horas);                                               //Exibe a variável no LCD
    lcd.print(":");                                                 //Exibe o texto no LCD
  }
  if (minutos < 10)                                                 // Acrescenta o 0 (zero) se minutos for menor do que 10
  {
    lcd.print("0");                                                 //Exibe o texto no LCD
    lcd.print(minutos);                                             //Exibe a variável no LCD
    lcd.setCursor(2,1);                                             //Posição do texto a ser exibido
  }
  switch(diadasemana)                                               //Controle a variável diadasemana
  {                                              
      case 0:lcd.print("Dom");                                      //Caso 0, Exibe o texto no LCD
      break;                                                        //Fim
      case 1:lcd.print("Seg");                                      //Caso 1, Exibe o texto no LCD
      break;                                                        //Fim
      case 2:lcd.print("Ter");                                      //Caso 2, Exibe o texto no LCD
      break;                                                        //Fim
      case 3:lcd.print("Quar");                                     //Caso 3, Exibe o texto no LCD
      break;                                                        //Fim
      case 4:lcd.print("Qui");                                      //Caso 4, Exibe o texto no LCD
      break;                                                        //Fim
      case 5:lcd.print("Sex");                                      //Caso 5, Exibe o texto no LCD
      break;                                                        //Fim
      case 6:lcd.print("Sab");                                      //Caso 6, Exibe o texto no LCD
   }                                     
    lcd.setCursor(6,1);                                             //Exibe o texto no LCD
    if (diadomes < 10)                                              //Acrescenta o 0 (zero) se dia do mes for menor do que 10
    {
      lcd.print("0");                                               //Exibe o texto no LCD
      lcd.print(diadomes);                                          //Exibe o texto no LCD
      lcd.print("/");                                               //Exibe o texto no LCD
    }
    if (mes < 10)                                                   //Acrescenta o 0 (zero) se mes for menor do que 10
    {
      lcd.print("0");                                               //Exibe o texto no LCD
      lcd.print(mes);                                               //Exibe o texto no LCD
      lcd.print("/");                                               //Exibe o texto no LCD
      lcd.print(ano);                                               //Exibe o texto no LCD
    }
}    
void SelecionaDataeHora()                                           //Seta a data e a hora do DS1307 MANUALMENTE
{   
  byte segundos = 20;                                               //Valores de 0 a 59
  byte minutos = 49;                                                //Valores de 0 a 59
  byte horas = 11;                                                  //Valores de 0 a 23
  byte diadasemana = 1;                                             //Valores de 0 a 6 - 0=Domingo, 1 = Segunda, etc.
  byte diadomes = 22;                                               //Valores de 1 a 31
  byte mes = 1;                                                     //Valores de 1 a 12
  byte ano = 21;                                                    //Valores de 0 a 99
  Wire.beginTransmission(DS1307_ADDRESS);                           //Lê os valores (data e hora) do módulo DS1307
  Wire.write(zero);                                                 //Stop no CI para que o mesmo possa receber os dados
  Wire.write(ConverteParaBCD(segundos));                            //Escreve no CI o dado colocado na variável segundos (Linha 84)
  Wire.write(ConverteParaBCD(minutos));                             //Escreve no CI o dado colocado na variável minutos (Linha 85)
  Wire.write(ConverteParaBCD(horas));                               //Escreve no CI o dado colocado na variável horas (Linha 86)
  Wire.write(ConverteParaBCD(diadasemana));                         //Escreve no CI o dado colocado na variável diadasemana (Linha 87)
  Wire.write(ConverteParaBCD(diadomes));                            //Escreve no CI o dado colocado na variável diadomes (Linha 88)
  Wire.write(ConverteParaBCD(mes));                                 //Escreve no CI o dado colocado na variável mes (Linha 89)
  Wire.write(ConverteParaBCD(ano));                                 //Escreve no CI o dado colocado na variável ano (Linha 90)
  Wire.write(zero);                                                 //Escreve na variável zero                                             
  Wire.endTransmission();                                           //Encerra ação
}                                       
  
byte ConverteParaBCD(byte val)                                      //Decimal para BCD (Binary Converter Decimal)
{ 
  return ( (val/10*16) + (val%10) );                                //Retorna os valores pela fórmula
}
  
byte ConverteparaDecimal(byte val)                                  //(Binary Converter Decimal) para decimal
{  
  return ( (val/16*10) + (val%16) );                                //Retorna os valores pela fórmula
}
