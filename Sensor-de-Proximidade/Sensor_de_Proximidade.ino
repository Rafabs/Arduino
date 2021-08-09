/***********************************************************************************************
 * EXEMPLO DE APLICAÇÃO DE SENSOR DE PROXIMIDADE                                               *
 * BY: LAB+ PROJETOS - 23.11.19 - UPDATE: 05.07.21                                             *
 ***********************************************************************************************/
#include <Tone.h>                             //Biblioteca para uso do Buzzer
int IRpin = A0;                               //Declaração do pino para ser usado no Sensor Infravermelho
int IRval= 0;                                 //Variável para medir a distância do sinal
int threshold = 100;                          //Variável para ativar o Sensor Infravermelho
int error = 10;                               //Variável para situações de erros por excesso de tempo
int temp[20] = {0};                           //Variável para armazenar as amostras no tempo
int x = 0;                                    //Variável para armazenar as amostras atreladas a 'temp'
int aproximacao= 0;                           //Variável para aproximação do objeto
int recuando = 0;                             //Variável para recuo do objeto
int last = 0;                                 //Variável para as últimas amostras
int derivative = 0;                           //Variável para derivativas das amostras
Tone player;                                  //Cria o objeto Tone com nome player
int note[] = {NOTE_A3,NOTE_G4};               //Variável para lista de Notas
int led_verde = 2;                            //Define a variável led verde como pino 2
int led_vermelho = 3;                         //Define a variável led vermelho como pino 3

void setup()
{
  Serial.begin(9600);                         //Monitor Serial na velocidade de 9600
  pinMode(led_verde, OUTPUT);                 //Declara o pino do LED verde como saída
  pinMode(led_vermelho, OUTPUT);              //Declara o pino do LED vermelho como saída
  player.begin(11);                           //Inicializa o buzzer 
}

void loop()
{
  if(analogRead(IRpin)>=threshold)            //Se o valor lido do sensor for igual ou maior do que 100:
  {
    do                                        //Faz
    {
      IRval=analogRead(IRpin);                //Atualiza o valor de IRval igual ao valor lido de IRpin
      derivative = IRval - last;              //Atualiza o valor do derivativo para (IRval menos last)
      last = IRval;                           //Atualiza o valor de last igual ao valor de IRval
      temp[x]=derivative;                     //Armazena o valor de temp e x igual ao do detivativo
      Serial.println(temp[x]);                //Exibe o texto na Serial
      x++;                                    //Começa a adicionar 1 até o valor ser maior ou igual a condição proposta (Linha 33)  
      delay(75);                              //Aguarda 75ms.
    }
  while(x<20);                                //Enquanto X for menor do que 20:
  x=0;                                        //Atualiza o valor de X para 0
  for(x=0;x<20;x++)                           //Para x igual a 0 e menor do 20, adiciona 1
  {                                   
    if(temp[x]>=error)                        //Se o valor da amostra 'x' for maior do que o valr da variável 'erro':
    {
      aproximacao=aproximacao+1;              //Atualiza o valor de 'aproximacao' para o próprio valor + 1
    }
    if(temp[x]<-error)                        //Se o valor da amostra 'x' for menor do que o valr da variável 'erro':
    {
      recuando=recuando+1;                    //Atualiza o valor de 'recuando' para o próprio valor + 1
    }
  }
  Serial.print("Aproximando =");              //Exibe o texto na Serial
  Serial.println(aproximacao);                //Exibe o valor da variável
  Serial.print("Recuando =");                 //Exibe o texto na Serial
  Serial.println(recuando);                   //Exibe o valor da variável
  if(aproximacao>recuando && aproximacao>3)   //Se o valor de 'aproximacao' for maior do que 'recuando' e 'aproximacao' for maior do que 3: (&& = 'e')
  {
    Serial.println("Aproximando");            //Exibe o texto na Serial
    digitalWrite(led_verde, HIGH);            //LED verde, LIGADO
    player.play(note[0]);                     //Executa a nota no Buzzer
    delay(200);                               //Aguarda 200ms.
    player.play(note[1]);                     //Executa a nota no Buzzer
    delay(200);                               //Aguarda 200ms.
    player.stop();                            //Desliga o buzzer
  }
  else if(recuando>aproximacao && recuando>3) //
  {   
    Serial.println("Recuando");               //Exibe o texto na Serial
    digitalWrite(led_vermelho, HIGH);         //LED vermelho, LIGADO
    player.play(note[1]);                     //Executa a nota no Buzzer
    delay(200);                               //Aguarda 200ms.
    player.play(note[0]);                     //Executa a nota no Buzzer
    delay(200);                               //Aguarda 200ms.
    player.stop();                            //Desliga o buzzer
  }
  delay(200);                                 //Aguarda 200ms.
  digitalWrite(led_verde, LOW);               //LED verde, DESLIGADO
  digitalWrite(led_vermelho, LOW);            //LED vermelho, DESLIGADO
  }
}
