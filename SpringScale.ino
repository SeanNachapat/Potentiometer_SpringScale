#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);
float k = 83.49;

void setup()
{
  pinMode(A2, INPUT);

  lcd.init();
  Serial.begin(9600);

  delay(1000);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("====================");
  lcd.setCursor(7, 1);
  lcd.print("Hello,");
  lcd.setCursor(7, 2);
  lcd.print("KUSMP");
  lcd.setCursor(0, 3);
  lcd.print("====================");
  delay(2000);
  lcd.noBacklight();
  lcd.clear();
  delay(2000);
}

void loop()
{
  float potentiometer = analogRead(A2);
  float angle = map(potentiometer, 0, 1023, 0, 270);
  float length = (angle/360) * 2 * (22/7) * 0.015;
  float mass = k*length * 100;


  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Angle(deg) :");
  lcd.setCursor(0, 1);
  lcd.print(angle);

  lcd.setCursor(0, 2);
  lcd.print("Mass(g) :");
  lcd.setCursor(0, 3);
  lcd.print(mass);


  //serial check
  Serial.print("Potentiometer : ");
  Serial.println(potentiometer);
  Serial.print("Angle : ");
  Serial.println(angle);
  Serial.print("Length : ");
  Serial.println(length);
  Serial.print("Mass : ");
  Serial.println(mass);

  delay(200);
}
