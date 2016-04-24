/*****
接线方式：
PSB	-	GND
RS	-	8
R/W	-	9
E	-	10
*****/
#include <dht.h>
#include <LCD12864RSPI.h>
#define AR_SIZE( a ) sizeof( a ) / sizeof( a[0] )
#define DHT11PIN 11

dht DHT11;

unsigned char project[] = {
	0xCE, 0xC2,
	0xCA, 0xAA,
	0xB6, 0xC8,
	0xB2, 0xE2,
	0xC1, 0xBF,
	0xD2, 0xC7
};                    //温湿度测量仪
unsigned char temperature[] = {
	0xCE, 0xC2,
	0xB6, 0xC8
};                    //温度：
unsigned char humidity[] = {
	0xCA, 0xAA,
	0xB6, 0xC8
};                    //湿度
unsigned char school[] = {
	0xCE, 0xEF,
	0xC0, 0xED,
	0xD1, 0xA7,
	0xD4, 0xBA
};                    //物理学院
unsigned char centigrade[] = {
	0xA1, 0xE6
};                    //℃
unsigned char percent[] = {
	0xA3, 0xA5
};                    //％

void setup()
{
	LCDA.Initialise(); // 屏幕初始化
	delay(100);
	LCDA.CLEAR();	//清屏
	delay(100);
	LCDA.DisplayString(0, 1, project, AR_SIZE(project));
	LCDA.DisplayString(1, 2, temperature, AR_SIZE(temperature));
	LCDA.DisplayString(2, 2, humidity, AR_SIZE(humidity));
	LCDA.DisplayString(3, 4, school, AR_SIZE(school));
	LCDA.DisplayString(1, 5, centigrade, AR_SIZE(centigrade));
	LCDA.DisplayString(2, 5, percent, AR_SIZE(percent));

}

void loop()
{
	DHT11.read11(DHT11PIN);
	LCDA.DisplayNum(1, 4, DHT11.temperature);
	LCDA.DisplayNum(2, 4, DHT11.humidity);
	delay(1000);
}