#define VRx A2
#define VRy A1
#define SW 2

void setup() {
  // put your setup code here, to run once:
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int valorVRx = analogRead(VRx);
int valorVRy = analogRead(VRy);
bool estadoSW = digitalRead(SW);
Serial.print("|");
Serial.print(valorVRx);
Serial.print("|");
Serial.print(valorVRy);
Serial.println("|");
Serial.print(estadoSW);
delay(200);


}
