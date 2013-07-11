#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <wiringPi.h>

#define RIGHT 		9999
#define CENTER 		9998
#define LCD_24		24
#define LCD_28		28

void SetPinNU(short P0,short P1,short P2,short P3,short P4,short P5,short P6,short P7,
			  short Prs,short Pcs,short Pwr,short Prst,short Pdout,short Pirq,short Pdin,short Pclk,short Ptcs)
{
	D0 = P0;	//1
	D1 = P1;	//3
	D2 = P2;	//4
	D3 = P3;	//7
	D4 = P4;	//8
	D5 = P5;	//10
	D6 = P6;	//13
	D7 = P7;	//14

	RS = Prs;	//15
	CS = Pcs;	//16
	WR = Pwr;	//19
	RST = Prst;	//21

	T_DOUT = Pdout; //22
	T_IRQ  = Pirq;	//23
	T_DIN  = Pdin;	//24
	T_CLK  = Pclk;	//25
	T_CS   = Ptcs;	//26

}
void SetLCDSize(int a)
{
	
	int i,R,G,B;
	gLCDSize = a;
	gTime = 40;
	orient=LANDSCAPE;
	
	switch(gLCDSize)
	{
		case LCD_24:
		disp_x_size=239;
		disp_y_size=319;
		break;
		case LCD_28:
		disp_x_size=239;
		disp_y_size=319;
		break;
		default:
		break;
	}
	pinMode(D0, OUTPUT);
	pinMode(D1, OUTPUT);
	pinMode(D2, OUTPUT);
	pinMode(D3, OUTPUT);
	pinMode(D4, OUTPUT);
	pinMode(D5, OUTPUT);
	pinMode(D6, OUTPUT);
	pinMode(D7, OUTPUT);

	pinMode(CS, OUTPUT);
	pinMode(RS, OUTPUT);
	pinMode(WR, OUTPUT);
	pinMode(RST, OUTPUT);
		
	digitalWrite(RST, 1);
	delay(1);
	digitalWrite(RST, 0);
	delay(1);
	digitalWrite(RST, 1);
	digitalWrite(CS, 1);
	digitalWrite(WR, 1);
	delay(20);

	switch(gLCDSize)
	{

		case LCD_24:
			WriteCommandData(0x0011,0x2004);		
			WriteCommandData(0x0013,0xCC00);		
			WriteCommandData(0x0015,0x2600);	
			WriteCommandData(0x0014,0x252A);		
			WriteCommandData(0x0012,0x0033);		
			WriteCommandData(0x0013,0xCC04);
			WriteCommandData(0x0013,0xCC06);
			WriteCommandData(0x0013,0xCC4F);
			WriteCommandData(0x0013,0x674F);
			WriteCommandData(0x0011,0x2003);
			WriteCommandData(0x0030,0x2609);		
			WriteCommandData(0x0031,0x242C);		
			WriteCommandData(0x0032,0x1F23);		
			WriteCommandData(0x0033,0x2425);		
			WriteCommandData(0x0034,0x2226);		
			WriteCommandData(0x0035,0x2523);		
			WriteCommandData(0x0036,0x1C1A);		
			WriteCommandData(0x0037,0x131D);		
			WriteCommandData(0x0038,0x0B11);		
			WriteCommandData(0x0039,0x1210);		
			WriteCommandData(0x003A,0x1315);		
			WriteCommandData(0x003B,0x3619);		
			WriteCommandData(0x003C,0x0D00);		
			WriteCommandData(0x003D,0x000D);		
			WriteCommandData(0x0016,0x0007);		
			WriteCommandData(0x0002,0x0013);		
			WriteCommandData(0x0003,0x0003);		
			WriteCommandData(0x0001,0x0127);
			WriteCommandData(0x0008,0x0303);		
			WriteCommandData(0x000A,0x000B);		
			WriteCommandData(0x000B,0x0003);   
			WriteCommandData(0x000C,0x0000);   
			WriteCommandData(0x0041,0x0000);    
			WriteCommandData(0x0050,0x0000);   
			WriteCommandData(0x0060,0x0005);    
			WriteCommandData(0x0070,0x000B);    
			WriteCommandData(0x0071,0x0000);    
			WriteCommandData(0x0078,0x0000);    
			WriteCommandData(0x007A,0x0000);   
			WriteCommandData(0x0079,0x0007);		
			WriteCommandData(0x0007,0x0051); 
			WriteCommandData(0x0007,0x0053);		
			WriteCommandData(0x0079,0x0000);
			WriteCommand(0x0022);
		break;
		case LCD_28:
			WriteCommandData(0x00E5, 0x78F0); // set SRAM internal timing
			WriteCommandData(0x0001, 0x0100); // set Driver Output Control  
			WriteCommandData(0x0002, 0x0200); // set 1 line inversion  
			WriteCommandData(0x0003, 0x1030); // set GRAM write direction and BGR=1.  
			WriteCommandData(0x0004, 0x0000); // Resize register  
			WriteCommandData(0x0008, 0x0207); // set the back porch and front porch  
			WriteCommandData(0x0009, 0x0000); // set non-display area refresh cycle ISC[3:0]  
			WriteCommandData(0x000A, 0x0000); // FMARK function  
			WriteCommandData(0x000C, 0x0000); // RGB interface setting  
			WriteCommandData(0x000D, 0x0000); // Frame marker Position  
			WriteCommandData(0x000F, 0x0000); // RGB interface polarity  
			//*************Power 00On sequence ****************//  
			WriteCommandData(0x0010, 0x0000); // SAP, BT[3:0], AP, DSTB, SLP, STB  
			WriteCommandData(0x0011, 0x0007); // DC1[2:0], DC0[2:0], VC[2:0]  
			WriteCommandData(0x0012, 0x0000); // VREG1OUT voltage  
			WriteCommandData(0x0013, 0x0000); // VDV[4:0] for VCOM amplitude  
			WriteCommandData(0x0007, 0x0001);  
			delay(200); // Dis-ch00arge capacitor power voltage  
			WriteCommandData(0x0010, 0x1690); // SAP, BT[3:0], AP, DSTB, SLP, STB  
			WriteCommandData(0x0011, 0x0227); // Set DC1[2:0], DC0[2:0], VC[2:0]  
			delay(50); // Delay 5000ms  
			WriteCommandData(0x0012, 0x000D); // 0012  
			delay(50); // Delay 5000ms  
			WriteCommandData(0x0013, 0x1200); // VDV[4:0] for VCOM amplitude  
			WriteCommandData(0x0029, 0x000A); // 04  VCM[5:0] for VCOMH  
			WriteCommandData(0x002B, 0x000D); // Set Frame Rate  
			delay(50); // Delay 5000ms  
			WriteCommandData(0x0020, 0x0000); // GRAM horizontal Address  
			WriteCommandData(0x0021, 0x0000); // GRAM Vertical Address  
			// ----------- Adjust00 the Gamma Curve ----------//  
			WriteCommandData(0x0030, 0x0000);  
			WriteCommandData(0x0031, 0x0404);  
			WriteCommandData(0x0032, 0x0003);  
			WriteCommandData(0x0035, 0x0405);  
			WriteCommandData(0x0036, 0x0808);  
			WriteCommandData(0x0037, 0x0407);  
			WriteCommandData(0x0038, 0x0303);  
			WriteCommandData(0x0039, 0x0707);  
			WriteCommandData(0x003C, 0x0504);  
			WriteCommandData(0x003D, 0x0808);  
			//------------------ 00Set GRAM area ---------------//  
			WriteCommandData(0x0050, 0x0000); // Horizontal GRAM Start Address  
			WriteCommandData(0x0051, 0x00EF); // Horizontal GRAM End Address  
			WriteCommandData(0x0052, 0x0000); // Vertical GRAM Start Address  
			WriteCommandData(0x0053, 0x013F); // Vertical GRAM Start Address  
			WriteCommandData(0x0060, 0xA700); // Gate Scan Line  
			WriteCommandData(0x0061, 0x0001); // NDL,VLE, REV   
			WriteCommandData(0x006A, 0x0000); // set scrolling line  
			//-------------- Part00ial Display Control ---------//  
			WriteCommandData(0x0080, 0x0000);  
			WriteCommandData(0x0081, 0x0000);  
			WriteCommandData(0x0082, 0x0000);  
			WriteCommandData(0x0083, 0x0000);  
			WriteCommandData(0x0084, 0x0000);  
			WriteCommandData(0x0085, 0x0000);  
			//-------------- Pane00l Control -------------------//  
			WriteCommandData(0x0090, 0x0010);  
			WriteCommandData(0x0092, 0x0000);  
			WriteCommandData(0x0007, 0x0133);
		break;
		default:
		break;
	}
}
void WriteCommand(unsigned int c)
{
		digitalWrite(RS,0);
		delayP(gTime);
		digitalWrite(CS,0);
		delayP(gTime);
		if(c>>8&0x01)
		{
			digitalWrite(D0,1);
		}
		else
		{
			digitalWrite(D0,0);	
		}
		if(c>>8&0x02)
		{
			digitalWrite(D1,1);	
		}
		else
		{
			digitalWrite(D1,0);	
		}
		if(c>>8&0x04)
		{
			digitalWrite(D2,1);	
		}
		else
		{
			digitalWrite(D2,0);	
		}
		if(c>>8&0x08)
		{
			digitalWrite(D3,1);	
		}
		else
		{
			digitalWrite(D3,0);	
		}
		if(c>>8&0x10)
		{
			digitalWrite(D4,1);	
		}
		else
		{
			digitalWrite(D4,0);	
		}
		if(c>>8&0x20)
		{
			digitalWrite(D5,1);	
		}
		else
		{
			digitalWrite(D5,0);	
		}
		if(c>>8&0x40)
		{
			digitalWrite(D6,1);	
		}
		else
		{
			digitalWrite(D6,0);	
		}
		if(c>>8&0x80)
		{
			digitalWrite(D7,1);	
		}
		else
		{
			digitalWrite(D7,0);	
		}
		delayP(gTime);
		digitalWrite(WR,0);
		delayP(gTime);
		digitalWrite(WR,1);
		delayP(gTime);
		if(c&0x01)
		{
			digitalWrite(D0,1);	
		}
		else
		{
			digitalWrite(D0,0);	
		}
		if(c&0x02)
		{
			digitalWrite(D1,1);	
		}
		else
		{
			digitalWrite(D1,0);	
		}
		if(c&0x04)
		{
			digitalWrite(D2,1);	
		}
		else
		{
			digitalWrite(D2,0);	
		}
		if(c&0x08)
		{
			digitalWrite(D3,1);	
		}
		else
		{
			digitalWrite(D3,0);	
		}
		if(c&0x10)
		{
			digitalWrite(D4,1);	
		}
		else
		{
			digitalWrite(D4,0);	
		}
		if(c&0x20)
		{
			digitalWrite(D5,1);	
		}
		else
		{
			digitalWrite(D5,0);	
		}
		if(c&0x40)
		{
			digitalWrite(D6,1);	
		}
		else
		{
			digitalWrite(D6,0);	
		}
		if(c&0x80)
		{
			digitalWrite(D7,1);	
		}
		else
		{
			digitalWrite(D7,0);	
		}
		delayP(gTime);
		digitalWrite(WR,0);
		delayP(gTime);
		digitalWrite(WR,1);
		delayP(gTime);
		digitalWrite(CS,1);
}
void WriteData(unsigned int c)
{
		digitalWrite(RS,1);
		delayP(gTime);
		digitalWrite(CS,0);
		delayP(gTime);
		if(c>>8&0x01)
		{
			digitalWrite(D0,1);	
		}
		else
		{
			digitalWrite(D0,0);	
		}
		if(c>>8&0x02)
		{
			digitalWrite(D1,1);	
		}
		else
		{
			digitalWrite(D1,0);	
		}
		if(c>>8&0x04)
		{
			digitalWrite(D2,1);	
		}
		else
		{
			digitalWrite(D2,0);	
		}
		if(c>>8&0x08)
		{
			digitalWrite(D3,1);	
		}
		else
		{
			digitalWrite(D3,0);	
		}
		if(c>>8&0x10)
		{
			digitalWrite(D4,1);	
		}
		else
		{
			digitalWrite(D4,0);	
		}
		if(c>>8&0x20)
		{
			digitalWrite(D5,1);	
		}
		else
		{
			digitalWrite(D5,0);	
		}
		if(c>>8&0x40)
		{
			digitalWrite(D6,1);	
		}
		else
		{
			digitalWrite(D6,0);	
		}
		if(c>>8&0x80)
		{
			digitalWrite(D7,1);	
		}
		else
		{
			digitalWrite(D7,0);	
		}
		digitalWrite(WR,0);
		delayP(gTime);
		digitalWrite(WR,1);
		delayP(gTime);
		if(c&0x01)
		{
			digitalWrite(D0,1);	
		}
		else
		{
			digitalWrite(D0,0);	
		}
		if(c&0x02)
		{
			digitalWrite(D1,1);	
		}
		else
		{
			digitalWrite(D1,0);	
		}
		if(c&0x04)
		{
			digitalWrite(D2,1);	
		}
		else
		{
			digitalWrite(D2,0);	
		}
		if(c&0x08)
		{
			digitalWrite(D3,1);	
		}
		else
		{
			digitalWrite(D3,0);	
		}
		if(c&0x10)
		{
			digitalWrite(D4,1);	
		}
		else
		{
			digitalWrite(D4,0);	
		}
		if(c&0x20)
		{
			digitalWrite(D5,1);	
		}
		else
		{
			digitalWrite(D5,0);	
		}
		if(c&0x40)
		{
			digitalWrite(D6,1);	
		}
		else
		{
			digitalWrite(D6,0);	
		}
		if(c&0x80)
		{
			digitalWrite(D7,1);	
		}
		else
		{
			digitalWrite(D7,0);	
		}
		digitalWrite(WR,0);
		delayP(gTime);
		digitalWrite(WR,1);
		delayP(gTime);
		digitalWrite(CS,1);

}
void WriteCommandData(unsigned int cmd,unsigned int dat)
{
	WriteCommand(cmd);
	WriteData(dat);
}
void SetXY(unsigned int x0,unsigned int y0,unsigned int x1,unsigned int y1)
{

	switch(gLCDSize)
	{
	case LCD_24:
	swap(x0, y0);
	swap(x1, y1);
	y0=disp_y_size-y0;
	y1=disp_y_size-y1;
	swap(y0, y1);

	WriteCommandData(0x0046,(x1<<8)|x0);
	WriteCommandData(0x0047,y1);
	WriteCommandData(0x0048,y0);
	WriteCommandData(0x0020,x0);
	WriteCommandData(0x0021,y0);
	WriteCommand(0x0022);
	break;
	case LCD_28:
	swap(x0, y0);
	swap(x1, y1);
	y0=disp_y_size-y0;
	y1=disp_y_size-y1;
	swap(y0, y1);

	WriteCommandData(0x20,x0);
	WriteCommandData(0x21,y0);
	WriteCommandData(0x50,x0);
	WriteCommandData(0x52,y0);
	WriteCommandData(0x51,x1);
	WriteCommandData(0x53,y1);
	WriteCommand(0x22);
	break;
	default:
	break;
	}
}
void fillScr(unsigned int color)
{
	int i,j;
	SetXY(0,0,disp_y_size,disp_x_size);

  	for(i=0;i<disp_x_size;i++)
	{
	  for (j=0;j<disp_y_size;j++)
	    {	
        	WriteData(color);
	    }
	}
}
void main(void)
{
	wiringPiSetupPhys();								//设置树莓派GPIO
	
	pinMode(1,OUTPUT);
	pinMode(3,OUTPUT);
	pinMode(4,OUTPUT);
	pinMode(7,OUTPUT);
	pinMode(8,OUTPUT);
	pinMode(10,OUTPUT);
	pinMode(13,OUTPUT);
	pinMode(14,OUTPUT);
	pinMode(15,OUTPUT);
	pinMode(16,OUTPUT);
	pinMode(19,OUTPUT);
	pinMode(21,OUTPUT);
	
	SetPinNU(1,3,4,7,8,10,13,14,15,16,19,21,22,22,22,22,22);	//设置引脚（参考树莓派GPIO映射图）
	SetLCDSize(LCD_28);									//设置使用的LCD尺寸	
	Touch_Init();										//初始化触摸
//	setFont(8,12);										//设置字体为8x12
//	setColor(0x07e0);									//设置字体颜色
//	setBackColor(0xf800);								//设置背景颜色	
	printf("Init is ok!\n");
	while(1)
	{
		fillScr(0x07e0);
		delay(1000);
		fillScr(0xf800);
		delay(1000);
	}

}
