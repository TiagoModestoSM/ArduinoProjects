#include <HCSR04.h>

#define trig 4
#define echo 5
#define led 9
UltraSonicDistanceSensor distanceSensor(trig, echo );  // Initialize sensor that uses digital pins 13 and 12.

int dist_cm,dist_m;
void setup () {
  pinMode(led, OUTPUT);
    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
}

void loop () {
  analogWrite(led,HIGH);
    // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
    dist_cm=distanceSensor.measureDistanceCm();
    dist_m=dist_cm/100;
    Serial.print("Distancia");
    Serial.print(dist_cm);
    Serial.println("Cm | ");
    Serial.print(dist_m);
    Serial.println("m");
    Serial.print("-------------------------");    
    delay(1000);
}
