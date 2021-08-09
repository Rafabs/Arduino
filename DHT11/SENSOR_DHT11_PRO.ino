/***********************************************************************************************
 * EXEMPLO DE APLICAÇÃO USANDO MÓDULO DHT                                                     *
 * BY: LAB+ PROJETOS - 14.12.20 - UPDATE: 02.07.21                                             *
 ***********************************************************************************************/
 
#include <DHT.h>                                          //Biblioteca para uso do DHT
#define DHTPIN 7                                          //Declara o pino 7 para usar o DHT
#define DHTTYPE DHT11                                     //Cria o objeto dht
DHT dht (DHTPIN, DHTTYPE);                                //Indica que o objeto e o pino será chamado quando dht for chamado
float t = dht.readTemperature();                          //Variável para fazer a leitura da Temperatura
float h = dht.readHumidity();                             //Variável para fazer a leitura da Umidade
float f = dht.readHumidity(true);                         //Variável para fazer a leitura em Fahrenheit ativada
float hif = dht.computeHeatIndex(f, h);                   
float hic = dht.computeHeatIndex(t, h, false);            
  
void setup() 
{
  dht.begin();                                            //begin é usado para exibir um dado na Serial
  Serial.begin(9600);                                     //na velocidade de 9600
  Serial.println(F("DHT test!"));                         //Exibe o texto na Serial
}

void loop() 
{
  delay(2000);                                            //Aguarda 2s.
  if(isnan(h) || isnan(t) || isnan(f))                    //isnan = is nan = Se não for um número/dado (a barra "|"serve como lógica "OU")
  {
    Serial.println(F("Failed to read from DHT sensor!")); //Exibe o texto na Serial
    return;                                             
  }
  Serial.print(F("Umidade: "));                           //Exibe o texto na Serial
  Serial.print(h);                                        //Exibe a variável na Serial
  Serial.print(F("%  Temperatura: "));                    //Exibe o texto na Serial
  Serial.print(t);                                        //Exibe a variável na Serial
  Serial.print(F("°C "));                                 //Exibe o texto na Serial
  Serial.print(f);                                        //Exibe a variável na Serial
  Serial.print(F("°F Heat index: "));                     //Exibe o texto na Serial
  Serial.print(hic);                                      //Exibe a variável na Serial
  Serial.print(F("°C "));                                 //Exibe o texto na Serial
  Serial.print(hif);                                      //Exibe a variável na Serial
  Serial.print(F("°F "));                                 //Exibe o texto na Serial
}
