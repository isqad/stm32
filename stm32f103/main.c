#define STM32F10X_MD
#include "stm32f10x.h"

void delay(void);

int main()
{
    // set clock
    RCC->CR |= RCC_CR_HSEON; // enable external clock

    // wait for ready HSE
    while (!(RCC->CR | RCC_CR_HSERDY))
    {
    }

    // switch to HSE clock
    RCC->CFGR |= RCC_CFGR_SW_HSE;

    // Enable clock for PC port
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    // GPIO configuration
    GPIOC->CRH |= GPIO_CRH_MODE13_1; // MODE13[1:0] bits (01) - max speed 10Mhz
    GPIOC->CRH &= ~GPIO_CRH_CNF13; // Reset CNF13[1:0] bits (00) - push pull mode


    while (1)
    {
      GPIOC->BSRR |= GPIO_BSRR_BS13;
      delay();
      GPIOC->BSRR |= GPIO_BSRR_BR13;
      delay();
    }

    return 0;
}

void delay(void)
{
  for (uint32_t i = 0; i < 1000000; i++)
  {
    asm("NOP");
  }
}
