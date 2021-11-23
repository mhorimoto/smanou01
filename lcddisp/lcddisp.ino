/* 
 *  LCD Sample Program
 *
 *    Masafumi Horimoto <horimoto@holly-linux.com>
 *    23rd Nov. 2021
 *    This software is released under the MIT License.
 */

#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x27,16,2);

int x,y;

void setup(void) {
  lcd.begin(6,2);
  lcd.init();         /* Initializing */
  lcd.backlight();    /* Back Light ON */
  lcd.scrollDisplayRight();
  lcd.cursor();
  lcd.blink_on();
  lcd.home();
  x = 0; y = 0;
  
  Serial.begin(9600); /* UART Begin */
  Serial.println("LCD Sample Program VER:1.00");
  Serial.println("Enter ASCII Characters");
}

void loop(void) {
  int inb;
  char ch;
  if (Serial.available() > 0) {
    inb = Serial.read();
    if ((inb >= 0x20)&&(inb <= 0x7e)) {
      ch = (char)inb;
      lcd.print(ch);
      x++;
      if (x>15) {
        x = 0;
        if (y==0) {
          y = 1;
        } else {
          y = 0;
        }
        lcd.setCursor(x,y);
        lcd.print("                ");
        lcd.setCursor(x,y);
      }  
    }
  }
}
