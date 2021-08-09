/***********************************************************************************************
 * EXEMPLO DE APLICAÇÃO USANDO MÓDULO RFID RC522                                               *
 * BY: LAB+ PROJETOS - 22.01.21 - UPDATE: 02.07.21                                             *
 ***********************************************************************************************/
#include <SPI.h>                                                          //Biblioteca para uso de Sinal Periférico
#include <MFRC522.h>                                                      //Biblioteca para uso do MFRC522
#define SS_PIN 10                                                         //Define o Pino 10 para dar o sinal periférico
#define RST_PIN 9                                                         //Define o Pino 9 para ser reset em casos de erros
MFRC522 mfrc522(SS_PIN, RST_PIN);                                         //Cria o objeto MFRC522 e define os pinos declarados
char st[20];                                                              
String conteudo= "";                                                      //Variável para ler o que tem na tag
byte letra;                                                               
  
void setup() 
{
  Serial.begin(9600);                                                     //Monitor Serial
  SPI.begin();                                                            //Inicia SPI bus
  mfrc522.PCD_Init();                                                     //Inicia o MFRC522
  Serial.println("Aproxime o seu cartao do leitor...");                   //Exibe o texto na Serial
  Serial.println();                                                       //Exibe o texto na Serial
}
 
void loop() 
{
  if ( ! mfrc522.PICC_IsNewCardPresent())                                 //Se não tiver nenhuma tag nova: (! NÃO Lógico)
  {
    return;                                                               
  }

  if ( ! mfrc522.PICC_ReadCardSerial())                                   //Se não for selecionada uma tag: (! NÃO Lógico)
  { 
    return;                                                              
  }
Serial.print("UID da tag :");                                             //Exibe o texto na Serial
for (byte i = 0; i < mfrc522.uid.size; i++)                               //Compara o tamanho para formar o UID da tag
{
  Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");               //Exibe o texto na Serial
  Serial.print(mfrc522.uid.uidByte[i], HEX);                              //Exibe o texto na Serial
  conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));    //Concatena a string e forma o conteúdo da tag
  conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));                   //Concatena a string e forma o conteúdo da tag
}       
Serial.println();                                                         //Exibe o texto na Serial
Serial.print("Mensagem : ");                                              //Exibe o texto na Serial
conteudo.toUpperCase();                                                   //Obtém o valor em Maiúsculo para a variável conteúdo 
if (conteudo.substring(1) == "F4 EC AE 2A")                               //Se o conteúdo for F4 EC AE 2A
{ 
  Serial.println("Ola RAFAEL BARBOSA");                                   //Exibe o texto na Serial
  Serial.println();                                                       //Exibe o texto na Serial
  delay(3000);                                                            //Aguarda 3s.
}
 
if (conteudo.substring(1) == "F7 9D A3 7A")                               //Se o conteúdo for F7 9D A3 7A
{  
  Serial.println("Ola LAB+ PROJETOS");                                    //Exibe o texto na Serial
  Serial.println();                                                       //Exibe o texto na Serial
  delay(3000);                                                            //Aguarda 3s.
}
}
