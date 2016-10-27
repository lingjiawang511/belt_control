#include"HeadType.h"	

//=============================================================================
//��������:Send_Medicine1_Config
//���ܸ�Ҫ:��ҩ��1�����������
//��������:��
//��������:��
//ע��    :��
//=============================================================================
static void Send_Medicine1_Config(void)
{
		//����һ��GPIO_InitTypeDef ���͵Ľṹ�壬���ֽ�GPIO_InitStructure 
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	//�������IO��
	GPIO_InitStructure.GPIO_Pin = DEVICE1_MOTOR_IO;			 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEVICE1_MOTOR_PORT, &GPIO_InitStructure);
	//�ƿ���IO��
	GPIO_InitStructure.GPIO_Pin = DEVICE1_LIGHT_IO;			 
	GPIO_Init(DEVICE1_LIGHT_PORT, &GPIO_InitStructure);
	//������1����IO��
// 	GPIO_InitStructure.GPIO_Pin = DEVICE1_SENSOR1_IO;			 
// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
// 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
// 	GPIO_Init(DEVICE1_SENSOR1_PORT, &GPIO_InitStructure);
	//������2����IO��
	GPIO_InitStructure.GPIO_Pin = DEVICE1_SENSOR2_IO;			 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEVICE1_SENSOR2_PORT, &GPIO_InitStructure);
	//������3����IO��
// 	GPIO_InitStructure.GPIO_Pin = DEVICE1_SENSOR3_IO;			 
// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
// 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
// 	GPIO_Init(DEVICE1_SENSOR3_PORT, &GPIO_InitStructure);
	//��������IO��
	GPIO_InitStructure.GPIO_Pin = DEVICE1_KEY_IO;			 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEVICE1_KEY_PORT, &GPIO_InitStructure);
	
}
//=============================================================================
//��������:Send_Medicine2_Config
//���ܸ�Ҫ:��ҩ��2�����������
//��������:��
//��������:��
//ע��    :��
//=============================================================================
static void Send_Medicine2_Config(void )
{
		//����һ��GPIO_InitTypeDef ���͵Ľṹ�壬���ֽ�GPIO_InitStructure 
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	//�������IO��
	GPIO_InitStructure.GPIO_Pin = DEVICE2_MOTOR_IO;			 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEVICE2_MOTOR_PORT, &GPIO_InitStructure);
	//�ƿ���IO��
	GPIO_InitStructure.GPIO_Pin = DEVICE2_LIGHT_IO;			 
	GPIO_Init(DEVICE2_LIGHT_PORT, &GPIO_InitStructure);
	//������1����IO��
// 	GPIO_InitStructure.GPIO_Pin = DEVICE2_SENSOR1_IO;			 
// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
// 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
// 	GPIO_Init(DEVICE2_SENSOR1_PORT, &GPIO_InitStructure);
	//������2����IO��
	GPIO_InitStructure.GPIO_Pin = DEVICE2_SENSOR2_IO;			 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEVICE2_SENSOR2_PORT, &GPIO_InitStructure);
	//������3����IO��
// 	GPIO_InitStructure.GPIO_Pin = DEVICE2_SENSOR3_IO;			 
// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
// 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
// 	GPIO_Init(DEVICE2_SENSOR3_PORT, &GPIO_InitStructure);
	//��������IO��
	GPIO_InitStructure.GPIO_Pin = DEVICE2_KEY_IO;			 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEVICE2_KEY_PORT, &GPIO_InitStructure);
}

//=============================================================================
//��������:Send_Medicine3_Config
//���ܸ�Ҫ:��ҩ��3�����������
//��������:��
//��������:��
//ע��    :��
//=============================================================================
static void Send_Medicine3_Config(void)
{
		//����һ��GPIO_InitTypeDef ���͵Ľṹ�壬���ֽ�GPIO_InitStructure 
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	//�������IO��
	GPIO_InitStructure.GPIO_Pin = DEVICE3_MOTOR_IO;			 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEVICE3_MOTOR_PORT, &GPIO_InitStructure);
	//�ƿ���IO��
	GPIO_InitStructure.GPIO_Pin = DEVICE3_LIGHT_IO;			 
	GPIO_Init(DEVICE3_LIGHT_PORT, &GPIO_InitStructure);
	//������1����IO��
// 	GPIO_InitStructure.GPIO_Pin = DEVICE3_SENSOR1_IO;			 
// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
// 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
// 	GPIO_Init(DEVICE3_SENSOR1_PORT, &GPIO_InitStructure);
	//������2����IO��
	GPIO_InitStructure.GPIO_Pin = DEVICE3_SENSOR2_IO;			 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEVICE3_SENSOR2_PORT, &GPIO_InitStructure);
	//������3����IO��
// 	GPIO_InitStructure.GPIO_Pin = DEVICE3_SENSOR3_IO;			 
// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
// 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
// 	GPIO_Init(DEVICE3_SENSOR3_PORT, &GPIO_InitStructure);
	//��������IO��
	GPIO_InitStructure.GPIO_Pin = DEVICE3_KEY_IO;			 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEVICE3_KEY_PORT, &GPIO_InitStructure);
}
//=============================================================================
//��������:Send_Medicine4_Config
//���ܸ�Ҫ:��ҩ��4�����������
//��������:��
//��������:��
//ע��    :��
//=============================================================================
static void Send_Medicine4_Config(void)
{
		//����һ��GPIO_InitTypeDef ���͵Ľṹ�壬���ֽ�GPIO_InitStructure 
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	//�������IO��
	GPIO_InitStructure.GPIO_Pin = DEVICE4_MOTOR_IO;			 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEVICE4_MOTOR_PORT, &GPIO_InitStructure);
	//�ƿ���IO��
	GPIO_InitStructure.GPIO_Pin = DEVICE4_LIGHT_IO;			 
	GPIO_Init(DEVICE4_LIGHT_PORT, &GPIO_InitStructure);
	//������1����IO��
// 	GPIO_InitStructure.GPIO_Pin = DEVICE4_SENSOR1_IO;			 
// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
// 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
// 	GPIO_Init(DEVICE4_SENSOR1_PORT, &GPIO_InitStructure);
	//������2����IO��
	GPIO_InitStructure.GPIO_Pin = DEVICE4_SENSOR2_IO;			 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEVICE4_SENSOR2_PORT, &GPIO_InitStructure);
	//������3����IO��
// 	GPIO_InitStructure.GPIO_Pin = DEVICE4_SENSOR3_IO;			 
// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
// 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
// 	GPIO_Init(DEVICE4_SENSOR3_PORT, &GPIO_InitStructure);
	//��������IO��
	GPIO_InitStructure.GPIO_Pin = DEVICE4_KEY_IO;			 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEVICE4_KEY_PORT, &GPIO_InitStructure);
}
//=============================================================================
//��������:CH_Param_Init
//���ܸ�Ҫ:ÿ��ͨ����ز����ĳ�ʼ��
//��������:��
//��������:��
//ע��    :��
//=============================================================================
static void CH_Param_Init(void)
{
	Channel.ch1.state = RESERVE;
	Channel.ch2.state = RESERVE;
	Channel.ch3.state = RESERVE;
	Channel.ch4.state = RESERVE;
}
//=============================================================================
//��������:Param_Init
//���ܸ�Ҫ:��ʼ�������Ͳ���
//��������:��
//��������:��
//ע��    :��
//=============================================================================
static void Param_Init(void)
{
	MCU_State = SLAVE;
	PC_Answer.Nanswer_timeout = NANSWER_TIME;
	PC_Answer.answer_numout = NANSWER_NUMOUT;
	PC_Answer.answer_state =0;	
	Usart1_Control_Data.rx_aframe = 0;
	Channel.ch1.motor_state = 0;
	Channel.ch2.motor_state = 0;
	Channel.ch3.motor_state = 0;
	Channel.ch4.motor_state = 0;
	Channel.ch1.timeoutstart = 0;
	Channel.ch2.timeoutstart = 0;
	Channel.ch3.timeoutstart = 0;
	Channel.ch4.timeoutstart = 0;
	Channel.ch1.timeout = 0;
	Channel.ch2.timeout = 0;
	Channel.ch3.timeout = 0;
	Channel.ch4.timeout = 0;
	CH_Param_Init();
}

//=============================================================================
//��������:Send_Medicine_Config
//���ܸ�Ҫ:��ʼ������ͨ��
//��������:��
//��������:��
//ע��    :��
//=============================================================================
void Roll_Pater_Config(void)
{
	Send_Medicine1_Config();
	Send_Medicine2_Config();
	Send_Medicine3_Config();
	Send_Medicine4_Config();
	Param_Init();
}
//=============================================================================
//��������:Roll_Pater_Motor_Run
//���ܸ�Ҫ:����ͨ���ĵ���ж�����
//��������:��
//��������:��
//ע��    :��
//=============================================================================
void Roll_Pater_Motor_Run(void)
{
	if(Channel.ch1.motor_start_state == 1){
		if(Channel.ch1.send_actual >= 1){
				DEVICE1_MOTOR_RUN;
				Channel.ch1.motor_state = 1;
				Channel.ch1.send_actual = 0;
		}
	}else{
			  Channel.ch1.send_actual = 0;
	}
	if(Channel.ch2.motor_start_state == 1){
		if(Channel.ch2.send_actual >= 1){
				DEVICE2_MOTOR_RUN;
				Channel.ch2.motor_state = 1;
				Channel.ch2.send_actual = 0;
		}
	}else{
				Channel.ch2.send_actual = 0;
	}
	if(Channel.ch3.motor_start_state == 1){
		if(Channel.ch3.send_actual >= 1){
				DEVICE3_MOTOR_RUN;
				Channel.ch3.motor_state = 1;
				Channel.ch3.send_actual = 0;
		}
	}else{
			 Channel.ch3.send_actual = 0;
	}
	if(Channel.ch4.motor_start_state == 1){
		if(Channel.ch4.send_actual >= 1){
				DEVICE4_MOTOR_RUN;
				Channel.ch4.motor_state = 1;
				Channel.ch4.send_actual = 0;
		}
	}else{
				Channel.ch4.send_actual = 0;
	}
	/********��ѯ��ʽ�������*********/
	if((READ_DEVICE1_SENSOR2 == READLOW)||(READ_DEVICE2_SENSOR2 == READLOW)\
			||(READ_DEVICE3_SENSOR2 == READLOW)||(READ_DEVICE4_SENSOR2 == READLOW)){	//���������ź�ʱΪ�͵�ƽ
			delay_ms(5);
			if((READ_DEVICE1_SENSOR2 == READLOW)||(READ_DEVICE2_SENSOR2 == READLOW)\
				||(READ_DEVICE3_SENSOR2 == READLOW)||(READ_DEVICE4_SENSOR2 == READLOW)){	//���������ź�ʱΪ�͵�ƽ
			  if(Channel.ch1.motor_start_state == 1){
					if(READ_DEVICE1_SENSOR2 == READLOW){
							DEVICE1_MOTOR_RUN;
							Channel.ch1.motor_state = 1;
					}
				}
				if(Channel.ch2.motor_start_state == 1){
					if(READ_DEVICE2_SENSOR2 == READLOW){
							DEVICE2_MOTOR_RUN;
							Channel.ch2.motor_state = 1;
					}
				}
				if(Channel.ch3.motor_start_state == 1){
					if(READ_DEVICE3_SENSOR2 == READLOW){
							DEVICE3_MOTOR_RUN;
							Channel.ch3.motor_state = 1;
					}
				}
				if(Channel.ch4.motor_start_state == 1){
					if(READ_DEVICE4_SENSOR2 == READLOW){
							DEVICE4_MOTOR_RUN;
							Channel.ch4.motor_state = 1;
					}
				}
		}
	}
}
//=============================================================================
//��������:CH_Key_Control
//���ܸ�Ҫ:����ͨ���İ������
//��������:��
//��������:��
//ע��    :��
//=============================================================================
void CH_Key_Control(void)
{

		if(Key_ScanNum != 0x00){
				 if(0x01== (Key_ScanNum&0x01)){
					 if(Channel.ch1.motor_start_state == 0){
							Channel.ch1.motor_start_state = 1;
					 }else{
						  DEVICE1_MOTOR_STOP;				
							Channel.ch1.motor_start_state = 0;
							Channel.ch1.send_actual = 0;
					}
					Key_ScanNum	&=0xfe;
				}
				 if(0x02== (Key_ScanNum&0x02)){
					 if(Channel.ch2.motor_start_state == 0){
							Channel.ch2.motor_start_state = 1;
					 }else{
						  DEVICE2_MOTOR_STOP;
							Channel.ch2.motor_start_state = 0;
						  Channel.ch2.send_actual = 0;
					}	
					Key_ScanNum	&=0xfd;					
				}
				 if(0x04== (Key_ScanNum&0x04)){
					 if(Channel.ch3.motor_start_state == 0){
							Channel.ch3.motor_start_state = 1;
					 }else{
						  DEVICE3_MOTOR_STOP;
							Channel.ch3.motor_start_state = 0;
						  Channel.ch3.send_actual = 0;
					}	
					Key_ScanNum	&=0xfb;					
				}
					if(0x08== (Key_ScanNum&0x08)){
					 if(Channel.ch4.motor_start_state == 0){
							Channel.ch4.motor_start_state = 1;
					 }else{
						  DEVICE4_MOTOR_STOP;
							Channel.ch4.motor_start_state = 0;
						  Channel.ch4.send_actual = 0;
					}	
					Key_ScanNum	&=0xf7;					
				}
				Key_ScanNum	&=0x0f;	
			}

}
//=============================================================================
//��������:CH_Light_Control
//���ܸ�Ҫ:����ͨ���ƵĿ���
//��������:��
//��������:��
//ע��    :��
//=============================================================================
void CH_Light_Control(void )
{
	if(Channel.ch1.motor_start_state == 1 ){
			DEVICE1_LIGHT_ON;
	}else{
			DEVICE1_LIGHT_OFF;
	}
	if(Channel.ch2.motor_start_state == 1 ){
			DEVICE2_LIGHT_ON;
	}else{
			DEVICE2_LIGHT_OFF;
	}
	if(Channel.ch3.motor_start_state == 1 ){
			DEVICE3_LIGHT_ON;
	}else{
			DEVICE3_LIGHT_OFF;
	}
	if(Channel.ch4.motor_start_state == 1 ){
			DEVICE4_LIGHT_ON;
	}else{
			DEVICE4_LIGHT_OFF;
	}	
}




