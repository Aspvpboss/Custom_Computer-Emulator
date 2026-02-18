

# Address space


0x0000 - 0x00FF: hardcoded bootloader (256B)

0x0100 - 0x7EFF: RAM (~32 KiB)

0x7F00 - 0x7FFF: MMIO (256B)

0x8000 - 0xFFFF: Selected ROM bank (32 KiB for each bank)
    can support techinically up to 2 ^ 16 amount of banks
    each bank being a binary file that is loaded

most functions will XIP (execute in place), but there should be a function in loaded from rom into ram that will switch banks, so that the program isn't running from the rom bank while it is switch banks

# Addressing modes

|Mode| Name | Extra bytes | Meaning |
|:---:|:---:|:---:|:---:|
| 000 | Reg | 2 | Rn0 + Rn1 -> Rn2 | 
| 001 | Reg indirect | 1 | [Rn] |
| 010 | Reg index imm8 | 3 | [Rn + imm8] |
| 011 | Reg index imm16 | 4 | [Rn + imm16] -> Rn |
| 100 | Reg imm8 | 2 | Rn + imm8 -> Rn |
| 101 | Reg imm16 | 3 | Rn + imm16 -> Rn |
| 110 |  Immediate8 | 1 | #imm8 |
| 111 |  Immediate16 | 2 | #imm16 |


# Registers
| ALU registers | FPU registers |
|:---:|:---:|
| 8 16-bit registers, stack pointer, frame pointer, and rom bank register | 8 16-bit IEEE floating point registers |

Instructions normally encode the ALU register operand using a 4-bit field. For memory operations, an additional high bit extends this field to 5 bits, where the extra bit specifies the transfer width (0 = 16-bit word, 1 = 8-bit byte)
    

# Instruction Set

### 32 total instructions

#### 6 memory instructions
- LOAD - load from memory into register
- STR - store register into address in memory
- PUSH - push register into memory
- POP - pop from memory into register
- LDI - load integer immediate into int register
- MOV - reg to reg, reg to float, float to reg, float to float


#### 6 control flow instructions
- SYSCALL - system call special functions (not in memory)
- JMP - absolute or relative, depends on addressing mode
- JIF - same as jmp
- CAL - functional absolute or relative
- CIF - same as cal
- RET - returns from function call

#### 12 alu instructions
- ADD - adds two integers
- SUB - subtracts two integers
- MUL - multiplys two integers
- DIV - divides two integers
- MOD - modulos two integers
- CMP - compares two integers
- AND - ands two integers
- NOR - nors two integers
- XOR - xors two integers
- ARS - arthimatic right shifts a integer
- LRS - logical right shifts a integer
- LLS - logical left shifts a integer

#### 8 float instructions
- FADD - adds two floats
- FSUB - subtracts two floats
- FMUL - multiplys two floats
- FDIV - divides two floats
- FSQRT - takes square root of float
- FCMP - compares two floats
- FINT - converts float to integer
- IFLO - converts integer to float

