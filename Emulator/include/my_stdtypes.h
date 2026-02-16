#ifndef MY_STDTYPES_H
#define MY_STDTYPES_H

#include <stdio.h>

typedef _Float16 f16;
typedef float f32;
typedef double f64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

#ifdef DEBUG
    #define d_printf(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
    #define d_printf(fmt, ...)
#endif

enum CMP_FlagMasks{

    CMP_EQU = 1 << 0,
    CMP_NEQ = 1 << 1,
    CMP_IF0 = 1 << 2,
    
    CMP_ULT = 1 << 3,
    CMP_ULE = 1 << 4,
    CMP_UGR = 1 << 5,
    CMP_UGE = 1 << 6,
    
    CMP_SLT = 1 << 7,
    CMP_SLE = 1 << 8,
    CMP_SGR = 1 << 9,
    CMP_SGE = 1 << 10,
    
    CMP_CAR = 1 << 11,
    CMP_OVER = 1 << 12,

};

typedef u16 CMP_Flags;

#endif