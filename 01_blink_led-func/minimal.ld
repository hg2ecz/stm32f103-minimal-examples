MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 128K
    SRAM (xrw)  : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
    .text :
    {
        *(.vector_table)    /* Vector table */
        *(.text)            /* Program code */
    } >FLASH

    .data :
    {
        *(.data)
    } >SRAM
}
