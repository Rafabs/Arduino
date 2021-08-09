/***********************************************************************************************
 * EXEMPLO DE APLICAÇÃO USANDO LED RGB                                                         *
 * BY: LAB+ PROJETOS - 22.03.18 - UPDATE: 05.07.21                                             *
 ***********************************************************************************************/
int tempo = 500;                  //Variável para controle do tempo chamado pelo delay
int tempo1 = 50;                  //Variável para controle do tempo chamado pelo delay
int led_vermelho = 11;            //Define a variável do LED vermelho no pino 11
int led_verde = 10;               //Define a variável do LED verde    no pino 10
int led_amarelo = 9;              //Define a variável do LED amarelo  no pino 9

void setup() 
{
  pinMode(led_vermelho, OUTPUT);  //Declara o pino do LED vermelho como saída
  pinMode(led_amarelo, OUTPUT);   //Declara o pino do LED amarelo como saída
  pinMode(led_verde, OUTPUT);     //Declara o pino do LED verde como saída
}

void loop() 
{
  digitalWrite(led_vermelho,1);   //LED vermelho, LIGADO
  delay(tempo);                   //Aguarda 500ms.
  digitalWrite(led_vermelho,0);   //LED vermelho, DESLIGADO
  delay(tempo1);                  //Aguarda 50ms.
  digitalWrite(led_amarelo,1);    //LED amarelo, LIGADO
  delay(tempo);                   //Aguarda 50ms.
  digitalWrite(led_amarelo,0);    //LED amarelo, DESLIGADO
  delay(tempo1);                  //Aguarda 500ms.
  digitalWrite(led_verde,1);      //LED verde, LIGADO
  delay(tempo);                   //Aguarda 50ms.
  digitalWrite(led_verde,0);      //LED verde, DESLIGADO
  delay(tempo1);                  //Aguarda 500ms.
}
