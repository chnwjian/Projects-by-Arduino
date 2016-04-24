/*****
	Show temperature with dig3 and dig2
	Show humidity with dig1 and dig0
	Change once per second
*****/
/*7-segment display (common anode) with 2 74hc595*/
/*Show numbers from 0-9 with dig0,dig1,dig2,dig3*/
/*λ: dig0 dig1 dig2 dig3 a b c d e f g dp*/
/*����0-9��Ӧ���룺03 9F 25 0D 99 49 41 1F 01 09*/

#include <MsTimer2.h>
#include <dht.h>
#define SCLK 8	//��������ʱ����
#define RCLK 9	//����洢������ʱ����
#define SI 10	//������	
#define DHTPIN 11	//DHT11 Input
#define DELAY 1
dht DHT;
int digNum[4] = { 0 };
int tempT;
int tempH;
void setup()
{
	pinMode(SCLK, OUTPUT);
	pinMode(RCLK, OUTPUT);
	pinMode(SI, OUTPUT);
	MsTimer2::set(12, writeSeg);
	Serial.begin(9600);
	MsTimer2::start();
}

void loop()
{
	int chk=DHT.read11(DHTPIN);

	tempT = DHT.temperature;
	tempH = DHT.humidity;
	if(chk==DHTLIB_OK)
	{ 
		digNum[3] = tempT / 10;
		digNum[2] = tempT % 10;
		digNum[1] = tempH / 10;
		digNum[0] = tempH % 10;	
	}
	Serial.println(chk);
	delay(3000);
}

void writeSeg()
{
	int i;
	int j;

	for (j=0; j < 5; j++)
	{
		for (i=0; i < 4; i++)
		{
			segDisplay(i, digNum[i], 0);
			//delay(DELAY);
		}
	}
	segDisplay(i, digNum[i], 0);	//i=5,�ض����������
	
}
void segDisplay(int dig, int num, int dp)	//��������λѡ����ѡ����(dp=1ʱ��������
{
	int numIn;
	int NUM[10] = { 0x03,0x9F,0x25,0x0D,0x99,0x49,0x41,0x1F,0x01,0x09};
	int DIG[5] = { 0x80,0x40,0x20,0x10,0x00 };	//from left to right, dp=1
	int a = 0xFE;
		
	numIn = (NUM[num]) & (bitWrite(a, 0, ~(!!dp)));	//bitWrite(x, bitPosition, value);	!!���Խ��ǲ���������ʱ���ɲ�������ʹ��
	digitalWrite(RCLK, LOW);
	shiftOut(SI, SCLK, LSBFIRST, numIn);
	shiftOut(SI, SCLK, LSBFIRST, DIG[dig]);
	digitalWrite(RCLK, HIGH);
}
