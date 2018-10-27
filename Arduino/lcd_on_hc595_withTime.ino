#include <ShiftLCD.h>
ShiftLCD lcd(2, 4, 3);

int sec(0), minutes(00), hours(00);

void setup() 
{
  lcd.begin(16, 2);
}

void loop() 
{
  lcd.clear();
  lcd.setCursor(3, 0); // 4th number of column (from left),  0th number of row
  lcd.print("Czas: ");
  printHour();

}

void printHour()
{
  lcd.setCursor(2, 1);
  lcd.print(hours);
  
  lcd.setCursor(4,1);
  lcd.print(":");
  
  lcd.setCursor(5,1);
  lcd.print(minutes);
  
  lcd.setCursor(7,1);
  lcd.print(":");
  
  lcd.setCursor(8,1);
  lcd.print(sec);
  
  sec++;
  
  if (sec == 60)
  {
      sec = 0;
      minutes++;
  
     if(minutes == 60)
     {
       hours++;
       minutes = 0;
     }
     if (hours == 24)
       hours = 0;
  }
  delay(1000);
}
