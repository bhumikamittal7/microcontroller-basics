#include <LiquidCrystal_I2C.h>

// Set up LCD JDH 162A 16x2 display
// Create the lcd object
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
// 0x27 is a default address. If it does not work, try 0x3F

int count = 0;

void setup() {
  lcd.begin(); // initialize the lcd
  // Turn on the backlight on LCD.  
  lcd.backlight();
  lcd.print("Hello YTS!");
  lcd.setCursor(0,1);
  lcd.print("Demo");  
  delay(2000); 
}


void loop() {
 // ESP32 LCD-1602-I2C 
  lcd.clear();// clear previous values from screen
  lcd.print("How are you?");
  lcd.setCursor(0,1);
  lcd.print("Counting:");
  lcd.setCursor(11,1);  
  lcd.print(count);
  count++;
  delay(200); 
  delay(100);
}



