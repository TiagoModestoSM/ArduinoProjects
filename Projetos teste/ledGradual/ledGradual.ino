const int LED = 9;
const int LED1 = 10;
const int LED2 = 11;
/*Pinos PWM (3,5,6,9,10 e 11)
pulse-width modulation: varia a tensão que ele envia para o pino
saída tem um valor de 8 bits, ou seja, varia de 0 a (2^8)-1
*/
void setup() {
  // put your setup code here, to run once:
pinMode (LED,OUTPUT);
pinMode (LED1,OUTPUT);
pinMode (LED2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for (int i = 0; i<256; i++)
  {
    analogWrite(LED,i);
    analogWrite(LED1,i);
    analogWrite(LED2,i);
    delay (10);
  }
  for (int i = 256; i>=0; i--)
  {
    analogWrite(LED,i);
    analogWrite(LED1,i);
    analogWrite(LED2,i);
    delay (10);
  }
}
