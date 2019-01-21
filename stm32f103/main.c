#define STM32F10X_MD
#include "stm32f10x.h"

void delay(void);

int main()
{
    // set clock
    // Crystal 8MHz
    RCC->CR |= RCC_CR_HSEON; // enable external clock

    // wait for ready HSE
    while (!(RCC->CR | RCC_CR_HSERDY))
    {
    }

    // Configure PLL
    // External Source For PLL
    RCC->CFGR |= RCC_CFGR_PLLSRC_HSE;
    // Not div
    RCC->CFGR |= RCC_CFGR_PLLXTPRE_HSE;
    // 8 * 6 = 48MHz
    RCC->CFGR |= RCC_CFGR_PLLMULL6;

    // switch to PLL clock
    //RCC->CFGR |= RCC_CFGR_SW_HSE;
    RCC->CFGR |= RCC_CFGR_SW_PLL;

    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;

    RCC->CR |= RCC_CR_PLLON;
    // wait for ready PLL
    while (!(RCC->CR | RCC_CR_PLLRDY))
    {
    }

    // Enable clock for PC port and timer
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    // Clock 24Mhz for TIM6
    RCC->APB1ENR |= RCC_APB2ENR_TIM6EN;
    RCC->APB1RSTR |= RCC_APB1RSTR_TIM6RST;

    // GPIO configuration
    GPIOC->CRH |= GPIO_CRH_MODE13_1; // MODE13[1:0] bits (01) - max speed 10Mhz
    GPIOC->CRH &= ~GPIO_CRH_CNF13; // Reset CNF13[1:0] bits (00) - push pull mode

    /**
    while (1)
    {
      GPIOC->BSRR |= GPIO_BSRR_BS13;
      delay();
      delay();
      delay();
      GPIOC->BSRR |= GPIO_BSRR_BR13;
      delay();
    }
    **/
    NVIC_EnableIRQ(TIM6_DAC_IRQn);
    return 0;
}

void delay(void)
{
  for (uint32_t i = 0; i < 80000; i++)
  {
    asm("NOP");
  }
}
