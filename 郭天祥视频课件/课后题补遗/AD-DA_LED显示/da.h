sbit dawr=P3^6;
sbit csda=P3^2;
unsigned char a,j,k;
extern void delay(unsigned char i);

void da()
{
    wela=0;
    dula=0;
    csda=0;
	a=0;
    dawr=0;
	P0=adval;
	delay(30);
//  dawr=1;

}
