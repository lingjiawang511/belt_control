#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"

#define       GLED_OFF   	GPIO_SetBits(GPIOA, GPIO_Pin_11)
#define       GLED_ON  		GPIO_ResetBits(GPIOA, GPIO_Pin_11)
#define       RLED_OFF   	GPIO_SetBits(GPIOA, GPIO_Pin_12)
#define       RLED_ON 	 	GPIO_ResetBits(GPIOA, GPIO_Pin_12)

extern u8 Gled_Num;
extern u8 Rled_Num;
extern u8 Gled_Light_Static;
extern u8 Rled_Light_Static;
void LED_GPIO_Config(void);
void Led_Flash(void);

#endif
