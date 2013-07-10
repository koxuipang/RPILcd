#define LCD_24		24
#define LCD_28		28

#define swap(i,j)			{int t;t=i;i=j;j=t;}
#define CAL_X 				0x00378F66UL
#define CAL_Y 				0x03C34155UL
#define CAL_S 				0x000EF13FUL

#define PREC_LOW			1
#define PREC_MEDIUM			2
#define PREC_HI				3
#define PREC_EXTREME		4

#define RIGHT 				9999
#define CENTER 				9998

void delayP(int a);
void DspSignalColor(unsigned char h,unsigned char l);
void SetPinNU(short P0,short P1,short P2,short P3,short P4,short P5,short P6,short P7,
			  short Prs,short Pcs,short Pwr,short Prst,short Pdout,short Pirq,short Pdin,short Pclk,short Ptcs);
void SetLCDSize(int a);
void WriteCommand(unsigned int c);
void WriteData(unsigned int c);
void WriteCommandData(unsigned int cmd,unsigned int dat);
void SetXY(unsigned int x0,unsigned int y0,unsigned int x1,unsigned int y1);
void fillScr(unsigned int color);
void fillScrRGB(int r, int g, int b);
void clrScr();
void clrXY();
void setColor(long int color);
void setColorRGB(int r, int g, int b);
void setBackColor(int color);
void setBackColorRGB(int r, int g, int b);
void drawRect(int x1, int y1, int x2, int y2);
void drawHLine(int x, int y, int l);
void drawVLine(int x, int y, int l);
void drawLine(int x1, int y1, int x2, int y2);
void drawRoundRect(int x1, int y1, int x2, int y2);
void drawPixel(int x, int y);
void setPixel(int color);
void fillRect(int x1, int y1, int x2, int y2);
void fillRoundRect(int x1, int y1, int x2, int y2);
void drawCircle(int x, int y, int radius);
void fillCircle(int x, int y, int radius);
void printChar(unsigned char c, int x, int y);
void setFont(unsigned short int mxsize,unsigned short int mysize);
void Touch_Init(void);
void Touch_WriteData(unsigned char data);
unsigned int Touch_ReadData(void);
void Touch_Read(void);
char Touch_DataAvailable(void);
int Touch_GetX(void);
int Touch_GetY(void);
void rotateChar(unsigned char c, int x, int y, int pos, int deg);
void print(char *st, int x, int y, int deg);
unsigned char* getFont();
unsigned int getFontXsize();
unsigned int getFontYsize();
int getDisplayXSize();
int getDisplayYSize();
void printNumI(long num, int x, int y, int length, char filler);
void printNumF(double num, unsigned char dec, int x, int y, char divider, int length, char filler);
void drawBitmap(int x, int y, int sx, int sy, unsigned int* data, int deg, int rox, int roy);
void drawBitmapP(int x, int y, int sx, int sy, unsigned int* data, int scale);
unsigned int getColor(void);
unsigned int getBackColor(void);
void setPrecision(short precision);
