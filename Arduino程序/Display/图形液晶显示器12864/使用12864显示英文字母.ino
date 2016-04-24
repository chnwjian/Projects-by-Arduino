/*****
使用12864显示英文字母
接线方式：
PSB	-	GND
RS	-	8
R/W	-	9
E	-	10
*****/
#include <LCD12864RSPI.h>
#define AR_SIZE( a ) sizeof( a ) / sizeof( a[0] )unsigned char show0[] = "Arduino mega2560";void setup(){	LCDA.Initialise(); // 屏幕初始化	delay(100);	LCDA.CLEAR();	//清屏	delay(100);	//从第一行第一格开始显示	LCDA.DisplayString(0, 0, show0, AR_SIZE(show0));	}void loop(){}