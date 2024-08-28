//Bibliotecas

#include <IRremote.h>

//Variáveis
#define PinRec 4

IRrecv irReceiver(PinRec);
int comando;

void setup() {
//Serial
  Serial.begin(9600);
//IR
  irReceiver.enableIRIn();

}

void loop() {
  //Se chegfou dados, faz:
  if (irReceiver.decode()){
    comando = irReceiver.decodedIRData.command; //guarda o dado recebido em "COMANDO"
    Serial.println(comando); //Imprime o dado no Serial
    irReceiver.resume();
  }
}
