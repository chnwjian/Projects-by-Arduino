/*****
ʹ��12864��ʾӢ����ĸ
���߷�ʽ��
PSB	-	GND
RS	-	8
R/W	-	9
E	-	10
*****/
#include <LCD12864RSPI.h>
#define AR_SIZE( a ) sizeof( a ) / sizeof( a[0] )unsigned char show0[] = "Arduino mega2560";void setup(){	LCDA.Initialise(); // ��Ļ��ʼ��	delay(100);	LCDA.CLEAR();	//����	delay(100);	//�ӵ�һ�е�һ��ʼ��ʾ	LCDA.DisplayString(0, 0, show0, AR_SIZE(show0));	}void loop(){}