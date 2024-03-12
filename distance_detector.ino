#include <LiquidCrystal_I2C.h>

int trig=16;
int echo=15;
float speedofsound=0.034;
float duration;
float distance_cm;

#define i2c_adder 0x27
#define lcd_lines 16
#define lcd_columns 2

LiquidCrystal_I2C lcd(i2c_adder,lcd_columns,lcd_lines);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  // this speeds up the simulation
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration=pulseIn(echo,HIGH);
  distance_cm=((speedofsound/2)*duration);
  Serial.print("distance in cm::");
  Serial.println(distance_cm);
  lcd.setCursor(0,0);
  lcd.print("distance in cm:");
  lcd.setCursor(0,1);
  lcd.print(distance_cm);
  delay(5000);
}
