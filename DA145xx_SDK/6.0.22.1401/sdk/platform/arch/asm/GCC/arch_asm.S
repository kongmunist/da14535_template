
    .syntax unified
    .thumb
    .thumb_func
    .global arch_asm_delay_us
    .weak arch_asm_delay_us
    .type arch_asm_delay_us, %function

arch_asm_delay_us:
loop:
    cmp r0, #0
    beq exit
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
#ifdef __DA14531__
    nop
#endif
    subs r0, r0, #1
    bne loop
exit:
    bx lr
    .size arch_asm_delay_us, .-arch_asm_delay_us
