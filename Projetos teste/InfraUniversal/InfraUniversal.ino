

//BIBLIOTECAS
#include <Pushbutton.h>
#include <IRremote.h>

//Diretivas de Compilação
#define tempoTecla 350
#define frequencia 38 //kHz

//Definição de pinos
#define pinReceptor 11
#define pinBot1 8
#define pinLed 12

// INSTANCIANDO OBJETOS
IRrecv receptorIR(pinReceptor);
IRsend emissorIR;
Pushbutton botaoLeitura(pinBot1);

// DECLARAÇÃO DE VARIAVEIS UNIVERSAIS
bool lerComando = false;

//DECLARAÇÃO DAS FUNÇÕES DE LEITURA

void ircode   (decode_results *results);
void encoding (decode_results *results);
void dumpInfo (decode_results *results);
void dumpRaw  (decode_results *results);
void dumpCode (decode_results *results);

//DECLARAÇÃO DAS TECLAS CLONADAS

unsigned int teclaA[] = {};
unsigned int teclaB[] = {};
unsigned int teclaC[] = {};
unsigned int teclaD[] = {};
void setup() {
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);

  //Iniciando Receptor IR
  receptorIR.enableIRIn();
  Serial.print ("Setup Concluído");

}

void loop() {
  //METODO PARA LEITURA E ATUALIZAÇÃO DAS PROPRIEDADES DO BOTÃO


  // BLOCO CONDIÇÕES PARA INICIAR LEITURA

  if (botaoLeitura.isPressed() && !lerComando) {
    lerComando = true;
    digitalWrite(pinLed, HIGH);
  } else if (botaoLeitura.isPressed() && lerComando) {
    lerComando = false;
    digitalWrite(pinLed, LOW);
  }

  //Laço para leitura do receptor ir quando for pressionado o botão
  while (lerComando) {
    decode_results results;
    if (receptorIR.decode(&results)) {
      ircode   (&results);
      encoding (&results);
      dumpInfo (&results);
      dumpRaw  (&results);
      dumpCode (&results);
      receptorIR.resume();
      lerComando = false;
      digitalWrite(pinLed, LOW);
    }
  }

  //BLOCO PARA RECEBER DADOS DA SERIAL E INICIAR EM EMISSOR IR
  if (Serial.available()) {
    char tecla = Serial.read();

    switch (tecla) {
      case 'a':
        emissorIR.sendRaw(teclaA, sizeof(teclaA) / sizeof(teclaA[0]), frequencia);
        Serial.println("Enviando Tecla A Clonada");
        delay(tempoTecla);
        break;
    }
  }
}
