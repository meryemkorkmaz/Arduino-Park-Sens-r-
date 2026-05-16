#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 9;
const int echoPin = 10;

long sure;
int mesafe;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
  
  lcd.init();
  lcd.backlight();
  
  Serial.println("Mesafe(cm),Yanki_Suresi(us)");
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  sure = pulseIn(echoPin, HIGH);
  mesafe = sure * 0.034 / 2;

  lcd.setCursor(0, 0);
  lcd.print("Mesafe: ");
  lcd.print(mesafe);
  lcd.print(" cm   ");

  Serial.print(mesafe);
  Serial.print(",");
  Serial.println(sure);

  delay(500);
}
