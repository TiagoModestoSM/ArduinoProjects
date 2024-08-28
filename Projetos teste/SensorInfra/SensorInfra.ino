#define Led 6
#define Infrarec 8
#define Infraem 9

void serial();
void setup() {
  Serial.begin(9600);
  pinMode(Led, OUTPUT);
  pinMode(Infrarec, INPUT);
  pinMode(Infraem, OUTPUT);
  digitalWrite(Infraem,HIGH);
}

void loop() {
   Serial.println(digitalRead(Infrarec));
  
if (digitalRead(Infrarec) == 0)
{
digitalWrite (Led,HIGH);   
}

else 
{
digitalWrite (Led,LOW);
}
}//end loop 
