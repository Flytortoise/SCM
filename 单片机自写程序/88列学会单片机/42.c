/*	2016年10月26日 10:19:02  单片机实习 计算器数码管显示，从23号下午开始
	缺陷：1.显示只能从最左边开始，位数不能跳转。
		  2.不支持浮点运算,运算不精确
		  3.第二个运算符必须为'='
		  4.仅支持正数的加减乘除，且结果也必须为正才行  */


#include<absacc.h>
#include<reg51.h>
#define dula XBYTE[0x08004]
#define wela XBYTE[0x08002] //列与位复用
#define hang XBYTE[0X08001]
unsigned char code table1[] = {0x01,0x02,0x04,0x08,0x10,0x20};	//选择数码管第几位显示
unsigned char code table2[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x7c,0x39,0x5e,0x79,0x71,0x00};
          //显示0~F,最后一个是不显示
unsigned char s1,s2,s3,s4,s5,s6;	//显示的6位
unsigned int wei,num,ok;	//wei记录位数， num记录具体数字， ok记录产生的第几个符号
void init()       //初始化
{
 dula = 0x00;
 wela = 0x00;
 s1 = 16; s2 = 16; s3 = 16; s4 = 16; s5 = 16 ; s6 = 16 ;
 wei = 0; ok = 0;num = 0;
}

void delay(unsigned int i)            //延迟,i为1时，延迟1ms
{
   unsigned int j,k;
   for(j = 0;j < i;j++)
         for(k = 0; k<200;k++);

}
void display(unsigned a,unsigned b,unsigned c,unsigned d,unsigned e,unsigned f)
                  
{
      wela = table1[5];          //显示位选
      dula = table2[a];          //a用于显示段选
      delay(22);
		
	  wela = table1[4];          
      dula = table2[b];         
      delay(22);

	  wela = table1[3];          
      dula = table2[c];         
      delay(22);

	  wela = table1[2];          
      dula = table2[d];         
      delay(22);

      wela = table1[1];          
      dula = table2[e];         
      delay(22);

      wela = table1[0];          
      dula = table2[f];         
      delay(22);
}
void scanf1()	//输入
{
    unsigned int i;
        wela = 0xDF;    //第一列
        while(hang == 0);
        i = hang;
        i = i&0x0F;
        while(i != 0x0F)  //有值输入
        {
          //delay(2);
         i = hang;      //消前抖动
         i = i&0x0F;
         while(i != 0x0F)
         {
            i = hang;
            i = i&0x0F;
            wela = 0x00;
            switch(i)
            {
             case 0x07: num = 7;wei++;break;
             case 0x0B: num = 4;wei++;break;
             case 0x0D: num = 1;wei++;break;
             case 0x0E: num = 0;wei++;break;
            }
            while(i != 0x0F)    //消后抖
            {
             i = hang;
             i = i&0x0F;
            }                  
         }
        }
        
        wela = 0xEF;       //第二列
        i = hang;
        i = i&0x0F;
        while(i != 0x0F)  //有值输入
        {
          //delay(2);
         i = hang;      //消前抖动
         i = i&0x0F;
         while(i != 0x0F)
         {
            i = hang;
            i = i&0x0F;
            wela = 0x00;
            switch(i)
            {
             case 0x07: num = 8;wei++;break;
             case 0x0B: num = 5;wei++;break;
             case 0x0D: num = 2;wei++;break;
             case 0x0E: num = 15;ok++;break;
            }
            while(i != 0x0F)    //消后抖
            {
             i = hang;
             i = i&0x0F;
            }
         }
        }
        
        wela = 0xF7;        //第三列
        i = hang;
        i = i&0x0F;
        while(i != 0x0F)  //有值输入
        {
          //delay(2);
         i = hang;      //消前抖动
         i = i&0x0F;
         while(i != 0x0F)
         {
            i = hang;
            i = i&0x0F;
            wela = 0x00;
            switch(i)
            {
             case 0x07: num = 9;wei++;break;
             case 0x0B: num = 6;wei++;break;
             case 0x0D: num = 3;wei++;break;
             case 0x0E: num = 14;ok++;break;
            }
            while(i != 0x0F)    //消后抖
            {
             i = hang;
             i = i&0x0F;
            }
         }
        }
        
        
         wela = 0xFB;    //第4列
        i = hang;
        i = i&0x0F;
        while(i != 0x0F)  //有值输入
        {
          //delay(2);
         i = hang;      //消前抖动
         i = i&0x0F;
         while(i != 0x0F)
         {
            i = hang;
            i = i&0x0F;
            wela = 0x00;
            switch(i)
            {
             case 0x07: num = 10;ok++;break;
             case 0x0B: num = 11;ok++;break;
             case 0x0D: num = 12;ok++;break;
             case 0x0E: num = 13;ok++;break;
            }
            while(i != 0x0F)    //消后抖
            {
             i = hang;
             i = i&0x0F;
            }                  
         }
        }
}

void fenjie(int a)
{
	if(a>=0 && a<10)
	{
		s1 = a; s2 = 16; s3 = 16; s4 = 16; s5 = 16 ; s6 = 16 ;
	}
	if(a>9 && a<100)
	{
		s1 = a/10;
		s2 = a%10;
		s3 = 16; s4 = 16; s5 = 16 ; s6 = 16 ;
	}
	if(a>99 & a<1000)
	{
		s1 = a/100;
		s2 = a/10%10;
		s3 = a%10;
		s4 = 16; s5 = 16 ; s6 = 16 ;
	}
	if(a>999 && a<10000)
	{
		s1 = a/1000;
		s2 = a/100%10;
		s3 = a/10%10;
		s4 = a%10;
		s5 = 16 ; s6 = 16 ;
	}
	if(a>9999 && a<100000)
	{
		s1 = a/10000;
		s2 = a/1000%10;
		s3 = a/100%10;
		s4 = a/10%10;
		s5 = a%10 ; s6 = 16 ;
	}
	if(a>99999 && a<1000000)
	{
		s1 = a/100000;
		s2 = a/10000%10;
		s3 = a/1000%10;
		s4 = a/100%10;
		s5 = a/10%10 ; 
		s6 = a%10 ;
	}
}

void main()
{
 unsigned int shu1,fuhao;
 int shu2 = -1;
 int shu  = -1;
 init();//初始化，全部清零
 while(1)
 {
   
   scanf1();	//按键输入
   if(wei)
	{
		switch(wei)		//将具体的每一位记录在s中
		{
			case 1: s1 = num;break;
			case 2: s2 = num;break;
			case 3: s3 = num;break;
			case 4: s4 = num;break;
			case 5: s5 = num;break;
			case 6: s6 = num;break;
		}
	}
   if(ok == 1)	//输入符号时，ok会自动+1，ok为1，说明出现第一个符号
	{
		switch(num)		//记录这个符号
		{
			case 10: fuhao = 10;break;
			case 11: fuhao = 11;break;
			case 12: fuhao = 12;break;
			case 13: fuhao = 13;break;
			case 14: fuhao = 14;break;	//第一个符号为=时，不做任何操作
			case 15: init();break;	//清零符号
		}
		switch(wei)		//生成第一个具体数字
		{
			case 1: shu1 = s1;break;
			case 2: shu1 = s1*10+s2;break;
			case 3: shu1 = s1*100+s2*10+s3;break;
			case 4: shu1 = s1*1000+s2*100+s3*10+s4;break;
			case 5: shu1 = s1*10000+s2*1000+s3*100+s4*10+s5;break;
			case 6: shu1 = s1*100000+s2*10000+s3*1000+s4*100+s5*10+s6;break;
		}
		wei = 0;		//清零来生成第二个数字
		s1 = fuhao;		//显示符号，顺便清零
		s2 = 16; s3 = 16; s4 = 16;s5 = 16 ; s6 = 16 ;
	}
	if(ok == 2)			//说明产生第二个符号，这里规定第二个符号必须为'='
	{	
		ok = 0;			//清零，以便下次运算
		switch(wei)		//生成第二个数字
		{
			case 1: shu2 = s1;break;
			case 2: shu2 = s1*10+s2;break;
			case 3: shu2 = s1*100+s2*10+s3;break;
			case 4: shu2 = s1*1000+s2*100+s3*10+s4;break;
			case 5: shu2 = s1*10000+s2*1000+s3*100+s4*10+s5;break;
			case 6: shu2 = s1*100000+s2*10000+s3*1000+s4*100+s5*10+s6;break;
		}
		wei = 0;		//清零，以便下次运算
	}
	if(shu2 != -1)		//第二个数字已经产生
    {
		switch(fuhao)	//根据第一个符号，来计算结果
		{
		 	case 10: shu = shu1 + shu2;break;
			case 11: shu = shu1 - shu2;break;
			case 12: shu = shu1 * shu2;break;
			case 13: shu = shu1 / shu2;break;
			case 14: ;break;		//第一个符号为=，不做任何操作
			case 15: init();break;	//清零按键
		}
		
	}
	if(shu != -1)	//结果已经产生
	{
		fenjie(shu);	//将结果分解到每一位的具体数字
	}
   display(s1,s2,s3,s4,s5,s6) ;    
 }
}


