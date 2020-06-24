#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "timer.h"
#include "lcd.h"


 
   				
extern uint32_t Freq_InputCapture;
  
	
int main(void)
{ 
	u8 freq[8];
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);  //��ʼ����ʱ����
	uart_init(115200);//��ʼ�����ڲ�����Ϊ115200
	LCD_Init();
	LCD_Display_Dir(1);	
	POINT_COLOR=RED;
	LCD_Clear(WHITE);
// 	TIM14_PWM_Init(500-1,84-1);       	//84M/84=1Mhz�ļ���Ƶ�ʼ�����500,PWMƵ��Ϊ1M/500=2Khz     
 	TIM5_CH1_Cap_Init(0XFFFFFFFF,0); //��1Mhz��Ƶ�ʼ��� 
   	while(1)
	{
				sprintf((char*)freq,"Freq:%-7d Hz",Freq_InputCapture);
				POINT_COLOR=BLUE;
				printf("HIGH:%d Hz\r\n",Freq_InputCapture); //��ӡ�ܵĸߵ�ƽʱ��
				LCD_ShowString(250,250,400,24,24,freq);
		
	}
}
