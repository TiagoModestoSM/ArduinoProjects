#define Led 11
#define Infra 8


void setup() {
  Serial.begin(9600);
  pinMode(Led, OUTPUT);
  pinMode(Infra, INPUT);
}

void loop() {
if (digitalRead(Infra) == HIGH){
digitalWrite (Led,HIGH);
    
  delay (200);
}
else {
digitalWrite (Led,LOW);
  delay(200);
}
}
