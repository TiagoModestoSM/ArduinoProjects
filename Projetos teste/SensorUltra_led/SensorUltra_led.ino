//Programa: Sensor ultrassônico Arduino acender LED
//Autor: Luan Alves - www.guiarobotica.com
#include "Ultrasonic.h"
#define trig 4
#define echo 5
#define buzzer 6
Ultrasonic ultrasonic(trig,echo ); // Trigger na porta 3 e Echo na porta 2

//Declarando os LED como constantes em seus respectivos pinos
const int ledVerde = 11;
const int ledAmarelo = 10;
const int ledVermelho = 9;

long microsec = 0; // variaveis de controle
float distanciaCM = 0;

void setup() {
  Serial.begin(9600); //Inicializando o serial monitor
  pinMode(ledVerde, OUTPUT); //declarando os LEDs como saida
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  //Lendo o valor do sensor
  microsec = ultrasonic.timing();

  //Convertendo a distância em CM
  distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM);

  ledDistancia();
  Serial.print(distanciaCM);// mostrar a distancia na porta serial
  Serial.println(" cm");// colocar unidade de medida
  delay(500);// espera de 500 milissegundos
}

void ledDistancia() {

  //Desliga todos os LEDs
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);

  // criando as condicoes se a distancia for entre 30 cm e 20 cm
  if (distanciaCM <= 80 and distanciaCM >= 50) {
    digitalWrite(ledVerde, HIGH); //liga o LED verde
  }
  // se a distancia for 10 cm e 20 cm
  if (distanciaCM <=50 and distanciaCM >= 30) {
    digitalWrite(ledAmarelo, HIGH); //liga LED amarelo
  }

  if (distanciaCM < 30) { // se a distancia for menor que 10 cm
    digitalWrite(ledVermelho, HIGH); }// liga LED vermelho
  if (distanciaCM <20) {
    
    for (int i = 0; i<256; i++)
  {
    analogWrite(ledVermelho,i);
    analogWrite(ledAmarelo,i);
    analogWrite(ledVerde,i);
    analogWrite(buzzer, i);
    delay(1);
  }
  for (int i = 256; i>=0; i--)
  {
    analogWrite(ledVermelho,i);
    analogWrite(ledAmarelo,i);
    analogWrite(ledVerde,i);
    analogWrite(buzzer,i);
    delay (1);
  
}
  }
  }
