
// Driver for the debug (timing) pin.

// ping 9 ist der obere pin am pinheader auf dem PCB.. just in case. also pin 30 am MCU oder GPIOA9

#include "braids/drivers/raffi_pin.h"

#include <string.h>

namespace braids {

void RaffiPin::Init() {

  //RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);			// start the clock for gpio A
  
  GPIO_InitTypeDef gpio_init;									// start init sequence
  gpio_init.GPIO_Pin = GPIO_Pin_9;								// set pin 9 to be initialized
  gpio_init.GPIO_Speed = GPIO_Speed_50MHz;						// set to max speed
  gpio_init.GPIO_Mode = GPIO_Mode_Out_PP;						// set to pushpull state
  GPIO_Init(GPIOA, &gpio_init);									// init 

  //GPIOA->BSRR = GPIO_Pin_9;										
}

void RaffiPin::High() {
  GPIOA->BSRR = GPIO_Pin_9;
}

void RaffiPin::Low() {
  GPIOA->BRR = GPIO_Pin_9;
}

}  // namespace braids
