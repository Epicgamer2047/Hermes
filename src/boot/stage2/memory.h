#pragma once
#include "stdint.h"
#include "memdefs.h"


/*
typedef struct {

	void far* addr;
	uint32_t size;

} MEMORY_BLOCK;
*/ //future implementation



void far* memcpy(void far* dst, const void far* src, uint16_t num);
void far* memset(void far* ptr, int value, uint16_t num);
int memcmp(const void far* ptr1, const void far* ptr2, uint16_t num);

//memory allocation management (extremely crude)

extern unsigned far* BREAK_POINT = MEMORY_ALLOC_BEGIN;

unsigned far* malloc(uint32_t size); //should push the break limit of memory alloc and return the address of beginning before the break is pushed

//void far* brk(void far* ptr); //should free what ever pointing to later implement
void free(); //this will just reset the break point for now
