/***********************************************************************************************
 * EXEMPLO DE APLICAÇÃO Scroll LCD (Rolamento de Texto)                                        *
 * BY: LAB+ PROJETOS - 20.10.21 - UPDATE: 05.07.21                                             *
 * ><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><*
 * VARIÁVEL: int (Um tipo de dados de número inteiros de até 16 bits)                          *
 * VARIÁVEL: String (Há múltiplas versões que constroem Strings de diferentes tipos de dados)  *
 ***********************************************************************************************/
#include <LiquidCrystal.h>                                               //Inclui a biblioteca do LCD 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7= 2;               //Declaração dos pinos para serem usados no LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);                               //Declaração dos pinos para serem usados no LCD
int screenWidth = 20;                                                    //Variável para a largura do LCD 
int screenHeight = 4;                                                    //Variável para a altura do LCD 
String line1 = "Lab+ Projetos = Laboratorio sob numero de ordem A 2078"; //Variável para exibir o texto no LCD
int stringStart, stringStop = 0;                                         //Variável para iniciar a parar o texto inicialmente setadas em 0
int scrollCursor = screenWidth;                                          //Variável para rolar o texto com o mesmo valor da largura do LCD
int tamanho = 0;                                                         //Variável para rolar o texto em comparação ao texto, inicialmente setadas em 0
   
void setup() 
{  
  lcd.begin(screenWidth,screenHeight);                                   //Tipo de display LCD  
}  
   
void loop() 
{  
  lcd.setCursor(scrollCursor, 0);                                       //Posição do texto a ser exibido
  lcd.print(line1.substring(stringStart,stringStop));                   //Exibe o texto no LCD
  delay(250);                                                           //Aguarda 250ms.
  scroll_sup();                                                         //Entra na função para executar o scroll (rolamento) na Linha 37
  tamanho = line1.length();                                             //determina o tamanho pelo comprimento do conteúdo na variável 'line1'
  if (stringStart == tamanho)                                           //Se o tamanho for igual a variável stringStart:
  {  
    stringStart = 0;                                                    //Atualiza o valor da variável stringStart, setadas em 0
    stringStop = 0;                                                     //Atualiza o valor da variável stringStart, setadas em 0
  }  
}  
   
void scroll_sup()                                                       //Função para executar o scroll (rolamento)
{  
  lcd.clear();                                                          //Limpa o display
  if(stringStart == 0 && scrollCursor > 0)                              //Se stringStart for igual a 0 e scrollCursor for maior do que 0: (&& = e)
  {  
    scrollCursor--;                                                     //Diminui o valor da variável scrollCursor (rolamento)
    stringStop++;                                                       //Aumenta o valor da variável stringStop (rolamento)
  } 
  else if (stringStart == stringStop)                                   //Se stringStart for igual a scrollCursor:
  {  
    stringStart = stringStop = 0;                                       //Atualiza o valor das variáveis stringStart e stringStop, setadas em 0
    scrollCursor = screenWidth;                                         //Atualiza o valor da variável scrollCursor, sendo igual ao da screenWidth 
  }
  else if (stringStop == line1.length() && scrollCursor == 0)           //Se stringStop for igual ao comprimento e scrollCursor for igual a 0: (&& = e)
  {  
    stringStart++;                                                      //Aumenta o valor da variável stringStart (rolamento)
  }
  else                                                                  //Senão:
  {  
    stringStart++;                                                      //Aumenta o valor da variável stringStart (rolamento)
    stringStop++;                                                       //Aumenta o valor da variável stringStop (rolamento)
  }  
}  
