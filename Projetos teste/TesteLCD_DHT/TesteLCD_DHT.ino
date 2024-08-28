/*
Autor: Tiago Modesto de Sousa Moura (Labigó)
Data: 18/06/24
Codigo teste do sensor de temperatura e umidade DHT11 implantado com display LCD I2C


*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h> // Inclui a biblioteca do LCD I2C
#include <DHT.h> //Inclui a biblioteca do sensor DHT11

  #define DHTPIN 3 //Definir o pino de Sinal
  #define DHTTYPE DHT11 // Definir o modelo do sensor
     LiquidCrystal_I2C lcd(0x27,16,2); // Define o endereço e a proporção do display LCD

byte neve[8] = {// Formato do Floco de Neve
  B00000,
  B00000,
  B01010,
  B11011,
  B00100,
  B11011,
  B01010,
  B00000,
};

byte gota[8] ={ // Formato da Gota
  B00000,
  B00100,
  B00110,
  B01111,
  B11101,
  B11001,
  B01110,  
};

byte grau[8] = {// Formato do Grau (°)
  B00000,
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
};
DHT dht(DHTPIN,DHTTYPE);


void setup() {
  lcd.init();
lcd.setBacklight(HIGH);
  Serial.begin(9600); //Inicia o Serial
  Serial.println("DHT11 test");
  Serial.println("-----------------------------------------");
  dht.begin();
lcd.createChar(0,gota);
lcd.createChar(1,neve);
lcd.createChar(2,grau);
lcd.begin(16,2);
lcd.clear();


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
lcd.setCursor(4,0);
lcd.write(byte(1));
 lcd.print(t);
 lcd.write(byte(2));
 lcd.print("C  ");
 lcd.setCursor(4,1);
 lcd.write(byte(0));
 lcd.print(h);
 lcd.print("%");
 lcd.setCursor(0,0);
  Serial.print("Umidade: ");
  Serial.print(h);
  Serial.print("% Temperatura: ");
  Serial.print(t);
  Serial.print("°C ");
  Serial.print(hif);
  Serial.println("°F");
  Serial.println("-------------------------");

}
