/***********************************************************************************************
 * EXEMPLO DE APLICAÇÃO USANDO Sensor de Umidade Higrômetro                                    *
 * BY: LAB+ PROJETOS - 22.01.21 - UPDATE: 02.07.21                                             *
 ***********************************************************************************************/
#define pino_sinal_analogico A0                             //Define o pino A0 ao A0 do sensor como Sinal Analógico
#define pino_led_vermelho 5                                 //Define o pino 5 para o LED Vermelho
#define pino_led_amarelo 6                                  //Define o pino 6 para o LED Amarelo
#define pino_led_verde 7                                    //Define o pino 7 para o LED Verde
int valor_analogico;                                        //Variável para o valor analógico de 0 a 1023

void setup()
{
  Serial.begin(9600);                                       //Monitor Serial
  pinMode(pino_sinal_analogico, INPUT);                     //Considera o pino mencionado como Entrada
  pinMode(pino_led_vermelho, OUTPUT);                       //Considera o pino mencionado como Saída
  pinMode(pino_led_amarelo, OUTPUT);                        //Considera o pino mencionado como Saída
  pinMode(pino_led_verde, OUTPUT);                          //Considera o pino mencionado como Saída
} 
  
void loop()
{
  valor_analogico = analogRead(pino_sinal_analogico);       //Le o valor do pino A0 do sensor
  Serial.print("Porta analogica: ");                        //Mostra o valor da porta analogica no serial monitor
  Serial.print(valor_analogico);
  
  
  if (valor_analogico > 0 && valor_analogico < 400)         //Solo úmido, acende o led verde
  {
    Serial.println(" Status: Solo umido");                  //Exibe o texto na Serial
    apagaleds();                                            //Executa a função mencionada
    digitalWrite(pino_led_verde, HIGH);                     //pino_led_verde, LIGADO
  }
    
  if (valor_analogico > 400 && valor_analogico < 800)       //Solo com umidade moderada, acende led amarelo
  {
    Serial.println(" Status: Umidade moderada");            //Exibe o texto na Serial
    apagaleds();                                            //Executa a função mencionada
    digitalWrite(pino_led_amarelo, HIGH);                   //pino_led_amarelo, LIGADO
  }
   
  if (valor_analogico > 800 && valor_analogico < 1024)      //Solo seco, acende led vermelho
  {
    Serial.println(" Status: Solo seco");                   //Exibe o texto na Serial
    apagaleds();                                            //Executa a função mencionada
    digitalWrite(pino_led_vermelho, HIGH);                  //pino_led_vermelho, LIGADO
  }
  delay(100);                                               //Aguarda 100ms.
}
  
void apagaleds()                                            //Função para apagar os leds
{
  digitalWrite(pino_led_vermelho, LOW);                     //pino_led_vermelho, DESLIGADO
  digitalWrite(pino_led_amarelo, LOW);                      //pino_led_amarelo, DESLIGADO
  digitalWrite(pino_led_verde, LOW);                        //pino_led_verde, DESLIGADO
}
