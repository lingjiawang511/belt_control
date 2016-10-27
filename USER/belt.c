#include "HeadType.h"	

//static u8 belt.speed_step;
//static u8 belt11.start_ok;
//static u8 belt21.speed_step;
//static u8 belt21.start_ok;
Belt_Work_Type belt11;
Belt_Work_Type belt12;
u8 Send_Medicine_Finish_State;		//����ͨ����ҩ���״̬�����ⷢҩû��ɣ�Ƥ����ֹͣ��
//=============================================================================
//��������:Belt11_Config
//���ܸ�Ҫ:Ƥ��11 IO����
//��������:��
//��������:��
//ע��    :��
//=============================================================================
 void Belt11_Config(void)
{
		//����һ��GPIO_InitTypeDef ���͵Ľṹ�壬���ֽ�GPIO_InitStructure 
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
	//Ƥ���ٶȿ���IO��1
	GPIO_InitStructure.GPIO_Pin = BELT11_SPEED1_IO;			 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(BELT11_SPEED1_PORT, &GPIO_InitStructure);
	//Ƥ���ٶȿ���IO��2
	GPIO_InitStructure.GPIO_Pin = BELT11_SPEED2_IO;			 
	GPIO_Init(BELT11_SPEED2_PORT, &GPIO_InitStructure);
	//Ƥ���ٶȿ���IO��3
	GPIO_InitStructure.GPIO_Pin = BELT11_SPEED3_IO;			 
	GPIO_Init(BELT11_SPEED3_PORT, &GPIO_InitStructure);
	//Ƥ���������IO��
	GPIO_InitStructure.GPIO_Pin = BELT11_DIR_IO;			 
	GPIO_Init(BELT11_DIR_PORT, &GPIO_InitStructure);
	//Ƥ������������IO��
	GPIO_InitStructure.GPIO_Pin = BELT11_ERR_IO;			 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(BELT11_ERR_PORT, &GPIO_InitStructure);
	//Ƥ��������11 IO��
	GPIO_InitStructure.GPIO_Pin = BELT11_SENSOR1_IO;
	GPIO_Init(BELT11_SENSOR1_PORT, &GPIO_InitStructure);
	//Ƥ��������12 IO��
	GPIO_InitStructure.GPIO_Pin = BELT11_SENSOR2_IO;
	GPIO_Init(BELT11_SENSOR2_PORT, &GPIO_InitStructure);
	
	belt11.speed_step = 0;
	belt11.start_ok = 0;
	BELT11_SPEED1 = 0;
	BELT11_SPEED2 = 0;
	BELT11_SPEED3 = 0;
	BELT11_DIR = 0;
}

//=============================================================================
//��������:Belt21_Config
//���ܸ�Ҫ:Ƥ��2IO����
//��������:��
//��������:��
//ע��    :��
//=============================================================================
 void Belt12_Config(void)
{
		//����һ��GPIO_InitTypeDef ���͵Ľṹ�壬���ֽ�GPIO_InitStructure 
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
	//Ƥ���ٶȿ���IO��1
	GPIO_InitStructure.GPIO_Pin = BELT12_SPEED1_IO;			 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(BELT12_SPEED1_PORT, &GPIO_InitStructure);
	//Ƥ���ٶȿ���IO��2
	GPIO_InitStructure.GPIO_Pin = BELT12_SPEED2_IO;			 
	GPIO_Init(BELT12_SPEED2_PORT, &GPIO_InitStructure);
	//Ƥ���ٶȿ���IO��3
	GPIO_InitStructure.GPIO_Pin = BELT12_SPEED3_IO;			 
	GPIO_Init(BELT12_SPEED3_PORT, &GPIO_InitStructure);
	//Ƥ���������IO��
	GPIO_InitStructure.GPIO_Pin = BELT12_DIR_IO;			 
	GPIO_Init(BELT12_DIR_PORT, &GPIO_InitStructure);
	//Ƥ������������IO��
	GPIO_InitStructure.GPIO_Pin = BELT12_ERR_IO;			 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(BELT12_ERR_PORT, &GPIO_InitStructure);
	//Ƥ��������11 IO��
	GPIO_InitStructure.GPIO_Pin = BELT12_SENSOR1_IO;
	GPIO_Init(BELT12_SENSOR1_PORT, &GPIO_InitStructure);
	//Ƥ��������12 IO��
	GPIO_InitStructure.GPIO_Pin = BELT12_SENSOR2_IO;
	GPIO_Init(BELT12_SENSOR2_PORT, &GPIO_InitStructure);
	
	belt12.speed_step = 0;
	belt12.start_ok = 0;
	BELT12_SPEED1 = 0;
	BELT12_SPEED2 = 0;
	BELT12_SPEED3 = 0;
	BELT12_DIR = 0;
}

//=============================================================================
//��������:BELT_Speed_Control
//���ܸ�Ҫ:Ƥ���ٶȿ��ƺ���
//��������:speed��Ƥ�������ٶ�
//��������:��
//ע��    :��
//=============================================================================
static void Belt11_Speed_Control(u8 speed)
{
	if(speed == 0){
		Belt11_Speed(0,0,0);	
	}else if(speed == 1){
		Belt11_Speed(0,0,1);
	}else if(speed == 2){
		Belt11_Speed(0,1,0);
	}else if(speed == 3){
		Belt11_Speed(0,1,1);
	}else if(speed == 4){
		Belt11_Speed(1,0,0);
	}else if(speed == 5){
		Belt11_Speed(1,0,1);
	}else if(speed == 6){
		Belt11_Speed(1,1,0);
	}else if(speed == 7){
		Belt11_Speed(1,1,1);
	}
}

//=============================================================================
//��������:Start_Belt
//���ܸ�Ҫ:Ƥ���������������
//��������:step������ٶ�Ҳ�ǵ������״̬����
//��������:���ִ�е���һ�����ٶ�
//ע��    :��Ҫ�ڶ�ʱ���жϺ�������
//=============================================================================
static u8 Start_Belt11(u8 step)
{
	static u16 start_time = 0;
	switch(step){
	case 0x00:Belt11_Speed_Control(step);step++; break;
	case 0x01:Belt11_Speed_Control(step);start_time++;
						if(start_time >= START_TIMEOUT/4){step++;start_time = 0;} break;
	case 0x02:Belt11_Speed_Control(step);start_time++;
						if(start_time >= START_TIMEOUT/4){step++;start_time = 0;} break;						
	case 0x03:Belt11_Speed_Control(step);start_time++;
						if(start_time >= START_TIMEOUT/4){step++;start_time = 0;} break;
	case 0x04:Belt11_Speed_Control(step);start_time++;
						if(start_time >= START_TIMEOUT/4){step++;start_time = 0;} break;						
	case 0x05:Belt11_Speed_Control(step);start_time++;
						if(start_time >= START_TIMEOUT){step++;start_time = 0;} break;					
	case 0x06:Belt11_Speed_Control(step);start_time++;
						if(start_time >= START_TIMEOUT/4){step++;start_time = 0;} break;						
	case 0x07:Belt11_Speed_Control(step-1);start_time++;
						if(start_time >= START_TIMEOUT/4)
							{step++;start_time = 0;belt11.start_ok = 1;} break;						
	default:start_time = 0; break;
	}
	return step;
}
//=============================================================================
//��������:Stop_Belt11
//���ܸ�Ҫ:�����ֹͣ����
//��������:step������ٶ�Ҳ�ǵ������״̬����
//��������:���ִ�е���һ�����ٶ�
//ע��    :��Ҫ�ڶ�ʱ���жϺ�������
//=============================================================================
static u8 Stop_Belt11(u8 step)
{
	static u16 stop_time = 0;
	switch(step){
	case 0x01:Belt11_Speed_Control(step-1);step--;stop_time = 0;belt11.start_ok = 0;break;
	case 0x02:Belt11_Speed_Control(step-1);stop_time++;
						if(stop_time >= STOP_TIMEOUT/4){step--;stop_time = 0;} break;	
	case 0x03:Belt11_Speed_Control(step-1);stop_time++;
						if(stop_time >= STOP_TIMEOUT/4){step--;stop_time = 0;} break;	
	case 0x04:Belt11_Speed_Control(step-1);stop_time++;
						if(stop_time >= STOP_TIMEOUT/2){step--;stop_time = 0;} break;	
	case 0x05:Belt11_Speed_Control(step-1);stop_time++;
						if(stop_time >= STOP_TIMEOUT/2){step--;stop_time = 0;} break;	
	case 0x06:Belt11_Speed_Control(step-1);stop_time++;
						if(stop_time >= STOP_TIMEOUT/2){step--;stop_time = 0;} break;	
	case 0x07:Belt11_Speed_Control(step-1);stop_time++;
						if(stop_time >= STOP_TIMEOUT/2){step--;stop_time = 0;} break;	
	case 0x08:Belt11_Speed_Control(step-2);stop_time++;
						if(stop_time >= STOP_TIMEOUT/2){step--;stop_time = 0;} break;	
	default:Belt11_Speed_Control(0);stop_time = 0; break;
	}
		return step;
}

//=============================================================================
//��������:BELT_Speed_Control
//���ܸ�Ҫ:Ƥ���ٶȿ��ƺ���
//��������:speed��Ƥ�������ٶ�
//��������:��
//ע��    :��
//=============================================================================
static void Belt12_Speed_Control(u8 speed)
{
	if(speed == 0){
		Belt12_Speed(0,0,0);	
	}else if(speed == 1){
		Belt12_Speed(0,0,1);
	}else if(speed == 2){
		Belt12_Speed(0,1,0);
	}else if(speed == 3){
		Belt12_Speed(0,1,1);
	}else if(speed == 4){
		Belt12_Speed(1,0,0);
	}else if(speed == 5){
		Belt12_Speed(1,0,1);
	}else if(speed == 6){
		Belt12_Speed(1,1,0);
	}else if(speed == 7){
		Belt12_Speed(1,1,1);
	}
}

//=============================================================================
//��������:Start_Belt
//���ܸ�Ҫ:Ƥ���������������
//��������:step������ٶ�Ҳ�ǵ������״̬����
//��������:���ִ�е���һ�����ٶ�
//ע��    :��Ҫ�ڶ�ʱ���жϺ�������
//=============================================================================
static u8 Start_Belt12(u8 step)
{
	static u16 start_time = 0;
	switch(step){
	case 0x00:Belt12_Speed_Control(step);step++; break;
	case 0x01:Belt12_Speed_Control(step);start_time++;
						if(start_time >= START_TIMEOUT/4){step++;start_time = 0;} break;
	case 0x02:Belt12_Speed_Control(step);start_time++;
						if(start_time >= START_TIMEOUT/4){step++;start_time = 0;} break;						
	case 0x03:Belt12_Speed_Control(step);start_time++;
						if(start_time >= START_TIMEOUT/4){step++;start_time = 0;} break;
	case 0x04:Belt12_Speed_Control(step);start_time++;
						if(start_time >= START_TIMEOUT/4){step++;start_time = 0;} break;						
	case 0x05:Belt12_Speed_Control(step);start_time++;
						if(start_time >= START_TIMEOUT){step++;start_time = 0;} break;					
	case 0x06:Belt12_Speed_Control(step);start_time++;
						if(start_time >= START_TIMEOUT/4){step++;start_time = 0;} break;						
	case 0x07:Belt12_Speed_Control(step-1);start_time++;
						if(start_time >= START_TIMEOUT/4)
							{step++;start_time = 0;belt12.start_ok = 1;} break;						
	default:start_time = 0; break;
	}
	return step;
}
//=============================================================================
//��������:Stop_Belt11
//���ܸ�Ҫ:�����ֹͣ����
//��������:step������ٶ�Ҳ�ǵ������״̬����
//��������:���ִ�е���һ�����ٶ�
//ע��    :��Ҫ�ڶ�ʱ���жϺ�������
//=============================================================================
static u8 Stop_Belt21(u8 step)
{
	static u16 stop_time = 0;
	switch(step){
	case 0x01:Belt12_Speed_Control(step-1);step--;stop_time = 0;belt12.start_ok = 0;break;
	case 0x02:Belt12_Speed_Control(step-1);stop_time++;
						if(stop_time >= STOP_TIMEOUT/4){step--;stop_time = 0;} break;	
	case 0x03:Belt12_Speed_Control(step-1);stop_time++;
						if(stop_time >= STOP_TIMEOUT/4){step--;stop_time = 0;} break;	
	case 0x04:Belt12_Speed_Control(step-1);stop_time++;
						if(stop_time >= STOP_TIMEOUT/2){step--;stop_time = 0;} break;	
	case 0x05:Belt12_Speed_Control(step-1);stop_time++;
						if(stop_time >= STOP_TIMEOUT/2){step--;stop_time = 0;} break;	
	case 0x06:Belt12_Speed_Control(step-1);stop_time++;
						if(stop_time >= STOP_TIMEOUT/2){step--;stop_time = 0;} break;	
	case 0x07:Belt12_Speed_Control(step-1);stop_time++;
						if(stop_time >= STOP_TIMEOUT/2){step--;stop_time = 0;} break;	
	case 0x08:Belt12_Speed_Control(step-2);stop_time++;
						if(stop_time >= STOP_TIMEOUT/2){step--;stop_time = 0;} break;	
	default:Belt12_Speed_Control(0);stop_time = 0; break;
	}
		return step;
}
//=============================================================================
//��������:Belt_Control
//���ܸ�Ҫ:Ƥ������
//��������:��
//��������:��
//ע��    :��
//=============================================================================
void Belt11_Control(void)
{
			if((READ_BELT11_SENSOR1 == 0)||(READ_BELT11_SENSOR2 == 0)){
			delay_ms(10);	
			if((READ_BELT11_SENSOR1 == 0)||(READ_BELT11_SENSOR2 == 0)){
				if(belt11.start_signal == 0){
					belt11.start_signal = 1;	
					belt11.stop_signal  = 0;
					belt11.start_ok = 0;
					belt11.stop_ok = 0;
					belt11.stop_delay_state = 0;
					if(belt11.speed_step>0){
						belt11.speed_step--; 
					}
				}
			}
		}else{
			if(belt11.start_ok == 1){
				belt11.stop_delay_state = 1;
				belt11.start_ok = 0;
				belt11.start_signal = 0;
			}
			if(belt11.stop_ok == 1){
				belt11.stop_signal = 1;
				belt11.start_signal = 0;
				belt11.stop_ok = 0;
			}
		}
}

//=============================================================================
//��������:Belt_Control
//���ܸ�Ҫ:Ƥ������
//��������:��
//��������:��
//ע��    :�� 
//=============================================================================
void Belt12_Control(void)
{
			if((READ_BELT12_SENSOR1 == 0)||(READ_BELT12_SENSOR2 == 0)){
			delay_ms(10);	
			if((READ_BELT12_SENSOR1 == 0)||(READ_BELT12_SENSOR2 == 0)){
				if(belt12.start_signal == 0){
					belt12.start_signal = 1;	
					belt12.stop_signal  = 0;
					belt12.start_ok = 0;
					belt12.stop_ok = 0;
					belt12.stop_delay_state = 0;
					if(belt12.speed_step>0){
						belt12.speed_step--; 
					}
				}
			}
		}else{
			if(belt12.start_ok == 1){
				belt12.stop_delay_state = 1;
				belt12.start_ok = 0;
				belt12.start_signal = 0;
			}
			if(belt12.stop_ok == 1){
				belt12.stop_signal = 1;
				belt12.start_signal = 0;
				belt12.stop_ok = 0;
			}
		}
}
//=============================================================================
//��������:belt11_time_control
//���ܸ�Ҫ:
//��������:��
//��������:��
//ע��    :��5MS��ʱ���ڵ���
//=============================================================================
void belt11_time_control(void) 
{
	static u16 stop_delay_time;

	if(belt11.start_signal ==1){
		belt11.speed_step = Start_Belt11(belt11.speed_step);
	}
	if(belt11.stop_signal == 1){
		belt11.speed_step = Stop_Belt11(belt11.speed_step);
	}
	if(belt11.stop_delay_state == 1){
		stop_delay_time++;
		if(stop_delay_time >= belt11.actual_time){
			belt11.stop_ok = 1;
			belt11.stop_delay_state = 0;
			stop_delay_time = 0;
		}
	}
}
//=============================================================================
//��������:belt21_time_control
//���ܸ�Ҫ:
//��������:��
//��������:��
//ע��    :��5MS��ʱ���ڵ���
//=============================================================================
void belt12_time_control(void) 
{
	static u16 stop_delay_time;

	if(belt12.start_signal ==1){
		belt12.speed_step = Start_Belt12(belt12.speed_step);
	}
	if(belt12.stop_signal == 1){
		belt12.speed_step = Stop_Belt21(belt12.speed_step);
	}
	if(belt12.stop_delay_state == 1){
		stop_delay_time++;
		if(stop_delay_time >= belt12.actual_time){
			belt12.stop_ok = 1;
			belt12.stop_delay_state = 0;
			stop_delay_time = 0;
		}
	}
}









