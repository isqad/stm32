#define STM32F10X_MD
#include "stm32f10x.h"

uint32_t counter;

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

    RCC->CR |= RCC_CR_PLLON;
    // wait for ready PLL
    while (!(RCC->CR | RCC_CR_PLLRDY))
    {
    }

    // Enable clock for PC port and timer
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    // Clock 24Mhz for TIM6
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
    // enable clock for APB1
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    //RCC->APB1RSTR |= RCC_APB1RSTR_TIM6RST;

    // GPIO configuration
    GPIOC->CRH |= GPIO_CRH_MODE13_1; // MODE13[1:0] bits (01) - max speed 10Mhz
    GPIOC->CRH &= ~GPIO_CRH_CNF13; // Reset CNF13[1:0] bits (00) - push pull mode

    // prescaler 24000 - 1 = 1ms
    TIM2->PSC = (uint32_t)(24000 - 1);
    TIM2->ARR = (uint32_t)(2000 - 1);
    TIM2->DIER |= TIM_DIER_UIE;
    TIM2->CR1 |= TIM_CR1_CEN | TIM_CR1_ARPE;

    NVIC_EnableIRQ(TIM2_IRQn);

    GPIOC->BSRR |= GPIO_BSRR_BS13;
    counter = 1;
    
    while (1)
    {
    }
    
    
    return 0;
}

void TIM2_IRQHandler(void) 
{
  TIM2->SR &= ~TIM_SR_UIF;

  if (counter == 1)
  {
    GPIOC->BSRR |= GPIO_BSRR_BR13;
    counter = 0;
  } else {
    GPIOC->BSRR |= GPIO_BSRR_BS13;
    counter = 1;
  }
}
