#define Botao 8 //Define que o botão encontra-se no pino 3 do Arduino 
#define LedR 12
#define LedY 9
#define LedG 10
void setup() {
  pinMode(Botao, INPUT); //Declara o pino como entrada 
  Serial.begin(9600); //Inicializa a Serial Monitor com baudrate de 9600
  pinMode(LedR, OUTPUT);
    pinMode(LedY, OUTPUT);
      pinMode(LedG, OUTPUT);
}
void loop() { 
  //Lê a porta digital e printa a leitura (0/1) na Serial Monitor 
  //ou no Plotter Serial
  int estadoBotao = digitalRead(Botao);
  Serial.println(digitalRead(Botao)); 
  digitalWrite(LedR, estadoBotao);
  digitalWrite(LedY, !estadoBotao);
}
