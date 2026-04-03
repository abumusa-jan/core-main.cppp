section .text
    global get_cpu_cycles

get_cpu_cycles:
    rdtsc
    shl rdx, 32
    or rax, rdx
    ret
