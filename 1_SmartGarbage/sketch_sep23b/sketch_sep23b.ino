#include <Arduino.h>
#include <Servo.h>

Servo sg90;
int sg90Pin = 4;

int trigPin = 3;
int echoPin = 2;

long time;
int distance;

void setup() {
  sg90.attach(sg90Pin);
  sg90.write(0);
  delay(2000);

  //choosing trigger-pin as outp & echo-pin as inp
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  //setting trigger-pin to 0V
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  //setting trigger-pin to 5V for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  //reads echo-pin & returns sound wave as microseconds
  time = pulseIn(echoPin, HIGH);

  distance = time * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance <= 30) {
    sg90.write(90);
    delay(2000);
  } else {
    sg90.write(35);
  }
}
