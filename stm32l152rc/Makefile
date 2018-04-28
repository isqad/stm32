main.bin: main.elf
	arm-none-eabi-objcopy main.elf main.bin -O binary

disassm: main.elf
	arm-none-eabi-objdump -D main.elf > main.lst

main.elf: startup.o main.o
	arm-none-eabi-ld -o main.elf -T stm32l152rc.ld startup.o main.o

main.o:
	arm-none-eabi-gcc -O3 -nostdlib -nostartfiles -ffreestanding -Wall -mthumb -mcpu=cortex-m3 -I. -c main.c -o main.o

startup.o:
	arm-none-eabi-as -o startup.o startup.s

clean:
	rm *.bin *.o *.elf
