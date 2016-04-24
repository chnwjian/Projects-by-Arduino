/*7-segment display (common anode) with 2 74hc595*/
/*Show numbers from 0-9 with dig0,dig1,dig2,dig3*/
/*位: dig0 dig1 dig2 dig3 a b c d e f g dp*/
/*数字0-9对应段码：03 9F 25 0D 99 49 41 1F 01 09*/

#define SCLK 8	//数据输入时钟线
#define RCLK 9	//输出存储器锁存时钟线
#define SI 10	//数据线	
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

void segDisplay(int dig, int num, int dp)	//参数包括位选、段选、点(dp=1时，点亮）
{
	int numIn;
	int NUM[10] = { 0x03,0x9F,0x25,0x0D,0x99,0x49,0x41,0x1F,0x01,0x09};
	int DIG[4] = { 0x80,0x40,0x20,0x10 };	//from left to right, dp=1
	int a = 0xFE;
		
	numIn = (NUM[num]) & (bitWrite(a, 0, ~(!!dp)));	//bitWrite(x, bitPosition, value);	!!可以将非布尔变量临时当成布尔变量使用
	digitalWrite(RCLK, LOW);
	shiftOut(SI, SCLK, LSBFIRST, numIn);
	shiftOut(SI, SCLK, LSBFIRST, DIG[dig]);
	digitalWrite(RCLK, HIGH);
}
