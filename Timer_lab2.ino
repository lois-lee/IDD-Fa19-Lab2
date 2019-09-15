/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2, pressed = 8;
const int blue = 6, red = 7, yellow = 9, white = 10, green = 13;
int countDown = 60;
int count = 0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int num_pressed = 0;
int button_state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(white, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(pressed, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.

  digitalWrite(blue, LOW);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(white, LOW);
  digitalWrite(green, LOW);
  lcd.print("Start game!");
  delay(2000);
}

void loop() {
  // set the cursor to column 0, line 1
  Serial.print(digitalRead(pressed));
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the time left:
  count++;
  if(num_pressed >= 20){
      digitalWrite(blue, HIGH);  
  }
  if(num_pressed >= 40){
      digitalWrite(red, HIGH);  
  }
  if(num_pressed >= 60){
      digitalWrite(yellow, HIGH);  
  }
  if(num_pressed >= 80){
      digitalWrite(white, HIGH);  
  }
  if(num_pressed >= 100){
      digitalWrite(green, HIGH);  
  }


  if(button_state == 0){
    if(digitalRead(pressed) == HIGH){
      num_pressed = num_pressed + 1;
      button_state = 1;
      Serial.print("off");
  }
  }
  if(button_state == 1){
    if(digitalRead(pressed) == LOW){
      num_pressed = num_pressed + 1;
      button_state = 0;
      Serial.print("on");
  }
  }

  countDown = 15 - (millis()/1000);
  delay(50);
  lcd.clear();
  lcd.print(countDown);

  if (countDown == 0){
    lcd.clear();
    delay(2000);
    lcd.print("Game Over!");
    delay(2000);
    lcd.clear();
    lcd.print("you pressed");
    delay(2000);
    lcd.clear();
    delay(2000);
    lcd.print(num_pressed);
    lcd.print("  times");
    delay(2000);
    lcd.clear();
    delay(20000000000);
  }
}
