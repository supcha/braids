
// Driver for the debug (timing) pin.

#include "braids/drivers/debug_pin.h"

#include <string.h>

namespace braids {

void DebugPin::Init() {
  GPIO_InitTypeDef gpio_init;
  gpio_init.GPIO_Pin = GPIO_Pin_10;
  gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
  gpio_init.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOA, &gpio_init);

  GPIOA->BSRR = GPIO_Pin_10;
}

void DebugPin::High() {
  GPIOA->BSRR = GPIO_Pin_10;
}

void DebugPin::Low() {
  GPIOA->BRR = GPIO_Pin_10;
}

}  // namespace braids
