/**
 * Startup file for stm32f103
 **/
#define STM32F10X_MD
#include "stm32f10x.h"

// макро-определение для weak-определений
#define WEAK __attribute__((weak))

// объявления обработчиков системных искл. stm32f10xxx
void WEAK Reset_Handler(void);
void WEAK NMI_Handler(void);
void WEAK HardFault_Handler(void);
void WEAK MemManage_Handler(void);
void WEAK BusFault_Handler(void);
void WEAK UsageFault_Handler(void);
void WEAK SVCall_Handler(void);
void WEAK DebugMonitor_Handler(void);
void WEAK PendSV_Handler(void);
void WEAK SysTick_Handler(void);

// объявления обработчиков прерываний stm32f10xxx
void WEAK WWDG_IRQHandler(void);
void WEAK PVD_IRQHandler(void);
void WEAK TAMPER_IRQHandler(void);
void WEAK RTC_IRQHandler(void);
void WEAK FLASH_IRQHandler(void);
void WEAK RCC_IRQHandler(void);
void WEAK EXTl0_IRQHandler(void);
void WEAK EXTl1_IRQHandler(void);
void WEAK EXTl2_IRQHandler(void);
void WEAK EXTl3_IRQHandler(void);
void WEAK EXTl4_IRQHandler(void);
void WEAK DMA1_Channel1_IRQHandler(void);
void WEAK DMA1_Channel2_IRQHandler(void);
void WEAK DMA1_Channel3_IRQHandler(void);
void WEAK DMA1_Channel4_IRQHandler(void);
void WEAK DMA1_Channel5_IRQHandler(void);
void WEAK DMA1_Channel6_IRQHandler(void);
void WEAK DMA1_Channel7_IRQHandler(void);
void WEAK ADC1_2_IRQHandler(void);
void WEAK USB_HP_CAN_TX_IRQHandler(void);
void WEAK USB_LP_CAN_RX0_IRQHandler(void);
void WEAK CAN_RX1_IRQHandler(void);
void WEAK CAN_SCE_IRQHandler(void);
void WEAK EXTl9_5_IRQHandler(void);
void WEAK TIM1_BRK_IRQHandler(void);
void WEAK TIM1_UP_IRQHandler(void);
void WEAK TIM1_TRG_COM_IRQHandler(void);
void WEAK TIM1_CC_IRQHandler(void);
void WEAK TIM2_IRQHandler(void);
void WEAK TIM3_IRQHandler(void);
void WEAK TIM4_IRQHandler(void);
void WEAK I2C1_EV_IRQHandler(void);
void WEAK I2C1_ER_IRQHandler(void);
void WEAK I2C2_EV_IRQHandler(void);
void WEAK I2C2_ER_IRQHandler(void);
void WEAK SPI1_IRQHandler(void);
void WEAK SPI2_IRQHandler(void);
void WEAK USART1_IRQHandler(void);
void WEAK USART2_IRQHandler(void);
void WEAK USART3_IRQHandler(void);
void WEAK EXTl15_10_IRQHandler(void);
void WEAK RTCAlarm_IRQHandler(void);
void WEAK USBWakeup_IRQHandler(void);
void WEAK TIM8_BRK_IRQHandler(void);
void WEAK TIM8_UP_IRQHandler(void);
void WEAK TIM8_TRG_COM_IRQHandler(void);
void WEAK TIM8_CC_IRQHandler(void);
void WEAK ADC3_IRQHandler(void);
void WEAK FSMC_IRQHandler(void);
void WEAK STDIO_IRQHandler(void);
void WEAK TIM5_IRQHandler(void);
void WEAK SPI3_IRQHandler(void);
void WEAK UART4_IRQHandler(void);
void WEAK UART5_IRQHandler(void);
void WEAK TIM6_IRQHandler(void);
void WEAK TIM7_IRQHandler(void);
void WEAK DMA2_Channel1_IRQHandler(void);
void WEAK DMA2_Channel2_IRQHandler(void);
void WEAK DMA2_Channel3_IRQHandler(void);
void WEAK DMA2_Channel4_5_IRQHandler(void);

void WEAK Reserved_Handler(void);

// вершина стека объявляется extern, так как будет определена на этапе линковки
extern uint32_t _stack;

extern int main(void);

// таблица векторов прерываний
__attribute__((section(".interrupt_vectors_simple")))
void (* const InterruptVectorsSimple[])(void) =
{
  (void *)&_stack,
  Reset_Handler,
  NMI_Handler,
  HardFault_Handler,
  MemManage_Handler,
  BusFault_Handler,
  UsageFault_Handler,
  Reserved_Handler,
  Reserved_Handler,
  Reserved_Handler,
  Reserved_Handler,
  SVCall_Handler,
  DebugMonitor_Handler,
  Reserved_Handler,
  PendSV_Handler,
  SysTick_Handler,
  WWDG_IRQHandler,
  PVD_IRQHandler,
  TAMPER_IRQHandler,
  RTC_IRQHandler,
  FLASH_IRQHandler,
  RCC_IRQHandler,
  EXTl0_IRQHandler,
  EXTl1_IRQHandler,
  EXTl2_IRQHandler,
  EXTl3_IRQHandler,
  EXTl4_IRQHandler,
  DMA1_Channel1_IRQHandler,
  DMA1_Channel2_IRQHandler,
  DMA1_Channel3_IRQHandler,
  DMA1_Channel4_IRQHandler,
  DMA1_Channel5_IRQHandler,
  DMA1_Channel6_IRQHandler,
  DMA1_Channel7_IRQHandler,
  ADC1_2_IRQHandler,
  USB_HP_CAN_TX_IRQHandler,
  USB_LP_CAN_RX0_IRQHandler,
  CAN_RX1_IRQHandler,
  CAN_SCE_IRQHandler,
  EXTl9_5_IRQHandler,
  TIM1_BRK_IRQHandler,
  TIM1_UP_IRQHandler,
  TIM1_TRG_COM_IRQHandler,
  TIM1_CC_IRQHandler,
  TIM2_IRQHandler,
  TIM3_IRQHandler,
  TIM4_IRQHandler,
  I2C1_EV_IRQHandler,
  I2C1_ER_IRQHandler,
  I2C2_EV_IRQHandler,
  I2C2_ER_IRQHandler,
  SPI1_IRQHandler,
  SPI2_IRQHandler,
  USART1_IRQHandler,
  USART2_IRQHandler,
  USART3_IRQHandler,
  EXTl15_10_IRQHandler,
  RTCAlarm_IRQHandler,
  USBWakeup_IRQHandler,
  TIM8_BRK_IRQHandler,
  TIM8_UP_IRQHandler,
  TIM8_TRG_COM_IRQHandler,
  TIM8_CC_IRQHandler,
  ADC3_IRQHandler,
  FSMC_IRQHandler,
  STDIO_IRQHandler,
  TIM5_IRQHandler,
  SPI3_IRQHandler,
  UART4_IRQHandler,
  UART5_IRQHandler,
  TIM6_IRQHandler,
  TIM7_IRQHandler,
  DMA2_Channel1_IRQHandler,
  DMA2_Channel2_IRQHandler,
  DMA2_Channel3_IRQHandler,
  DMA2_Channel4_5_IRQHandler,
};

void Reset_Handler(void)
{
  main();
}

