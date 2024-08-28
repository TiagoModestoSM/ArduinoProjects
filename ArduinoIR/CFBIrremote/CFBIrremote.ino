/*VALORES TV DE CASA

Botão Power: F708FB04
Botão + Volume: FD02FB04
Botão - Volume: FC03FB04


*/
#include <IRremote.h>
#define IRrec 2

IRrecv recIR(IRrec);
decode_results resultado;

void setup() {
  Serial.begin(9600);
  recIR.enableIRIn();
}

void loop() {
  if(recIR.decode(&resultado)){
    Serial.print("Valor: ");
    Serial.println(resultado.value,HEX);
    recIR.resume();
  }
}
