#include"HeadType.h"


/*����1�ܽ���ӳ��*/
#define USART1REMAP 0
/*�Զ���֡��ʱ��ʱʱ��*/
#define AUTO_FRAME_TIMEOUT1  100  //10*2ms

/*�Զ���֡��ʱ��ʱʱ��*/

Usart_Type Usart1_Control_Data;
Answer_Type 	 PC_Answer;
char Auto_Frame_Time1;

COMM_Send_Union_Type PC_Host_Rec;	//PC����Ϊ����ʱ�Ľṹ����ձ���
// COMM_Rec_Union_Type  PC_Hosr_Send;//PC����Ϊ����ʱ�Ľṹ�巢��Ӧ�����

COMM_Send_Union_Type MCU_Host_Send;//MCU��Ϊ����ʱ�Ľṹ�巢�ͱ���
COMM_Rec_Union_Type  MCU_Host_Rec;//MCU��Ϊ����ʱ�Ľṹ�����Ӧ�����
MCU_State_Type MCU_State;					//MCU��Ϊ�������Ǵӻ�״̬

CH_Work Channel;									//�ĸ���ҩͨ�����Ʊ���
Belt_Work_Type belt;							//Ƥ�����Ʊ���

//=============================================================================
//��������:Init_USART1
//���ܸ�Ҫ:USART1 ��ʼ��������ز���
//����˵��:��
//��������:��
//=============================================================================
static void Init_USART1(void)
{
    Usart1_Control_Data.tx_index = 0;
    Usart1_Control_Data.rx_index = 0;
    Usart1_Control_Data.tx_count = 0;
    Usart1_Control_Data.rx_count = 0;
    Usart1_Control_Data.rx_start = 0;
    Usart1_Control_Data.rx_aframe = 0;
    
}
//=============================================================================
//��������:USART1_Interrupts_Config
//���ܸ�Ҫ:USART1 �ж����ȼ�����
//����˵��:��
//��������:��
//=============================================================================
static void USART1_Interrupts_Config(void)
{
     NVIC_InitTypeDef NVIC_InitStructure; 
    
     NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
    
     NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
     NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
     NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
     NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
     NVIC_Init(&NVIC_InitStructure);
}
//=============================================================================
//��������:USART2_Interrupts_Config
//���ܸ�Ҫ:USART2 �ж����ȼ�����
//����˵��:��
//��������:��
//=============================================================================
static void USART2_Interrupts_Config(void)
{
     NVIC_InitTypeDef NVIC_InitStructure; 
    
     NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
    
     NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
     NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
     NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
     NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
     NVIC_Init(&NVIC_InitStructure);
}
//=============================================================================
//��������:USART1_Config
//���ܸ�Ҫ:USART1 ��ʼ������,����ģʽ���á�57600 8-N-1
//����˵��:��
//��������:��
//=============================================================================
#if USART1REMAP  //���USART1ʹ����ӳ��

void USART1_Config(void )
{	
    GPIO_InitTypeDef GPIO_InitStructure;	
    USART_InitTypeDef USART_InitStructure;  //���崮�ڳ�ʼ���ṹ��
    
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB | RCC_APB2Periph_USART1,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
    GPIO_PinRemapConfig(GPIO_Remap_USART1,ENABLE);

  /*  USART1_TX -> PB6 */
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;	       //ѡ�д���Ĭ������ܽ�         
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�������������� 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//����ܽ�9��ģʽ  
  GPIO_Init(GPIOB, &GPIO_InitStructure);           //���ú������ѽṹ�����������г�ʼ��	
  
  /*  USART1_RX ->	PB7*/

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;	        
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  
  USART_InitStructure.USART_BaudRate = 19200; //������
  USART_InitStructure.USART_WordLength = USART_WordLength_8b; //����λ8λ
  USART_InitStructure.USART_StopBits = USART_StopBits_1;	//ֹͣλ1λ
  USART_InitStructure.USART_Parity = USART_Parity_No;		//У��λ ��
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��������
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;		//ʹ�ܽ��պͷ�������

  USART_Init(USART1, &USART_InitStructure); //�����ϸ���ֵ�Ľṹ�����⺯��USART_Init���г�ʼ��
  USART_ClearFlag(USART1,USART_FLAG_TC);
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
  USART_ITConfig(USART1, USART_IT_TC, ENABLE);
    /* Enable the EXTI Interrupt */
  USART_Cmd(USART1, ENABLE);//����USART1��ע��������RCC_APB2PeriphClockCmd()���õ�����
  USART1_Interrupts_Config();
  Init_USART1();
}
#else
void USART1_Config(void)
{
	//gpio��usart��ʼ���ṹ�嶨��
	//��gpio����ʱ����������ʱ������Ҫ��ʼ��ͬʱgpio��ppp���裬��������ʹ�ܺͿ���ʱ��
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	
	//����gpio������ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);

	//gpio��ʼ���ṹ���Ա��ֵ
	//��ʼ��PA��9�������������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	//ִ�������gpio��ʼ��
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	// PA.10��������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	//USART��ʼ��
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure);
	USART_ClearFlag(USART1,USART_FLAG_TC);
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	USART_ITConfig(USART1, USART_IT_TC, ENABLE);
	/* Enable the EXTI Interrupt */
	USART_Cmd(USART1, ENABLE);//����USART1��ע��������RCC_APB2PeriphClockCmd()���õ�����
	
	USART1_Interrupts_Config();
	Init_USART1();
}

#endif
 //=============================================================================
//��������:USART2_Config
//���ܸ�Ҫ:USART2 ��ʼ������,����ģʽ���á�57600 8-N-1
//����˵��:��
//��������:��
//=============================================================================
void USART2_Config(void)
{

	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	/* Enable the USART2 Pins Software Remapping */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE); 

	/* Configure USART2 Tx (PA.02) as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	/* Configure USART2 Rx (PA.03) as input floating */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;	  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
    
	/* Enable the USART2 Interrupt */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//ѡ���жϷ���
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);    

	USART_InitStructure.USART_BaudRate = 19200; 			 
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;	   
	USART_InitStructure.USART_Parity = USART_Parity_No; 	  
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;  

	USART_Init(USART2, &USART_InitStructure);
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	USART_ITConfig(USART2, USART_IT_TC, ENABLE);
	USART_ClearFlag(USART2,USART_FLAG_TC);
	/* Enable USART2 */
	USART_Cmd(USART2, ENABLE);
	USART2_Interrupts_Config();

}

//=============================================================================
//��������:fputc
//���ܸ�Ҫ:�ض���c�⺯��printf��USART
//����˵��:��
//��������:��
//ע��   :��printf����,��Ҫ��ѡUse Microlib
//=============================================================================

int fputc(int ch, FILE *f)
{
//��Printf���ݷ������� 
  USART_SendData(USART1, (unsigned char) ch);
  while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET); 
  return (ch);
}
//=============================================================================
//��������:USART1_Putc
//���ܸ�Ҫ:��USART1_Putc�������ݴ�ӡ������
//����˵��:��
//��������:��
//ע��   :��
//=============================================================================
void USART1_Putc(unsigned char c)
{
    USART_SendData(USART1, c);
    while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET );
}

//=============================================================================
//��������:USART1_Putc
//���ܸ�Ҫ:��USART1_Putc�������ݴ�ӡ������
//����˵��:��
//��������:��
//ע��    :��
//=============================================================================
void USART1_Puts(char * str)
{
    while(*str)
    {
        USART_SendData(USART1, *str++);
        while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
    }
}
//=============================================================================
//��������:USART1_Putc
//���ܸ�Ҫ:��USART1_Putc�������ݴ�ӡ������
//����˵��:��
//��������:��
//ע��   :��
//=============================================================================
void USART2_Putc(unsigned char c)
{
    USART_SendData(USART2, c);
    while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET );
}

//=============================================================================
//��������:USART1_Putc
//���ܸ�Ҫ:��USART1_Putc�������ݴ�ӡ������
//����˵��:��
//��������:��
//ע��    :��
//=============================================================================
void USART2_Puts(char * str)
{
    while(*str){
        USART_SendData(USART2, *str++);
        while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
    }
}

//=============================================================================
//��������:USART1_Do_Tx
//���ܸ�Ҫ:������һ�����ݷ��ͳ�ȥ��ͨ���жϷ���
//����˵��:��
//��������:��
//ע��    :��
//=============================================================================
void USART1_Do_Tx(void )
{
    if (Usart1_Control_Data.tx_index < Usart1_Control_Data.tx_count) {
		USART_SendData(USART1, Usart1_Control_Data.txbuf[Usart1_Control_Data.tx_index]);
		Usart1_Control_Data.tx_index++;
	}else{
       Usart1_Control_Data.tx_count = 0; 
       Usart1_Control_Data.tx_index = 0;
    }
}

//=============================================================================
//��������:USART1_Do_Rx
//���ܸ�Ҫ:������һ���յ�����
//����˵��:��
//��������:��
//ע��    :��
//=============================================================================
void USART1_Do_Rx(u8 rxdata)
{       
    if (0 == Usart1_Control_Data.rx_aframe){
       if (0 == Usart1_Control_Data.rx_index){  //���յ�һ֡�ĵ�һ�����ݿ�����ʱ��3��ʱ���Զ���֡����
           Usart1_Control_Data.rx_start = 1;
           Auto_Frame_Time1 = AUTO_FRAME_TIMEOUT1; 
       }else {
            if (Auto_Frame_Time1 <=0){   //ʱ�䳬ʱ�Զ���֡
               Usart1_Control_Data.rx_aframe = 1; 
               Usart1_Control_Data.rx_start = 0;
               Usart1_Control_Data.rx_count = Usart1_Control_Data.rx_index;
               Usart1_Control_Data.rx_index = 0;   //�õ�һ֡���ݺ�ʱ����������
               return ;   //ֱ�ӷ��ز���������              
            }                    
        }
       	Usart1_Control_Data.rxbuf[Usart1_Control_Data.rx_index] = rxdata;
        Usart1_Control_Data.rx_index++;
        if (Usart1_Control_Data.rx_index > (RxBufMax - 1)){
            Usart1_Control_Data.rx_index = (RxBufMax - 1);
            Usart1_Control_Data.rx_aframe = 1;  //�������ݳ����Զ���֡
            Usart1_Control_Data.rx_count = Usart1_Control_Data.rx_index+1;
            Usart1_Control_Data.rx_index = 0;   //�õ�һ֡���ݺ�ʱ����������
            Usart1_Control_Data.rx_start = 0;
            Auto_Frame_Time1 = AUTO_FRAME_TIMEOUT1; 
        }   
    }else{  //���յ�һ֡���ݺ���봦����ſ��Լ���������һ֡����
       Usart1_Control_Data.rx_start = 0;
       Auto_Frame_Time1 = AUTO_FRAME_TIMEOUT1; 
        return;
    }           
}
//=============================================================================
//��������:SLAVE_Rec_Comm
//���ܸ�Ҫ:PC��ΪͨѶ����ʱ���յĿ����ִ�����Ӧ
//����˵��:��
//��������:��
//ע��    :��
//=============================================================================
static u8  SLAVE_Rec_Comm(void)
{
	u8 i,res;
	u16 crc;
	if(Usart1_Control_Data.rx_count < 18){
		res = 2;
		return res;
	}crc=CRC_GetCCITT(Usart1_Control_Data.rxbuf,Usart1_Control_Data.rx_count-4);//֡����β����У��
	if((Usart1_Control_Data.rxbuf[Usart1_Control_Data.rx_count-3]+\
 	    Usart1_Control_Data.rxbuf[Usart1_Control_Data.rx_count-4]*256 == crc)){	    
		for(i = 0;i < 18;i++){
            PC_Host_Rec.send_buf[i] = Usart1_Control_Data.rxbuf[i];
        }//�����ݸ��Ƹ�����ͨѶ�ṹ��
		switch(PC_Host_Rec.control.ch1_state){
		case 0x00:
							Channel.ch1.send_num = 0;
							Channel.ch1.state = READY;	 
							break;
		case 0x01:Channel.ch1.send_num = PC_Host_Rec.control.ch1_num;	
							Channel.ch1.send_actual = 0;
							Channel.ch1.state = READY ;
							PC_Host_Rec.control.ch1_state = 0;
							break;
		default : Channel.ch1.send_num = 0;
							Channel.ch1.state = READY;
							break;
		}
		switch(PC_Host_Rec.control.ch2_state){
		case 0x00:	
							Channel.ch2.send_num = 0;
							Channel.ch2.state = READY;
							break;
		case 0x01:Channel.ch2.send_num = PC_Host_Rec.control.ch2_num;	
							Channel.ch2.send_actual = 0;
							Channel.ch2.state = READY ;
							PC_Host_Rec.control.ch2_state = 0;
							break;
		default : Channel.ch2.send_num = 0;
							Channel.ch2.state = READY;
							break;
		}
		switch(PC_Host_Rec.control.ch3_state){
		case 0x00:
							Channel.ch3.send_num = 0;
							Channel.ch3.state = READY;
							break;
		case 0x01:Channel.ch3.send_num = PC_Host_Rec.control.ch3_num;	
							Channel.ch3.send_actual = 0;
							Channel.ch3.state = READY ;
							PC_Host_Rec.control.ch3_state = 0;
							break;
		default :
							Channel.ch3.send_num = 0;
							Channel.ch3.state = READY;
							break;
		}
		switch(PC_Host_Rec.control.ch4_state){
		case 0x00:	 
							Channel.ch4.send_num = 0;
							Channel.ch4.state = READY;
							break;
		case 0x01:Channel.ch4.send_num = PC_Host_Rec.control.ch4_num;	
							Channel.ch4.send_actual = 0;
							Channel.ch4.state = READY ;
							PC_Host_Rec.control.ch4_state = 0;
							break;
		default :	Channel.ch4.send_num = 0;
							Channel.ch4.state = READY;
							break;
		}
		switch(PC_Host_Rec.control.belt_state){
		case 0x00:	 
							break;
		case 0x01:belt.send_time = PC_Host_Rec.control.belt_time;	
							belt.actual_time = belt.send_time *400; //*2s
							belt.state = READY ;
							PC_Host_Rec.control.belt_state = 0;
							break;
		default : break;
		}		
			res = 0;	
	}else{
		 res = 1;
	}
	Usart1_Control_Data.tx_count = 0;
	Usart1_Control_Data.txbuf[Usart1_Control_Data.tx_count++] = 0x01;
	Usart1_Control_Data.txbuf[Usart1_Control_Data.tx_count++] = 0x58;
	Usart1_Control_Data.txbuf[Usart1_Control_Data.tx_count++] = 0x00;
	Usart1_Control_Data.txbuf[Usart1_Control_Data.tx_count++] = 0x02;
	if(res == 0)//���յ�������ȷ
	{
			Usart1_Control_Data.txbuf[Usart1_Control_Data.tx_count++] = 0x01;
			Usart1_Control_Data.txbuf[Usart1_Control_Data.tx_count++] = 0x00;
			crc=CRC_GetCCITT(Usart1_Control_Data.txbuf,Usart1_Control_Data.tx_count);
			Usart1_Control_Data.txbuf[Usart1_Control_Data.tx_count++] = (crc>>8)&0xFF; ;
			Usart1_Control_Data.txbuf[Usart1_Control_Data.tx_count++] = crc&0xFF;	
	}else if(res == 1){//CRCУ�����
			Usart1_Control_Data.txbuf[Usart1_Control_Data.tx_count++] = 0x00;
			Usart1_Control_Data.txbuf[Usart1_Control_Data.tx_count++] = 0x00;
			crc=CRC_GetCCITT(Usart1_Control_Data.txbuf,Usart1_Control_Data.tx_count);
			Usart1_Control_Data.txbuf[Usart1_Control_Data.tx_count++] = (crc>>8)&0xFF; ;
			Usart1_Control_Data.txbuf[Usart1_Control_Data.tx_count++] = crc&0xFF;
	}
	Usart1_Control_Data.txbuf[Usart1_Control_Data.tx_count++] = 0x0D;
	Usart1_Control_Data.txbuf[Usart1_Control_Data.tx_count++] = 0x0A;
	return res;
}
//=============================================================================
//��������:SLAVE_Rec_Comm
//���ܸ�Ҫ:PC��ΪͨѶ�ӻ�ʱ���յ����ݣ�������
//����˵��:��
//��������:��
//ע��    :�����������λ��ߵȴ����ճ�ʱ�������ٷ��ͣ�����״̬������ת��Ϊ�ӻ�ģʽ
//=============================================================================
static u8  Host_Rec_Comm(void)
{
	u8 i,res;
	u16 crc;
	if(Usart1_Control_Data.rx_count != 10){
		res = 2;
		return res;
	}crc=CRC_GetCCITT(Usart1_Control_Data.rxbuf,Usart1_Control_Data.rx_count-4);
	if((Usart1_Control_Data.rxbuf[Usart1_Control_Data.rx_count-3]+\
 	    Usart1_Control_Data.rxbuf[Usart1_Control_Data.rx_count-4]*256 == crc)){	    
		for(i = 0;i < 10;i++){
            MCU_Host_Rec.rec_buf[i] = Usart1_Control_Data.rxbuf[i];
        }//�����ݸ��Ƹ�����ͨѶ�ṹ��
		if(MCU_Host_Rec.control.comm_state == 1){//PC��Ӧ����ȷ����������
				res = 0;	
		}else{
				res = 3;
		}
	}else{
		 res = 1;
	}
	return res;
}
//=============================================================================
//��������:Execute_Host_Comm
//���ܸ�Ҫ:ִ����λ������������
//����˵��:��
//��������:��
//ע��    :��
//=============================================================================
static u8 Execute_Host_Comm(void)
{
	u8 res;
	switch(MCU_State){
	case SLAVE: res = SLAVE_Rec_Comm();
							if(0 == res){
								Usart1_Control_Data.tx_index = 0;
								USART_SendData(USART1,Usart1_Control_Data.txbuf[Usart1_Control_Data.tx_index++]);
								MCU_State = HOST;		//��ȷ���յ�PC�����͵Ŀ�����Ϣ����Ӧ��״̬����Ϊ����ģʽ
							}else if(1 == res){
								Usart1_Control_Data.tx_index = 0;
								USART_SendData(USART1,Usart1_Control_Data.txbuf[Usart1_Control_Data.tx_index++]);
							}
							break;
	case HOST :	res = Host_Rec_Comm();
							if(( res== 1)||(res == 3)){//����û����ȷ���յ����ݣ����·�������
								Usart1_Control_Data.tx_index = 0;
								Usart1_Control_Data.tx_count = 16;	
								PC_Answer.Nanswer_timeout = NANSWER_TIME;
								PC_Answer.answer_numout--;
								USART_SendData(USART1,Usart1_Control_Data.txbuf[Usart1_Control_Data.tx_index++]);//ԭ��������û�ı䣬����ֱ�ӷ���
							}else if(res == 0){
								PC_Answer.answer_state = 0;	
								MCU_State = SLAVE;		//��ȷ���յ�PC�����͵Ľ���״̬��Ϣ��ת��Ϊ�ӻ��ȴ���һ��PC���Ϳ�����Ϣ
								PC_Answer.Nanswer_timeout = NANSWER_TIME;
								PC_Answer.answer_numout = NANSWER_NUMOUT;
							}
						break;
	default :MCU_State = SLAVE;		
					 break ;
	}
	return res;
}

//=============================================================================
//��������:Respond_Host_Comm
//���ܸ�Ҫ:��Ӧ��λ���ķ�����������������Ѿ��Ӵ���һ��������
//����˵��:��
//��������:��
//ע��    :��
//=============================================================================
void Respond_Host_Comm(void)
{
    if (1 == Usart1_Control_Data.rx_aframe){    
				Execute_Host_Comm();		
				Usart1_Control_Data.rx_count = 0;
				Auto_Frame_Time1 = AUTO_FRAME_TIMEOUT1;
				Usart1_Control_Data.rx_aframe = 0;
    }else{
        return;
    }
}



