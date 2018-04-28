#include "stm32l1xx.h"

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

    while (1)
    {
    }

    return 0;
}
