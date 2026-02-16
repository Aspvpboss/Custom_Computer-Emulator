

Address space

0x0000 - 0x00FF: hardcoded bootloader (256B)

0x0100 - 0x7EFF: RAM (~32 KiB)

0x7F00 - 0x7FFF: MMIO (256B)

0x8000 - 0xFFFF: Selected ROM bank (32 KiB for each bank)
    can support techinically up to 2 ^ 16 amount of banks
    each bank being a binary file that is loaded



Addressing modes

Mode  Name               Extra bytes   Meaning
--------------------------------------------------------
000   Reg                1             Rn
001   Reg indirect       1             [Rn]
010   Reg + imm8         2             [Rn + imm8]
011   Reg + imm16        3             [Rn + imm16]
100   Absolute16         2             [addr16]
101   PC-relative8       1             PC + signed imm8
110   Immediate8         1             #imm8
111   Immediate16        2             #imm16


of the 8 general purpose register, but there will "16 general purpose registers"
the 8 bit version of it, and the 16 bit version of it


ISA

// 7 memory instructions (operand will determine if 8 bit or 16 bit)
LOAD - load from memory into register
STR - store register into address in memory
PUSH - push register into memory
POP - pop from memory into register
LDI - load integer immediate into int register
LDF - load float immediate into float register
MOV - reg to reg, reg to float, float to reg, float to float


// byte in opcode will determine if absolute or relative
// 5 control flow instructions
SYSCALL - system call
JMP - absolute or relative, depends on addressing mode
JIF - same as jmp
CAL - functional absolute or relative
CIF - same as cal

// 12 alu instructions
ADD
SUB
MUL
DIV
MOD
CMP

AND
NOR
XOR

ARS
LRS
LLS


// 8 float instructions
FADD
FSUB
FMUL
FDIV
FSQRT

FCMP
FINT
IFLO


// 32 total instructions