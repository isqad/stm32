MEMORY
{
  rom : org = 0x08000000, l = 64K
  ram : org = 0x20000000, l = 20K
}

_stack = ORIGIN(ram) + LENGTH(ram);

SECTIONS
{
  .text : {
    KEEP(*(.interrupt_vectors_simple*))
    *(.text);
  } > rom

  .data : {
    *(.data);
  } > ram AT>rom = 0xff
}
