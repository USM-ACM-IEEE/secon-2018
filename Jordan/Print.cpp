#include <LiquidCrystal.h>

int pin1;
int pin2;
int pin3;
int pin4;
int rem, temp, dec = 0, b = 1;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void binDec(int num);


void setup() {
  lcd.begin(16, 2);                  // set up the LCD's number of columns and rows
  lcd.print("#");                    // print

  // setting pins 6-9 to input
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  
}

void loop() {
 
  lcd.setCursor(0, 1);               // set the cursor to column 0, line 1 because count starts at 0

  pin1 = digitalRead(6);
  pin2 = digitalRead(7);
  pin3 = digitalRead(8);
  pin4 = digitalRead(9);

  binDec(pin1);
  binDec(pin2);
  binDec(pin3);
  binDec(pin4);

  if(pin4 == 7){
    lcd.print("Aligned");
  }
}

//==================== Binary to Decimal ====================
void binDec(int num){
  temp = num;
  while (num > 0){
     rem = temp % 10;
     dec = dec + rem * b;
     b *= 2;
     temp /= 10;
  }
  lcd.print(temp);
}
