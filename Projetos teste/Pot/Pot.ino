const int pinoPOT = A5; //PINO ANALÓGICO UTILIZADO PELO POTENCIÔMETRO
const int LedG = 10; //PINO DIGITAL UTILIZADO PELO LED
const int LedY = 5; //PINO DIGITAL UTILIZADO PELO LED
const int LedR = 3; //PINO DIGITAL UTILIZADO PELO LED

float luminosidadeLED = 0; //VARIÁVEL QUE ARMAZENA O VALOR DA LUMINOSIDADE QUE SERÁ APLICADA AO LED

void setup(){
   pinMode(pinoPOT, INPUT); //DEFINE O PINO COMO ENTRADA
   pinMode(LedG, OUTPUT); //DEFINE O PINO COMO SAÍDA
   pinMode(LedY, OUTPUT); //DEFINE O PINO COMO SAÍDA
   pinMode(LedR, OUTPUT); //DEFINE O PINO COMO SAÍDA
}

void loop(){
  luminosidadeLED = map(analogRead(pinoPOT), 0, 1023, 0, 255); //EXECUTA A FUNÇÃO "map" DE ACORDO COM OS PARÂMETROS PASSADOS
  analogWrite(LedG, luminosidadeLED); //APLICA AO LED O VALOR DE LUMINOSIDADE GERADO PELA FUNÇÃO "map"
  analogWrite(LedY, luminosidadeLED); //APLICA AO LED O VALOR DE LUMINOSIDADE GERADO PELA FUNÇÃO "map"
  analogWrite(LedR, luminosidadeLED); //APLICA AO LED O VALOR DE LUMINOSIDADE GERADO PELA FUNÇÃO "map"
}
