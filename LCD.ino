#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int pin1=A0;
int pin2=A1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // Serial Monitor is being initiated for Serial communication between the arduino and your computer
  lcd.begin(16, 2);
  lcd.print("Inidara!");
  pinMode(pin1,INPUT);
  pinMode(pin2,INPUT);
}

void loop() {
  int mq135 = analogRead(A0); // we read analog values using the analogread function
  int mq7 = analogRead(A1);
  int mq135_cent=mq135/10;
  int mq7_cent=mq7/10;
  lcd.setCursor(0, 1);
  lcd.print("Co2:");
  lcd.setCursor(4, 1);
  lcd.print(mq135_cent);
  lcd.setCursor(7, 1);
  lcd.print("%");

  lcd.setCursor(10, 1);
  lcd.print("Co:");
  lcd.setCursor(13, 1);
  lcd.print(mq7_cent);
   lcd.setCursor(15, 1);
  lcd.print("%");
  
}

//x<400 = High Carbon
//x>400 = Low Carbon