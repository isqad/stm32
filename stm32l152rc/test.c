#include <stdio.h>
#define RCC_RC        0x00010300
#define RCC_CR_HSERDY 0x00020000

int main()
{
    printf("TEST %d", (RCC_RC & RCC_CR_HSERDY));
    return 0;
}
