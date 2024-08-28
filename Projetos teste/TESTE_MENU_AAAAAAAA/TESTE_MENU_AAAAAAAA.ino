//Inclusão das bibliotecas do projeto
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Criação do Objeto do LCD 16x2 com seu enderço 0x27
LiquidCrystal_I2C lcd(0x27,16,2);//Configurando o endereço do LCD 16x2

//Definição de nomes para os números dos pinos digitais do Arduino UNO
#define ButtonUp 5
#define ButtonDown 6
#define ButtonEnter 7

#define Led1 9

//Declaração das variáveis do projeto
bool up = 0, down = 0, enter = 0;
bool StateUp = 1, StateDown = 1, EnableLCD = 0, StateEnterControl = 1;
bool StateLed1 = 0;

byte count = 1;

//-----------------------------------------------------
//Funções para apresentação de cada tela do menu de opções do projeto

void screen1() // Função para tela 1
{
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("->MONITOR");// Seleção da opção de monitoramento
  lcd.setCursor(0,1);
  lcd.print("  CONTROL");//Opção Controle
}

void screen2() // Função para tela 2
{
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("  MONITOR");//Opção de monitoramento
  lcd.setCursor(0,1);
  lcd.print("->CONTROL");//Seleção de opção Controle
}

void screen3() // Função para tela 3
{
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("  CONTROL");//Opção de monitoramento
  lcd.setCursor(0,1);
  lcd.print("->MODO");//Seleção de opção MODO
}
//-----------------------------------------------------

void setup() {
  
  pinMode(ButtonUp,INPUT_PULLUP);
  pinMode(ButtonDown,INPUT_PULLUP);
  pinMode(ButtonEnter,INPUT_PULLUP);

  pinMode(Led1,OUTPUT);

//INICIALIZAÇÃO DO LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

//Tela de Entrada
  lcd.setCursor(3,0);
  lcd.print("THERMOSTAT");
  lcd.setCursor(2,1);
  lcd.print("PRESS  ENTER");

  delay(2000);

//Abrir tela 1
 screen1();

 delay(2000);
}

void loop() {

//-----------------------------------------------------
//Leitura dos estados dos botões
//A função retorna 1 quando o botão não está pressionado e 0 quando está pressionado

  up = digitalRead(ButtonUp);
  down = digitalRead(ButtonDown);
  enter = digitalRead(ButtonEnter);

}
