
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
LOAD
STR
PUSH
POP
LDI
LDF
MOV


// byte in opcode will determine if absolute or relative
// 5 control flow instructions
SYSCALL
JMP
JIF
CAL
CIF

// 12 alu instructions
ADD
SUB
MUL
DIV
MOD
AND
NOR
XOR
ARS
LRS
LLS
CMP


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