/***********************************************************************************************
 * EXEMPLO DE APLICAÇÃO USANDO MÓDULO OLED 0,96" (Desenho de Triângulo)                        *
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
  display.clearDisplay ();                                                //Limpa o buffer.
  display.drawTriangle (24, 1, 3, 55, 45, 55, WHITE);                     //Triângulo Comum (x0,y0,x1,y1,x2,y2,color)
  display.fillTriangle (104, 62, 125, 9, 83, 9, WHITE);                   //Triângulo com fundo preenchido (x0,y0,x1,y1,x2,y2,color)
  display.display ();                                                     //Atualiza a representação na memória, chamado para ligar o display
  delay(1000);                                                            //Aguarda 1s
}
