#include <LiquidCrystal.h>

//实例化一个名为lcd的liquidcrystal类的对象，并初始化相关引脚
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//自定义字符
byte heart[8] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000 };

byte smile[8] = {
  B00000,
  B00000,
  B01010,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000 };

void setup()
{

  lcd.begin(16, 2);
  lcd.createChar(1, heart);
  lcd.createChar(2, smile);
  lcd.setCursor(0,0);
  lcd.print("I ");
  lcd.write(1);
  lcd.print(" Physics. ");
  lcd.write(2);
  
}

void loop()
{

}
