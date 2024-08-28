
#define infra 12
int cont=0;
int disp_pinos[8] = {2,3,4,5,6,7,8,9};
int numero = 0;
int digitos [2][8] = {
{1,1,1,1,1,1,0,0},//0
{0,1,1,0,0,0,0,0},//1
};

  

void setup() {
 Serial.begin(9600);
 pinMode(infra, INPUT);
 for (int nP = 0; nP<=8;nP++){
  pinMode(disp_pinos[nP],OUTPUT);
 }

}//end setup

void loop() 
{ 
  bool estadoinfra = digitalRead(infra);
  Serial.println(estadoinfra);
  if (estadoinfra == 0){
    for (int nP = 0; nP<=8;nP++){
  digitalWrite(disp_pinos[nP],HIGH);
 
    }
  }


  

}
