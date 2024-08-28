/*
|Autor: Tiago Modesto (Labigó)                           |
|Data:04/06/2024                                         |
|Teste de código do Sensor DHT11 de Umidade e Temperatura|
*/

#include <DHT.h> //inclui a biblioteca do sensor

#define DHTPIN 3 //Definir o pino de Sinal
#define DHTTYPE DHT11 // Definir o modelo do sensor

DHT dht(DHTPIN,DHTTYPE);

void setup() {
  Serial.begin(9600); //Inicia o Serial
  Serial.print("DHT11 test");
  Serial.println("-------------------------");

  dht.begin();
}

void loop() {
 delay(2000); //adiciona um delay de 2s a cada leitura

 float h = dht.readHumidity();
 float t = dht.readTemperature();// Celsius é o padrão
 float f = dht.readTemperature(true);// lê em Fahrenheit

  if (isnan(h) || isnan(t) || isnan(f)){ // Para se alguma leitura falhar, ele fazer a leitura novamente
  Serial.println("Leitura do sensor DHT falhou");
  return; 
}
float hif = dht.computeHeatIndex(f, h); // temperatura em F
float hic = dht.computeHeatIndex(t, h, false);// temperatura em C

  Serial.print("Umidade: ");
  Serial.print(h);
  Serial.print("% Temperatura: ");
  Serial.print(t);
  Serial.print("°C ");
  Serial.print(hif);
  Serial.println("°F");
  Serial.println("-------------------------");
} 
