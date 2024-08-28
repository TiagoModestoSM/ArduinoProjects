#define motorEFrente 10
#define motorETras 9
#define motorDFrente 5
#define motorDTras 3

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Configurando pinMode");

  pinMode(motorEFrente, OUTPUT);
  pinMode(motorETras,OUTPUT);
  pinMode(motorDFrente, OUTPUT);
  pinMode(motorDTras, OUTPUT);
}

void loop() {
  Serial.println("M.Frente = Frente");
  digitalWrite(motorEFrente, HIGH);
  digitalWrite(motorDFrente, HIGH);
  digitalWrite(motorETras,LOW);
  digitalWrite(motorDTras,LOW);

  delay(2000);

  Serial.println("M.Tras = Tras");
  digitalWrite(motorEFrente, LOW);
  digitalWrite(motorDFrente, LOW);
  digitalWrite(motorETras,HIGH);
  digitalWrite(motorDTras,HIGH);
  delay(2000);
  

  // put your main code here, to run repeatedly:

}
