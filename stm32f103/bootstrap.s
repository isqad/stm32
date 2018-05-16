@ stm32l152 has 0x8000 (32K) SRAM
@ SRAM is starting from 0x20000000
@ so stack is eq 0x20000000 + 0x8000 = 0x20008000
@ flash starts from 0x08000000

.syntax unified
.thumb
.cpu cortex-m3

.equ Stack_up, 0x20008000

.section .text

.word  Stack_up     @ stack header
.word  Reset + 1    @ start of program. +1 for format in Thumb instead ARM. Stm32 understands only set of Thumb commands

Reset:  B main

