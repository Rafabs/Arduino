/***********************************************************************************************
 * EXEMPLO DE APLICAÇÃO USANDO MÓDULO DHT                                                      *
 * BY: LAB+ PROJETOS - 14.12.20 - UPDATE: 02.07.21                                             *
 ***********************************************************************************************/
 
#include <DHT.h>                       //Biblioteca para uso do DHT
#include <DHT_U.h>                     //Biblioteca para uso do DHT
DHT dht(7,DHT22);                      //Declara o pino 7 para usar o DHT e cria o objeto dht
float temp = dht.readTemperature();    //Variável para fazer a leitura da Temperatura
float umid = dht.readHumidity();       //Variável para fazer a leitura da Umidade
  
void setup() 
{
  dht.begin();                         //begin é usado para exibir um dado na Serial
  Serial.begin(9600);                  //na velocidade de 9600
}

void loop() 
{
  Serial.print("Temperatura: ");       //Exibe o texto na Serial
  Serial.println (temp);               //Exibe a variável na Serial
  Serial.print("Umidade: ");           //Exibe o texto na Serial
  Serial.println (umid);               //Exibe a variável na Serial
  Serial.println ();                   //Exibe o texto na Serial
  delay(2000);                         //Aguarda 2s.
}
