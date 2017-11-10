#ifndef TYPES_H_
#define TYPES_H_
#include "types.h"

#define false 0
#define true 1
#define EOF -1

/* A boolean type */
typedef unsigned char boolean;
/* 1 byte sized type */
typedef unsigned char byte;
/* 2 byte sized type */
typedef unsigned short int word;
/* 4 byte sized type */
typedef unsigned int dword;
/* 8 byte sized type */
typedef unsigned long qword;

/* Preferiblemente sacar esto y meter todo como los tipos de arriba */
/* 1 byte sized type */
typedef unsigned char uint8_t;
/* 2 byte sized type */
typedef unsigned short uint16_t;
/* 4 byte sized type */
typedef unsigned int uint32_t;
/* 8 byte sized type */
typedef unsigned long uint64_t;

#endif
