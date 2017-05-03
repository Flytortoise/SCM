//由于矩阵键盘与串口引脚冲突，因此本题仅供学习参考。
#include <reg52.h>    		//52系列单片机头文件
#define uchar unsigned char
#define uint unsigned int 
uchar flag,key;
void delayms(uint xms)				
{
	uint i,j;
	for(i=xms;i>0;i--)		      //i=xms即延时约xms毫秒
		for(j=110;j>0;j--);
}
void matrixkeyscan()
{
	uchar temp;
	TR1=0;
    P3=0xfe;
    temp=P3;
    temp=temp&0xf0;
    if(temp!=0xf0)
    {
      delayms(10);
	  temp=P3;
	  temp=temp&0xf0;
      if(temp!=0xf0)
      {
        temp=P3;
		TH1=0xe8; //波特率设置为1200
		TL1=0xe8;
        switch(temp)
        {
          case 0xee:
			   key=1;
               break;
          case 0xde:
			   key=2;
               break;
          case 0xbe:
			   key=3;
               break;
          case 0x7e:
 			   key=4;
               break;
         }
         while(temp!=0xf0)
         {
           temp=P3;
           temp=temp&0xf0;
         }
		 flag=1;
      }
    }
    P3=0xfd;
    temp=P3;
    temp=temp&0xf0;
    if(temp!=0xf0)
    {
      delayms(10);
      temp=P3;
      temp=temp&0xf0;
      if(temp!=0xf0)
      {
        temp=P3;
		TH1=0xf4; //波特率设置为2400
		TL1=0xf4;
        switch(temp)
        {
          case 0xed:
			   key=5;
               break;
          case 0xdd:
			   key=6;
               break;
          case 0xbd:
			   key=7;
               break;
          case 0x7d:
			   key=8;
               break;
         }
         while(temp!=0xf0)
         {
           temp=P3;
           temp=temp&0xf0;
         }
		 flag=1;
      }
      }
    P3=0xfb;
    temp=P3;
    temp=temp&0xf0;
    if(temp!=0xf0)
    {
      delayms(10);
   	  temp=P3;
      temp=temp&0xf0;
      if(temp!=0xf0)
      {
        temp=P3;
		TH1=0xfa; //波特率设置为4800
		TL1=0xfa;
        switch(temp)
        {
          case 0xeb:
			   key=9;
               break;
          case 0xdb:
			   key=10;
               break;
          case 0xbb:
			   key=11;
               break;
          case 0x7b:
    		   key=12;
               break;
         }
         while(temp!=0xf0)
         {
           temp=P3;
           temp=temp&0xf0;
         }
		 flag=1;
      }
      }
    P3=0xf7;
    temp=P3;
    temp=temp&0xf0;
    if(temp!=0xf0)
    {
      delayms(10);
      temp=P3;
      temp=temp&0xf0;
      if(temp!=0xf0)
      {
        temp=P3;
		TH1=0xfd; //波特率设置为9600
		TL1=0xfd;
        switch(temp)
        {
          case 0xe7:
			   key=13;
               break;
          case 0xd7:
			   key=14;
               break;
          case 0xb7:
			   key=15;
               break;
          case 0x77:
			   key=16;
               break;
         }
         while(temp!=0xf0)
         {
           temp=P3;
           temp=temp&0xf0;
         }
		 flag=1;
      }
    }
	TR1=1;
}
void main()
{
	TMOD=0x20;//设置定时器1为工作方式2
	TH1=0xe8; //波特率设置为1200
	TL1=0xe8;
	SM0=0;
	SM1=1;
	while(1)
	{
		matrixkeyscan();
		P3=0xff;
		if(flag==1)
		{
			flag=0;
			SBUF=key;
			while(!TI);
			TI=0;
		}
	}
}
