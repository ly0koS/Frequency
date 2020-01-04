#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "timer.h"
#include "lcd.h"

//ALIENTEK 探索者STM32F407开发板 实验10
//输入捕获实验 -库函数版本
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com  
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK
 
 
   				
extern uint32_t Freq_InputCapture;
  
	
int main(void)
{ 
	u8 freq[8];
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);  //初始化延时函数
	uart_init(115200);//初始化串口波特率为115200
	LCD_Init();
	LCD_Display_Dir(1);	
	POINT_COLOR=RED;
	LCD_Clear(WHITE);
// 	TIM14_PWM_Init(500-1,84-1);       	//84M/84=1Mhz的计数频率计数到500,PWM频率为1M/500=2Khz     
 	TIM5_CH1_Cap_Init(0XFFFFFFFF,0); //以1Mhz的频率计数 
   	while(1)
	{
				sprintf((char*)freq,"Freq:%-7d Hz",Freq_InputCapture);
				POINT_COLOR=BLUE;
				printf("HIGH:%d Hz\r\n",Freq_InputCapture); //打印总的高点平时间
				LCD_ShowString(250,250,400,24,24,freq);
		
	}
}
