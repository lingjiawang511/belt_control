#include "led.h"

#define LED_LIGHT_TIMEOUT  4000			//N*5MS
u8 Gled_Num;
u8 Rled_Num;
u8 Gled_Light_Static;
u8 Rled_Light_Static;
//=============================================================================
//��������: LED_GPIO_Config
//���ܸ�Ҫ:LED����������
//��������:��
//��������:��
//ע��    :��
//=============================================================================
void LED_GPIO_Config(void)
{	
	//����һ��GPIO_InitTypeDef ���͵Ľṹ�壬���ֽ�GPIO_InitStructure 
	GPIO_InitTypeDef  GPIO_InitStructure;
	//ʹ��GPIOC������ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	//ѡ��Ҫ�õ�GPIO����		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11|GPIO_Pin_12;
	///��������ģʽΪ�������ģʽ			 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
	//���������ٶ�Ϊ50MHZ
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	//���ÿ⺯������ʼ��GPIO
	GPIO_Init(GPIOA, &GPIO_InitStructure);

 	GLED_OFF;
	Gled_Num = 1;
	Rled_Num = 0;
}

//=============================================================================
//��������:Gled_Flash
//���ܸ�Ҫ:��ɫLED��˸����
//��������:��
//��������:��
//ע��    :��
//=============================================================================
static void Gled_Flash(void )
{
	static u8 retry = 50; //led��˸ʱ����
	static u8 led_state=1;
	if(Gled_Num > 0){
		retry--;
		if(retry <=0){
			if(led_state){
			   GLED_ON;
			   led_state = 0;
			}else{
			   GLED_OFF;
//			   Gled_Num--;
			   led_state = 1;
			}
			retry = 50;
		}
	}	
}
//=============================================================================
//��������:Rled_Flash
//���ܸ�Ҫ:��ɫLED��˸����
//��������:��
//��������:��
//ע��    :��
//=============================================================================
static void Rled_Flash(void )
{
	static u8 retry = 50; //led��˸ʱ����
	static u8 led_state=1;
	if(Rled_Num > 0){
		retry--;
		if(retry <=0){
			if(led_state){
			   RLED_ON;
			   led_state = 0;
			}else{
			   RLED_OFF;
//			   Rled_Num--;
			   led_state = 1;
			}
			retry = 50;
		}
	}	
}
//=============================================================================
//��������:Led_Flash
//���ܸ�Ҫ:LED��˸����
//��������:��
//��������:��
//ע��    :�˺�����Ҫ��5MS��ʱ��2�ж��е���
//=============================================================================
void Led_Flash(void)
{
	static u16 gled_light_time = 0;
	static u16 rled_light_time = 0;
	Gled_Flash();
	Rled_Flash();
	if(Gled_Light_Static == 1){
		gled_light_time++;
		if(gled_light_time >= LED_LIGHT_TIMEOUT ){
			GLED_OFF;
			Gled_Light_Static = 0;
			gled_light_time = 0;
		}
	}
	if(Rled_Light_Static == 1){
		rled_light_time++;
		if(rled_light_time >= LED_LIGHT_TIMEOUT ){
			RLED_OFF;
			Rled_Light_Static = 0;
			rled_light_time = 0;
		}
	}
}





