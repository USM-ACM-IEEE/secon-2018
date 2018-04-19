#include <LiquidCrystal.h>

int pin1, pin2, pin3, pin4;
int rem, temp, dec = 0, b = 1;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);                  // set up the LCD's number of columns and rows

  // setting pins 6-9 to input
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  
}

void loop() {

  pin1 = digitalRead(6);
  pin2 = digitalRead(7);
  pin3 = digitalRead(8);
  pin4 = digitalRead(9);

  int val = 4 * pin1 + 2 * pin2 + 1 * pin3;
  
  
  if(!pin4 && val == 7){
    lcd.setCursor(0, 1); 
    lcd.print("Aligned");
  }
  else {
    lcd.setCursor(0,0);
    lcd.print(val);
    lcd.setCursor(0,1);
    lcd.print("                          ");
  }

}

