
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

ISA

// 8 memory instructions
LOAD16
LOAD8
STR16
STR8
PUSH8
PUSH16
POP8
POP16

// byte in opcode will determine if absolute or relative
// 5 control flow instructions
SYSCALL
JMP
JIF
CAL
CIF

// 10 alu instructions
ADD
SUB
MUL
DIV
MOD
AND
NOR
XOR
CMP

// 6 float instructions
FADD
FSUB
FMUL
FDIV
FSQRT


// 29 total instructions