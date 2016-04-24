/*7-segment display (common anode) with 2 74hc595*/
/*Show numbers from 0-9 with dig0,dig1,dig2,dig3*/
/*λ: dig0 dig1 dig2 dig3 a b c d e f g dp*/
/*����0-9��Ӧ���룺03 9F 25 0D 99 49 41 1F 01 09*/

#define SCLK 8	//��������ʱ����
#define RCLK 9	//����洢������ʱ����
#define SI 10	//������	
#define DELAY 2
void setup()
{
	pinMode(SCLK, OUTPUT);
	pinMode(RCLK, OUTPUT);
	pinMode(SI, OUTPUT);
}

void loop()
{
	segDisplay(3, 4, 0);
	delay(DELAY);
	segDisplay(2, 3, 0);
	delay(DELAY);
	segDisplay(1, 2, 0);
	delay(DELAY);
	segDisplay(0, 1, 0);
	delay(DELAY);
}

void segDisplay(int dig, int num, int dp)	//��������λѡ����ѡ����(dp=1ʱ��������
{
	int numIn;
	int NUM[10] = { 0x03,0x9F,0x25,0x0D,0x99,0x49,0x41,0x1F,0x01,0x09};
	int DIG[4] = { 0x80,0x40,0x20,0x10 };	//from left to right, dp=1
	int a = 0xFE;
		
	numIn = (NUM[num]) & (bitWrite(a, 0, ~(!!dp)));	//bitWrite(x, bitPosition, value);	!!���Խ��ǲ���������ʱ���ɲ�������ʹ��
	digitalWrite(RCLK, LOW);
	shiftOut(SI, SCLK, LSBFIRST, numIn);
	shiftOut(SI, SCLK, LSBFIRST, DIG[dig]);
	digitalWrite(RCLK, HIGH);
}
