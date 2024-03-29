#ifndef PES_PROJECT1_PROGRAM1
#define PES_PROJECT1_PROGRAM1

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>


/**​​
*​​@brief​​ finds decimal equivalent of a number
​​*for a following radix value
​​*​​​Input value which needs to converted
​​*
​​*​​@param​​ radix value
​​*​​@param​​ numerical input value​ ​to be converted ​
​*
​​*​​@return​​ int​
*/
int32_t dec (int32_t r, int32_t n);
/**​​
*​​@brief​​ converts decimal equivalent of input number into binary form
​​*
​​*​​​Decimal value which needs to be converted​​​​
​​*
​​*​​@param​​ Decimal value
​​*​​@param​​ op_size ​value​ ​to ​​write​ ​to ​​the ​​location​
​*
​​*​​@return​​ void.​
*/
void dec2bin (int Decimal, int op_size);

/**​​
*​​@brief​​ converts decimal equivalent of number into octal form
​​*
​​*​​​Decimal value which needs to be converted​​​​
​​*
​​*​​@param​​ Decimal value ​ ​to ​​write​ ​to ​​the ​​location​
​*
​​*​​@return​​ int.​
*/
int dec2oct (int dec);

/**​​
*​​@brief​​ converts decimal equivalent of number into hexadecimal form
​​*
​​*​​​Decimal value which needs to be converted​​​​
​​*
​​*​​@param​​ Decimal value ​ ​to ​​write​ ​to ​​the ​​location​
​*
​​*​​@return​​ int.​
*/
int dec2hex (int dec);

/**​​
*​​@brief​​ Calculates sign 1's complement of input
​​*
​​*​​​Input Decimal equivalent value which needs to be represented in sign 1's complement form​​​
​​*
​​*​​@param​​ Decimal equivalent of input
​​*​​@param​​ op_size ​value​ ​to ​​write​ ​to ​​the ​​location​
​*
​​*​​@return​​ int.​
*/
int sign1comp (int Decimal, int op_size);

/**​​
*​​@brief​​ converts decimal equivalent of sign 1's complement
*number into binary equivalent
​​*
​​*​​​Decimal equivalent value which needs to be converted​​​​
​​*
​​*​​@param​​ Sign1complement in decimal form
​​*​​@param​​ op_size ​value​ ​to ​​write​ ​to ​​the ​​location​
​*
​​*​​@return​​ void.​
*/
void sign1comp_dec2bin (int Sign1complement_dec,int op_size);


/**​​
*​​@brief​​ converts decimal equivalent of sign 2's complement
*number into binary equivalent
​​*
​​*​​​Decimal equivalent value which needs to be converted​​​​
​​*
​​*​​@param​​ Sign 2's complement in decimal form
​​*​​@param​​ op_size ​value​ ​to ​​write​ ​to ​​the ​​location​
​*
​​*​​@return​​ void.​
*/
void sign2comp_dec2bin (int Sign2complement_dec,int op_size);


/**​​
*​​@brief​​ Calculates signed magnitude complement of input
​​*
​​*​​​Input Decimal equivalent value which needs to be represented
*in sign magnitude binary form​​​
​​*
​​*​​@param​​ Decimal equivalent of input
​​*​​@param​​ op_size ​value​ ​to ​​write​ ​to ​​the ​​location​
​*
​​*​​@return​​ int.​
*/
int sign_magnitude_dec (int Decimal, int op_size);

/**​​
*​​@brief​​ converts decimal equivalent of sign magnitude
*number into binary equivalent
​​*
​​*​​​Decimal equivalent value which needs to be converted​​​​
​​*
​​*​​@param​​ Sign magnitude in decimal form
​​*​​@param​​ op_size ​value​ ​to ​​write​ ​to ​​the ​​location​
​*
​​*​​@return​​ void.​
*/
void sign_mag_dec2bin (int Signed_magnitude_dec,int op_size);

#endif	/*	PES_PROJECT1_PROGRAM1 */
