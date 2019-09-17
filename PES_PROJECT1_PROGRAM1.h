/**
 *@file PES_PROJECT1_PROGRAM1.h
 *@brief Declaration of all inbuilt library functions,
 *function prototypes which are there in the c source file 
 *used online gdb,code blocks and gcc development environment on windows 
 *for compiling,debugging, running the program
 *@author Harsh Rathore 
 *@date September 14 2019 
 *@version 1.0
 *
 */ 
#ifndef PES_PROJECT1_PROGRAM1
#define PES_PROJECT1_PROGRAM1

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

/**
*@brief converts decimal equivalent of input number into binary form
*
*Decimal value which needs to be converted
*
*@param Decimal value 
*@param op_size value to write to the location
*
*@return void
*/
void dec2bin (int32_t Decimal, int32_t op_size);

/**
*@brief converts decimal equivalent of number into octal form
*
*Decimal value which needs to be converted
*
*@param Decimal value to write to the location
*
*@return int
*/
int32_t dec2oct (int32_t dec);

/**
*@brief converts decimal equivalent of number into hexadecimal form
*
*Decimal value which needs to be converted
*
*@param Decimal value to write to the location
*
*@return int
*/
int32_t dec2hex (int32_t dec);

/**
*@brief Calculates sign 1's complement of input
*
*Input Decimal equivalent value which needs to be represented in sign 1's complement form
*
*@param Decimal equivalent of input 
*@param op_size value to write to the location
*
*@return int
*/
int32_t sign1comp (int32_t Decimal, int32_t op_size);

/**
*@brief converts decimal equivalent of sign 1's complement
*number into binary equivalent
*
*Decimal equivalent value which needs to be converted
*
*@param Sign1complement in decimal form 
*@param op_size value to write to the location
*
*@return void
*/
void sign1comp_dec2bin (int32_t Sign1complement_dec,int32_t op_size);


/**
*@brief converts decimal equivalent of sign 2's complement
*number into binary equivalent
*
*Decimal equivalent value which needs to be converted
*
*@param Sign 2's complement in decimal form 
*@param op_size value to write to the location
*
*@return void
*/
void sign2comp_dec2bin (int32_t Sign2complement_dec,int32_t op_size);


/**
*@brief Calculates signed magnitude complement of input
*
*Input Decimal equivalent value which needs to be represented 
*in sign magnitude binary form
*
*@param Decimal equivalent of input 
*@param op_size value to write to the location
*
*@return int
*/
int32_t sign_magnitude_dec (int32_t Decimal,int32_t op_size);

/**
*@brief converts decimal equivalent of sign magnitude
*number into binary equivalent
*
*Decimal equivalent value which needs to be converted
*
*@param Sign magnitude in decimal form 
*@param op_size value to write to the location
*
*@return void
*/
void sign_mag_dec2bin (int32_t Signed_magnitude_dec,int32_t op_size);

#endif	/*	PES_PROJECT1_PROGRAM1.h */
