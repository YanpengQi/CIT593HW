/************************************************************************/
/* File Name : lc4_disassembler.h 										*/
/* Purpose   : This function declares functions for lc4_dissembler.c	*/
/*      																*/
/*             															*/
/* Author(s) : tjf 														*/
/************************************************************************/

#include <stdio.h>
#include "lc4_memory.h"

/*
 * declarations of functions that must defined in lc4_disassembler.c
 */



/**
 * translates the hex representation of arithmetic instructions
 * into their assembly equivalent in the given linked list.
 *
 * returns 0 upon success, and non-zero if an error occurs.
 */
int reverse_assemble (row_of_memory* memory) ;

