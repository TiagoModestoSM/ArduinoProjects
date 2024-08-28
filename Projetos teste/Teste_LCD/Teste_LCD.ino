#include <LiquidCrystal_I2C.h>
#define ButtonUp 6
#define ButtonDown 7
#define Enter 5
LiquidCrystal_I2C lcd(0x27, 16, 2);
byte neve[8] = {
  B00000,
  B00000,
  B01010,
  B11011,
  B00100,
  B11011,
  B01010,
  B00000,
};

byte gota[8] = {
  B00000,
  B00100,
  B00110,
  B01111,
  B11101,
  B11001,
  B01110,
};

byte grau[8] = {
  B00000,
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
};

void setup() {
  lcd.init();
  lcd.setBacklight(HIGH);
   /* lcd.createChar(0, gota);
  lcd.createChar(1, neve);
  lcd.createChar(2, grau);
  lcd.begin(16, 2);
  lcd.write(byte(0));
  lcd.setCursor(0, 1);
  lcd.write(byte(2));*/
  pinMode(ButtonUp,INPUT_PULLUP);
  pinMode(ButtonDown,INPUT_PULLUP);
  pinMode(Enter,INPUT_PULLUP);



}

void loop() {
  lcd.setCursor(0,0);
  lcd.print(digitalRead(ButtonDown));
  lcd.setCursor(7,0);
  lcd.print(digitalRead(ButtonUp));
  lcd.setCursor(15,0);
  lcd.print(digitalRead(Enter));
  //lcd.print("Ola Mundo!!");
  //lcd.setCursor(10,1);
  //lcd.print("O");
  //lcd.cursor();
  //lcd.setCursor(12,1);
  //lcd.write(byte(244));
  //lcd.scrollDisplayLeft();
  //lcd.noDisplay();
  //delay(350);
  //lcd.display();
}
