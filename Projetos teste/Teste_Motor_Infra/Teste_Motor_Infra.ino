/*
autor: 
data:
oq o codigo faz

*/
#define motorEFrente 2
#define motorETras 3
#define motorDFrente 4
#define motorDTras 5
#define infra1 8
#define infra2 7
#define infra3 6

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Configurando pinMode");
  pinMode(infra1,INPUT);
  pinMode(infra2,INPUT);
  pinMode(infra3,INPUT);
  pinMode(motorEFrente, OUTPUT);
  pinMode(motorETras,OUTPUT);
  pinMode(motorDFrente, OUTPUT);
  pinMode(motorDTras, OUTPUT);
  Serial.println("Iniciando Programa");
  
}

void loop() {
 
  Serial.println(digitalRead(infra1));
  Serial.println(digitalRead(infra2));
  Serial.println(digitalRead(infra3));

  if(digitalRead(infra1) == 0 && digitalRead(infra2) )
  {
    digitalWrite(motorEFrente,LOW);
    analogWrite(motorETras,100);
    analogWrite(motorDFrente,100);
    digitalWrite(motorDTras,LOW);
  }

  else if(digitalRead(infra1) && digitalRead(infra2)==0 )
  {
    
    analogWrite(motorEFrente,100);
    digitalWrite(motorETras,LOW);
    digitalWrite(motorDFrente,LOW);
    analogWrite(motorDTras,100);
  }

  else if(digitalRead(infra1)==0 && digitalRead(infra2)==0 )
  {
    digitalWrite(motorDFrente,LOW);
    digitalWrite(motorDTras,LOW);
    digitalWrite(motorEFrente,LOW);
    digitalWrite(motorETras,LOW);        
  }
  else 
  {
    analogWrite(motorDFrente, 100);
    analogWrite(motorEFrente, 100);
    digitalWrite(motorDTras,LOW);
    digitalWrite(motorETras,LOW);
  }
  if (digitalRead(infra3) == 1){
        digitalWrite(motorDFrente,LOW);
    digitalWrite(motorDTras,LOW);
    digitalWrite(motorEFrente,LOW);
    digitalWrite(motorETras,LOW);        
  }
  

}
