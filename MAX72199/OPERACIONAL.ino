#include <FC16.h>

const int csPin = D4; //Conexao do pino CS
const int numDisp = 8; //Numero de displays que estamos usando
const int scrollDelay = 100; //Tempo do scroll em milisegundos

FC16 display = FC16(csPin, numDisp);

void setup() 
{
 display.begin(); //Inicializa o display
 display.setIntensity(2); //Intensidade / Brilho
 display.clearDisplay(); //Apaga o display
 display.setText("Lab+ Projetos"); //Texto a ser exibido no display

}

void loop() 
{
 display.update(); //Chama a rotina de scroll
 delay(scrollDelay); //Aguarda o tempo definido

}
