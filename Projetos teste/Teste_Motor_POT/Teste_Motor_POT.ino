/*
Autor: Tiago Modesto de Sousa Moura (LABIGO)
Data: 26/04/24

Alterar a velocidade do Motor com potenciometro

*/
 
#define motorFrente 5
#define motorTras 3
const int pinoPOT = A5; //PINO ANALÓGICO UTILIZADO PELO POTENCIÔMETRO
float luminosidadeLED = 0; //VARIÁVEL QUE ARMAZENA O VALOR DA LUMINOSIDADE QUE SERÁ APLICADA AO LED
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Configurando pinMode");
  pinMode(pinoPOT, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode(motorFrente, OUTPUT);
  pinMode(motorTras,OUTPUT);
}

void loop() {
Serial.println(analogRead(pinoPOT));
  delay(500);
  luminosidadeLED = map(analogRead(pinoPOT), 0, 511, 255, 0); //EXECUTA A FUNÇÃO "map" DE ACORDO COM OS PARÂMETROS PASSADOS
  analogWrite(motorFrente, luminosidadeLED); //APLICA AO LED O VALOR DE LUMINOSIDADE GERADO PELA FUNÇÃO "map"
  luminosidadeLED = map(analogRead(pinoPOT), 530, 1023, 0, 255); //EXECUTA A FUNÇÃO "map" DE ACORDO COM OS PARÂMETROS PASSADOS
  analogWrite(motorTras, luminosidadeLED); //APLICA AO LED O VALOR DE LUMINOSIDADE GERADO PELA FUNÇÃO "map"
}
