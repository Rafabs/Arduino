/***********************************************************************************************
 * EXEMPLO DE APLICAÇÃO USANDO MÓDULO OLED 0,96" (Fonte de Texto)                              *
 * BY: LAB+ PROJETOS - 21.01.21 - UPDATE: 02.07.21                                             *
 * ><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><*
 * Fontes:                                                                                     *
 * FreeMono12pt7b.h / FreeSansBoldOblique12pt7b.h / FreeMono18pt7b.h / FreeMono24pt7b.h        *
 * FreeSansBoldOblique18pt7b.h / FreeSansBoldOblique24pt7b.h / FreeMono9pt7b.h                 *
 * FreeSansBoldOblique9pt7b.h / FreeMonoBold12pt7b.h / FreeSansOblique12pt7b.h                 *
 * FreeMonoBold18pt7b.h / FreeSansOblique18pt7b.h / FreeMonoBold24pt7b.h                       *
 * FreeSansOblique24pt7b.h / FreeMonoBold9pt7b.h / FreeSansOblique9pt7b.h                      *
 * FreeMonoBoldOblique12pt7b.h / FreeSerif12pt7b.h / FreeMonoBoldOblique18pt7b.h               *
 * FreeSerif18pt7b.h / FreeMonoBoldOblique24pt7b.h / FreeSerif24pt7b.h / FreeSans12pt7b.h      *
 * FreeMonoBoldOblique9pt7b.h / FreeSerif9pt7b.h / FreeMonoOblique12pt7b.h                     *
 * FreeSerifBold12pt7b.h / FreeMonoOblique18pt7b.h / FreeSerifBold18pt7b.h                     *
 * FreeMonoOblique24pt7b.h / FreeSerifBold24pt7b.h / FreeMonoOblique9pt7b.h                    *
 * FreeSerifBold9pt7b.h / FreeSerifBoldItalic12pt7b.h / FreeSerifItalic9pt7b.h                 *
 * FreeSans18pt7b.h / FreeSerifBoldItalic18pt7b.h / FreeSans24pt7b.h                           *
 * FreeSerifBoldItalic24pt7b.h / FreeSans9pt7b.h / FreeSerifBoldItalic9pt7b.h                  *
 * FreeSansBold12pt7b.h / FreeSerifItalic12pt7b.h / FreeSansBold18pt7b.h                       *
 * FreeSerifItalic18pt7b.h / FreeSansBold24pt7b.h / FreeSerifItalic24pt7b.h                    *
 * FreeSansBold9pt7b.h /                                                                       *
 ***********************************************************************************************/
#include <SPI.h>                                                          //Biblioteca para uso de Sinal Periférico
#include <Wire.h>                                                         //Biblioteca para uso geral    
#include <Adafruit_GFX.h>                                                 //Biblioteca para uso da Adafruit
#include <Adafruit_SSD1306.h>                                             //Biblioteca para uso do SSD1306 OLED
#include <Fonts/FreeSerif9pt7b.h>                                         //Biblioteca para uso da fonte

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
  display.setFont(&FreeSerif9pt7b);                                       //Seleciona a Fonte FreeSerif9pt7b.h
  display.clearDisplay();                                                 //Limpa o buffer.
  display.setTextSize(1);                                                 //Seleciona o tamanho do texto (1=10px. / 2=20px. ...)
  display.setTextColor(WHITE);                                            //Seleciona a cor do Texto
  display.setCursor(0,20);                                                //Seleciona as coordenadas (X,Y)
  display.println("Hello, world!");                                       //Exibe o texto no Display
  display.display();                                                      //Atualiza a representação na memória, chamado para ligar o display
  delay(2000);                                                            //Aguarda 1s
}
