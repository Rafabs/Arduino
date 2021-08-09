/***********************************************************************************************
 * EXEMPLO DE APLICAÇÃO USANDO MÓDULO OLED 0,96" (Desenho de Retangulo)                        *
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
  display.drawRect (100, 10, 20, 20, WHITE);                              //Retângulo Comum (Start X, Start Y, Widht, Height, Color)
  display.fillRect (10, 10, 45, 15, WHITE);                               //Retângulo Preenchido (Start X, Start Y, Widht, Height, Color)
  display.drawRoundRect (60, 20, 35, 35, 8, WHITE);                       //Retângulo Arredondado (Start X, Start Y, Widht, Height, Radius, Color)
  display.display ();                                                     //Atualiza a representação na memória, chamado para ligar o display
  delay(1000);                                                            //Aguarda 1s
}
