int valorX;
int valorY;
int valorZ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  valorX = 10;
  valorY = 500;
  valorZ = valorX + valorY;
  Serial.print("valorX = ");
  Serial.print(valorX, BIN);

  Serial.print("\tvalorY =");
  Serial.print(valorY, BIN);

  Serial.print("\tvalorZ =");
  Serial.println(valorZ, BIN);
}

void loop() {
  // put your main code here, to run repeatedly:

}
