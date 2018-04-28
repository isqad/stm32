MEMORY
{
  rom : org = 0x08000000, l = 640K
  ram : org = 0x20000000, l = 32K
}

SECTIONS
{
  .text : {
    *(.text);
  } > rom

  .data : {
    *(.data);
  } > ram AT>rom = 0xff
}
