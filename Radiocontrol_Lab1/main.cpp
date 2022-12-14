#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>

void delay(int millis) {
	for(int i=0;i< millis*0x010000;i++);
}

int main(void)
{  
  GPIO_InitTypeDef  GPIO_InitStructure;

  // Enable PORTB Clock
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  /* Configure the GPIO_LED pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);	
	
	
	GPIO_SetBits(GPIOB, GPIO_Pin_8);
	
		while (1) {
		
		  //Turn on pin
		  GPIOB->ODR |= GPIO_Pin_8;  		  
		  //wait 10 carrots
		  delay(10);
		  //Turn off pin
		  GPIOB->ODR &= ~GPIO_Pin_8;     
		  //wait 30-10 carrots
		  delay(20);
  }
		
}