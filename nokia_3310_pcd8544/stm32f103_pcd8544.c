#include "stm32f103_pcd8544.h"

unsigned char PCD8544_Buffer[PCD8544_BUFFER_SIZE];


void PCD8544_InitIO(void)
{
  // Enable AHB periph clock
  RCC->APB2ENR |= (PCD8544_RST_RCC | PCD8544_CE_RCC | PCD8544_CE_RCC);
}
