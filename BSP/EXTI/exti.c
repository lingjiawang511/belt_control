#include"HeadType.h"	


//=============================================================================
//��������:EXTIX0_Init
//���ܸ�Ҫ:�ⲿ�ж�0��ʼ��
//��������:��
//��������:��
//ע��    :��
//=============================================================================
static void  EXTIX0_Init(void )
{
	 	EXTI_InitTypeDef EXTI_InitStructure;
		NVIC_InitTypeDef NVIC_InitStructure;
		GPIO_InitTypeDef  GPIO_InitStructure;
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//ʹ�ܸ��ù���ʱ��
	  GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource0);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;			 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
  	EXTI_InitStructure.EXTI_Line=EXTI_Line0;	//KEY2
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);	 	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
	
	  NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;			//ʹ�ܰ���KEY2���ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2�� 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//�����ȼ�2
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure);
}
//=============================================================================
//��������:EXTIX3_Init
//���ܸ�Ҫ:�ⲿ�ж�3��ʼ��
//��������:��
//��������:��
//ע��    :��
//=============================================================================
static void  EXTIX3_Init(void )
{
	 	EXTI_InitTypeDef EXTI_InitStructure;
		NVIC_InitTypeDef NVIC_InitStructure;
		GPIO_InitTypeDef  GPIO_InitStructure;
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//ʹ�ܸ��ù���ʱ��
//	  GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);
		GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;			 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource3);
			
  	EXTI_InitStructure.EXTI_Line=EXTI_Line3;	//KEY2
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);	 	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
	
	  NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;			//ʹ�ܰ���KEY2���ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2�� 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//�����ȼ�2
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure);
}
//=============================================================================
//��������:EXTIX4_Init
//���ܸ�Ҫ:�ⲿ�ж�4��ʼ��
//��������:��
//��������:��
//ע��    :��
//=============================================================================
static void  EXTIX4_Init(void )
{
	 	EXTI_InitTypeDef EXTI_InitStructure;
		NVIC_InitTypeDef NVIC_InitStructure;
		GPIO_InitTypeDef  GPIO_InitStructure;
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//ʹ�ܸ��ù���ʱ��
//	  GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);
		GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;			 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource4);
	
  	EXTI_InitStructure.EXTI_Line=EXTI_Line4;	//KEY2
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);	 	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
	
	  NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;			//ʹ�ܰ���KEY2���ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2�� 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					//�����ȼ�2
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure);
}
//=============================================================================
//��������:EXTIX9_5_Init
//���ܸ�Ҫ:�ⲿ�ж�9_5��ʼ��
//��������:��
//��������:��
//ע��    :��
//=============================================================================
static void  EXTIX9_5_Init(void )
{
	 	EXTI_InitTypeDef EXTI_InitStructure;
		NVIC_InitTypeDef NVIC_InitStructure;
		GPIO_InitTypeDef  GPIO_InitStructure;
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//ʹ�ܸ��ù���ʱ��
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_8;			 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
		GPIO_Init(GPIOC, &GPIO_InitStructure);
	
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource6); 
 	  GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource8);
  	EXTI_InitStructure.EXTI_Line=EXTI_Line6|EXTI_Line8;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);	 	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
	
	  NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//ʹ�ܰ���KEY2���ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2�� 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					//�����ȼ�2
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure);
}
//=============================================================================
//��������:EXTIX15_10_Init
//���ܸ�Ҫ:�ⲿ�ж�15_10��ʼ��
//��������:��
//��������:��
//ע��    :��
//=============================================================================
static void  EXTIX15_10_Init(void )
{
	 	EXTI_InitTypeDef EXTI_InitStructure;
		NVIC_InitTypeDef NVIC_InitStructure;
		GPIO_InitTypeDef  GPIO_InitStructure;
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//ʹ�ܸ��ù���ʱ��
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_12|GPIO_Pin_14;			 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource10); 
 	  GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource12);
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);
	
  	EXTI_InitStructure.EXTI_Line=EXTI_Line10|EXTI_Line12|EXTI_Line14;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);	 	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
	
	  NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;			//ʹ�ܰ���KEY2���ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2�� 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					//�����ȼ�2
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure);
}
//=============================================================================
//��������:Motor1_pulse_IRQTimer
//���ܸ�Ҫ:ͨ��1������������������
//��������:��
//��������:��
//ע��    :��
//=============================================================================
static void 	Motor1_pulse_IRQTimer(void)
{
		if(MCU_State == HOST){
				if((Channel.ch1.state == WORKING)&&(Channel.ch1.motor_irqstate == 1)){//��ʱ����ʹ�ö�ʱ����ʱ���жϽ�����״̬��8MS���ж�״̬�Ƿ�����
					Channel.ch1.motor_irqtime++;
					if(IRQ_TIMEOUT <= Channel.ch1.motor_irqtime){
						if(READ_DEVICE1_SENSOR1 == RESET){
							Channel.ch1.motor_pulse++;
						}
						Channel.ch1.motor_irqstate = 0;
						Channel.ch1.motor_irqtime = 0;
					}
					if((Channel.ch1.send_num <= Channel.ch1.motor_pulse)){ //���ת������ô��Ȧ����Ӧ�÷���ô��ҩ
							DEVICE1_MOTOR_STOP;							
							Channel.ch1.motor_state	= 0;					
						}
				}
		}
}
//=============================================================================
//��������:Motor2_pulse_IRQTimer
//���ܸ�Ҫ:ͨ��2������������������
//��������:��
//��������:��
//ע��    :��
//=============================================================================
static void 	Motor2_pulse_IRQTimer(void)
{
		if(MCU_State == HOST){
				if((Channel.ch2.state == WORKING)&&(Channel.ch2.motor_irqstate == 1)){//��ʱ����ʹ�ö�ʱ����ʱ���жϽ�����״̬��8MS���ж�״̬�Ƿ�����
					Channel.ch2.motor_irqtime++;
					if(IRQ_TIMEOUT <= Channel.ch2.motor_irqtime){
						if(READ_DEVICE2_SENSOR1 == RESET){
							Channel.ch2.motor_pulse++;
						}
						Channel.ch2.motor_irqstate = 0;
						Channel.ch2.motor_irqtime = 0;
					}
					if((Channel.ch2.send_num <= Channel.ch2.motor_pulse)){ //���ת������ô��Ȧ����Ӧ�÷���ô��ҩ
							DEVICE2_MOTOR_STOP;							
							Channel.ch2.motor_state	= 0;					
						}
				}
		}
}
//=============================================================================
//��������:Motor3_pulse_IRQTimer
//���ܸ�Ҫ:ͨ��3������������������
//��������:��
//��������:��
//ע��    :��
//=============================================================================
static void 	Motor3_pulse_IRQTimer(void)
{
		if(MCU_State == HOST){
				if((Channel.ch3.state == WORKING)&&(Channel.ch3.motor_irqstate == 1)){//��ʱ����ʹ�ö�ʱ����ʱ���жϽ�����״̬��8MS���ж�״̬�Ƿ�����
					Channel.ch3.motor_irqtime++;
					if(IRQ_TIMEOUT <= Channel.ch3.motor_irqtime){
						if(READ_DEVICE3_SENSOR1 == RESET){
							Channel.ch3.motor_pulse++;
						}
						Channel.ch3.motor_irqstate = 0;
						Channel.ch3.motor_irqtime = 0;
					}
					if((Channel.ch3.send_num <= Channel.ch3.motor_pulse)){ //���ת������ô��Ȧ����Ӧ�÷���ô��ҩ
							DEVICE3_MOTOR_STOP;							
							Channel.ch3.motor_state	= 0;					
						}
				}
		}
}
//=============================================================================
//��������:Motor4_pulse_IRQTimer
//���ܸ�Ҫ:ͨ��4������������������
//��������:��
//��������:��
//ע��    :��
//=============================================================================
static void 	Motor4_pulse_IRQTimer(void)
{
		if(MCU_State == HOST){
				if((Channel.ch4.state == WORKING)&&(Channel.ch4.motor_irqstate == 1)){//��ʱ����ʹ�ö�ʱ����ʱ���жϽ�����״̬��8MS���ж�״̬�Ƿ�����
					Channel.ch4.motor_irqtime++;
					if(IRQ_TIMEOUT <= Channel.ch4.motor_irqtime){
						if(READ_DEVICE4_SENSOR1 == RESET){
							Channel.ch4.motor_pulse++;
						}
						Channel.ch4.motor_irqstate = 0;
						Channel.ch4.motor_irqtime = 0;
					}
					if((Channel.ch4.send_num <= Channel.ch4.motor_pulse)){ //���ת������ô��Ȧ����Ӧ�÷���ô��ҩ
							DEVICE4_MOTOR_STOP;							
							Channel.ch4.motor_state	= 0;					
						}
				}
		}
}

//=============================================================================
//��������:Device1_Send_Actual_IRQTimer
//���ܸ�Ҫ:ͨ��1ʵ�ʷ�ҩ���������������ʱ���
//��������:��
//��������:��
//ע��    :��
//=============================================================================
static void 	Device1_Send_Actual_IRQTimer(void)
{
		if((Channel.ch1.send_actual_irqstate == 1)){//��ʱ����ʹ�ö�ʱ����ʱ���жϽ�����״̬��8MS���ж�״̬�Ƿ�����
					Channel.ch1.send_actual_irqtime++;
					if(IRQ_TIMEOUT <= Channel.ch1.send_actual_irqtime){
						if(READ_DEVICE1_SENSOR3 == RESET){
							Channel.ch1.send_actual++;
						}
						Channel.ch1.send_actual_irqstate = 0;
						Channel.ch1.send_actual_irqtime = 0;
					}
		}
}
//=============================================================================
//��������:Device2_Send_Actual_IRQTimer
//���ܸ�Ҫ:ͨ��2ʵ�ʷ�ҩ���������������ʱ���
//��������:��
//��������:��
//ע��    :��
//=============================================================================
static void 	Device2_Send_Actual_IRQTimer(void)
{
		if((Channel.ch2.send_actual_irqstate == 1)){//��ʱ����ʹ�ö�ʱ����ʱ���жϽ�����״̬��8MS���ж�״̬�Ƿ�����
					Channel.ch2.send_actual_irqtime++;
					if(IRQ_TIMEOUT <= Channel.ch2.send_actual_irqtime){
						if(READ_DEVICE2_SENSOR3 == RESET){
							Channel.ch2.send_actual++;
						}
						Channel.ch2.send_actual_irqstate = 0;
						Channel.ch2.send_actual_irqtime = 0;
					}
		}
}
//=============================================================================
//��������:Device3_Send_Actual_IRQTimer
//���ܸ�Ҫ:ͨ��3ʵ�ʷ�ҩ���������������ʱ���
//��������:��
//��������:��
//ע��    :��
//=============================================================================
static void 	Device3_Send_Actual_IRQTimer(void)
{
		if((Channel.ch3.send_actual_irqstate == 1)){//��ʱ����ʹ�ö�ʱ����ʱ���жϽ�����״̬��8MS���ж�״̬�Ƿ�����
					Channel.ch3.send_actual_irqtime++;
					if(IRQ_TIMEOUT <= Channel.ch3.send_actual_irqtime){
						if(READ_DEVICE3_SENSOR3 == RESET){
							Channel.ch3.send_actual++;
						}
						Channel.ch3.send_actual_irqstate = 0;
						Channel.ch3.send_actual_irqtime = 0;
					}
		}
}
//=============================================================================
//��������:Device4_Send_Actual_IRQTimer
//���ܸ�Ҫ:ͨ��4ʵ�ʷ�ҩ���������������ʱ���
//��������:��
//��������:��
//ע��    :��
//=============================================================================
static void 	Device4_Send_Actual_IRQTimer(void)
{
		if((Channel.ch4.send_actual_irqstate == 1)){//��ʱ����ʹ�ö�ʱ����ʱ���жϽ�����״̬��8MS���ж�״̬�Ƿ�����
					Channel.ch4.send_actual_irqtime++;
					if(IRQ_TIMEOUT <= Channel.ch4.send_actual_irqtime){
						if(READ_DEVICE4_SENSOR3 == RESET){
							Channel.ch4.send_actual++;
						}
						Channel.ch4.send_actual_irqstate = 0;
						Channel.ch4.send_actual_irqtime = 0;
					}
		}
}
//=============================================================================
//��������:EXTIX_Init
//���ܸ�Ҫ:�����ⲿ�жϳ�ʼ��
//��������:��
//��������:��
//ע��    :��
//=============================================================================
void EXTIX_Init(void)
{
		EXTIX0_Init( );
		EXTIX3_Init( );
		EXTIX4_Init( );
		EXTIX9_5_Init( );
		EXTIX15_10_Init( );
  	
}
//=============================================================================
//��������:EXTI0_IRQHandler
//���ܸ�Ҫ:�ⲿ�ж�0������� 
//��������:��
//��������:��
//ע��    :��
//=============================================================================
void EXTI0_IRQHandler(void)
{		
		if(EXTI_GetITStatus(EXTI_Line0) != RESET){
			delay_ms(3);
			if(READ_DEVICE1_SENSOR1 == READLOW){
				DEVICE1_MOTOR_STOP;	//�ӻ�ģʽֻҪת��ԭ���ֹͣ
				Channel.ch1.motor_state	= 0;
			}
		}
		EXTI_ClearITPendingBit(EXTI_Line0); //���LINE0�ϵ��жϱ�־λ  
		
}

//=============================================================================
//��������:EXTI3_IRQHandler
//���ܸ�Ҫ:�ⲿ�ж�3������� 
//��������:��
//��������:��
//ע��    :��
//=============================================================================
void EXTI3_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line3) != RESET){
			delay_ms(3);
			if(READ_DEVICE4_SENSOR1 == READLOW){
				DEVICE4_MOTOR_STOP;	//�ӻ�ģʽֻҪת��ԭ���ֹͣ
				Channel.ch4.motor_state	= 0;
			}
		}
		EXTI_ClearITPendingBit(EXTI_Line3); //���LINE0�ϵ��жϱ�־λ  
	 
}
//=============================================================================
//��������:EXTI4_IRQHandler
//���ܸ�Ҫ:�ⲿ�ж�4������� 
//��������:��
//��������:��
//ע��    :��
//=============================================================================
void EXTI4_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line4) != RESET){
			if((Channel.ch4.send_actual_irqstate == 0)){//��ʱ����ʹ�ö�ʱ����ʱ���жϽ�����״̬��8MS���ж�״̬�Ƿ�����					
					Channel.ch4.send_actual_irqstate = 1;
					Channel.ch4.send_actual_irqtime = 0;					
			}
		EXTI_ClearITPendingBit(EXTI_Line4); //���LINE0�ϵ��жϱ�־λ  
	}  
}
//=============================================================================
//��������:EXTI9_5_IRQHandler
//���ܸ�Ҫ:�ⲿ�ж�9-5������� 
//��������:��
//��������:��
//ע��    :��
//=============================================================================
void EXTI9_5_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line6) != RESET){
			delay_ms(3);
			if(READ_DEVICE3_SENSOR1 == READLOW){		
				DEVICE3_MOTOR_STOP;	//�ӻ�ģʽֻҪת��ԭ���ֹͣ
				Channel.ch3.motor_state	= 0;	
			}				
			EXTI_ClearITPendingBit(EXTI_Line6);
	}else if(EXTI_GetITStatus(EXTI_Line8) != RESET){
			if((Channel.ch3.send_actual_irqstate == 0)){//��ʱ����ʹ�ö�ʱ����ʱ���жϽ�����״̬��8MS���ж�״̬�Ƿ�����					
					Channel.ch3.send_actual_irqstate = 1;
					Channel.ch3.send_actual_irqtime = 0;					
			}
		EXTI_ClearITPendingBit(EXTI_Line8);
	}else{
		EXTI_ClearITPendingBit(EXTI_Line5);
		EXTI_ClearITPendingBit(EXTI_Line7);
		EXTI_ClearITPendingBit(EXTI_Line9);
	}

}
//=============================================================================
//��������:EXTI15_10_IRQHandler
//���ܸ�Ҫ:�ⲿ�ж�15-10������� 
//��������:��
//��������:��
//ע��    :��
//=============================================================================
void EXTI15_10_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line10) != RESET){
			if((Channel.ch1.send_actual_irqstate == 0)){//��ʱ����ʹ�ö�ʱ����ʱ���жϽ�����״̬��8MS���ж�״̬�Ƿ�����					
					Channel.ch1.send_actual_irqstate = 1;
					Channel.ch1.send_actual_irqtime = 0;					
			}
		EXTI_ClearITPendingBit(EXTI_Line10);
	}else if(EXTI_GetITStatus(EXTI_Line12) != RESET){
			delay_ms(3);
			if(READ_DEVICE2_SENSOR1 == READLOW){
				DEVICE2_MOTOR_STOP;	//�ӻ�ģʽֻҪת��ԭ���ֹͣ
				Channel.ch2.motor_state	= 0;
			}
			  EXTI_ClearITPendingBit(EXTI_Line12);
	}else if(EXTI_GetITStatus(EXTI_Line14) != RESET){
			if((Channel.ch2.send_actual_irqstate == 0)){//��ʱ����ʹ�ö�ʱ����ʱ���жϽ�����״̬��8MS���ж�״̬�Ƿ�����					
					Channel.ch2.send_actual_irqstate = 1;	
					Channel.ch2.send_actual_irqtime = 0;
			}	
		EXTI_ClearITPendingBit(EXTI_Line14);
	}else{
		EXTI_ClearITPendingBit(EXTI_Line11);
		EXTI_ClearITPendingBit(EXTI_Line13);
		EXTI_ClearITPendingBit(EXTI_Line15);
	}
}
//=============================================================================
//��������:Motor_pulse_IRQTimer
//���ܸ�Ҫ:���ԭ�������ж���ʱ��⺯�� 
//��������:��
//��������:��
//ע��    :������2ms��ʱ���жϷ������е���
//=============================================================================
void 	Motor_pulse_IRQTimer(void)
{
	Motor1_pulse_IRQTimer();
	Motor2_pulse_IRQTimer();
	Motor3_pulse_IRQTimer();
	Motor4_pulse_IRQTimer();
}
//=============================================================================
//��������:Device_Send_Actual_IRQTimer
//���ܸ�Ҫ:����ͨ��ʵ�ʷ�ҩ���������������ʱ���
//��������:��
//��������:��
//ע��    :������5ms��ʱ���жϷ������е���
//=============================================================================
void 	Device_Send_Actual_IRQTimer(void)
{
	Device1_Send_Actual_IRQTimer();
	Device2_Send_Actual_IRQTimer();
	Device3_Send_Actual_IRQTimer();
	Device4_Send_Actual_IRQTimer();
}






