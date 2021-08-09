/***********************************************************************************************
 * EXEMPLO DE APLICAÇÃO USANDO MÓDULO OLED 0,96" (Rolagem de Texto)                            *
 * BY: LAB+ PROJETOS - 21.01.21 - UPDATE: 02.07.21                                             *
 ***********************************************************************************************/
#include <SPI.h>                                                          //Biblioteca para uso de Sinal Periférico
#include <Wire.h>                                                         //Biblioteca para uso geral    
#include <Adafruit_GFX.h>                                                 //Biblioteca para uso da Adafruit
#include <Adafruit_SSD1306.h>                                             //Biblioteca para uso do SSD1306 OLED
const byte SCREEN_WIDTH = 128;                                            //Define a quantidade de pixels de largura
const byte SCREEN_HEIGHT = 64;                                            //Define a quantidade de pixels de altura
const int OLED_RESET = -1;                                                //Pino de reset (-1) se compartilhar pino de reset Arduino
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); //Cria o objeto display e define a resolução

void setup() 
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);                              //Ligação dos Circuitos Internos, Endereço padrão OLED.
  display.clearDisplay();                                                 //Limpa o buffer.
}

void loop() 
{
  display.clearDisplay();                                                 //Limpa o buffer.
  display.setTextColor(WHITE);                                            //Seleciona a cor do Texto
  display.setTextSize(1);                                                 //Seleciona o tamanho do texto (1=10px. / 2=20px. ...)
  display.setCursor(0, 0);                                                //Seleciona as coordenadas (X,Y)
  display.println("Hello Word!");                                         //Exibe o texto no Display
  delay(1000);                                                            //Aguarda 1s  
  display.startscrollright(0x00, 0x0F);                                   //Rola o texto da esquerda para a direita '-->' (Pos. em HEX) 
  delay(1000);                                                            //Aguarda 1s  
  display.stopscroll();                                                   //Para a rolagem
  delay(1000);                                                            //Aguarda 1s  
  display.startscrollleft(0x00, 0x0F);                                    //Rola o texto da direita para a esquerda '<--' (Pos. em HEX) 
  delay(1000);                                                            //Aguarda 1s  
  display.stopscroll();                                                   //Para a rolagem
  delay(1000);                                                            //Aguarda 1s  
  display.startscrolldiagright(0x00, 0x07);                               //Rola o texto do canto inferior esq. para o canto superior dir.
  delay(1000);                                                            //Aguarda 1s  
  display.startscrolldiagleft(0x00, 0x07);                                //Rola o texto do canto inferior dir. para o canto superior esq.
  delay(1000);                                                            //Aguarda 1s  
  display.stopscroll();                                                   //Para a rolagem
  delay(1000);                                                            //Aguarda 1s  
  display.display();                                                      //Atualiza a representação na memória, chamado para ligar o display
}
