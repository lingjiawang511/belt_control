#include"HeadType.h"	
#include "usart.h"
#include "TIM.h"

void delay_ms1(u16 ms)
{
	u16  i;
	u32  j;
	for(i=ms;i>0;i--)
	{
		for(j=5000;j>0;j--)
		;
	}
  if(j > 5000){
    j = 0;
  }
   if(i > 5200){
    i = 0;
  }
}
//配置时钟在target宏定义
int main(void)
{
  static u8 testmaster = 0;
   static u8 testmaster1 = 0;
  static u8 branchmaster = 0;
		delay_init();
		Belt11_Config();
		Belt12_Config();
		LED_GPIO_Config();
		KEY_GPIO_Config();
		belt11.actual_time = switch_init_time();
		belt12.actual_time = switch_init_time();
    TIM2_Config();
    TIM3_Config();
		delay_ms(100);
    while(1){
      testmaster1++;
      branchmaster++;
			Belt11_Control();
			Belt12_Control();
		}
		
        
}




