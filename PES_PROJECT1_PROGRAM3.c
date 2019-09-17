/**
 *@file PES_PROJECT1_PROGRAM3.h
 *@brief takes and prints input hexadecimal value and does a sequence of operations on it
 *used online gdb,code blocks and gcc development environment on windows for compiling,debugging, running the program
 *@author Harsh Rathore 
 *@date September 14 2019 
 *@version 1.0
 *
 */ 
#include<stdio.h>
void dec2bin(int Decimal);                      /*Function prototype to convert decimal to binary */
int main()
{
    int input=0xCAFE,check1,check2,check3,check4,operation1,operation2,operation3,byte_rev,rot4left,rot8right;
    printf("The input in Hexadecimal=");
    printf("0X%X\n",input);                     /*Print the Hexadecimal input*/
    check1=input&0xF;                                /*Bitwise and operation  to check if any last 3 bits of last 4 bits are on*/
    if (check1==0X7||check1==0XB||check1==0XD||check1==0XE) /*check if 3 of the last 4 bits are on and print true if yes
                                                                        and false if not*/
    {
        printf("TRUE that only 3 of the last 4 bits are on \t");
    }
    else
    {
        printf("FALSE as 3 of the last 4 bits are off \t");
    }
    printf("The binary value=");                             /* print the binary value */
    printf("0b");
    dec2bin(input);                                                    /*Function call to convert decimal to binary */
    printf("\n");                                                /*goto next line*/
    printf("\nThe Reverse of the byte order in Hexadecimal=");
    operation1=((input>>8)|(input<<8));                        /*Reverse the byte order  by shifting the input bitwise left 
                                                                and right by 8 bits and do bitwise or*/
    byte_rev=operation1&0x0000FFFF;                            /* Bitwise or with  0x0000FFFF to get the required output*/
    printf("0X%X\n",byte_rev);
    check2=byte_rev&0XF;                                      /*Bitwise and operation  to check if any last 3 bits of 
                                                                    last 4 bits are on*/
    if (check2==0X7||check2==0XB||check2==0XD||check2==0XE)    /*check if 3 of the last 4 bits are on and print true if 
                                                                    yes and false if not*/
    {
        printf("TRUE that only 3 of the last 4 bits are on \t");
    }
    else
    {
        printf("FALSE as only 3 of the last 4 bits are not on \t");
    }
    printf("The binary value=");                            /* print the binary value */
    printf("0b");
    dec2bin(byte_rev);                                      /*Function call to convert decimal to binary */
    printf("\n");
    printf("\nThe Rotation of result by 4 bits to the left in Hexadecimal=");
    operation2=((byte_rev<<4)|(byte_rev>>12));                /*Rotate bits left by 4 bits by shifting the input bitwise
                                                                left and right by 4 and bits respectively and bitwise or*/
    rot4left=operation2&0x0000FFFF;
    printf("0X%X\n",rot4left);
    check3=rot4left&0XF;                               /*Bitwise and operation  to check if any last 3 bits of last 4 bits are on*/
    if (check3==0X7||check3==0XB||check3==0XD||check3==0XE) /*check if 3 of the last 4 bits are on and print 
                                                                        true if yes and false if not*/
    {
        printf("TRUE that only 3 of the last 4 bits are on \t");
    }
    else
    {
        printf("FALSE as only 3 of the last 4 bits are not on  \t");
    }
    printf("The binary value=");                             /* print the binary value */
    printf("0b");
    printf("0b");
    dec2bin(rot4left);                                      /*Function call to convert decimal to binary */
    printf("\n");
    printf("\nThe Rotation of result by 8 bits to the right in Hexadecimal=");
    operation3=((rot4left>>8)|(rot4left<<8));              /*Rotate bits right by 8 bits by shifting
                                                                                the input bitwise left and right by 8 and bitwise or*/
    rot8right=operation3&0x0000FFFF;
    printf("0X%X\n",rot8right);
    check4=rot8right&0XF;                               /*Bitwise and operation  to check if any last 3 bits of last 4 bits are on*/

    if (check4==0X7||check4==0XB||check4==0XD||check4==0XE) /*check if 3 of the last 4 bits are on and print true 
                                                                        if yes and false if not*/
    {
        printf("TRUE that only 3 of the last 4 bits are on \t");
    }
    else
    {
        printf("FALSE as only 3 of the last 4 bits are not on \t");
    }
    printf("The binary value=");                            /* print the binary value */
    printf("0b");
    dec2bin(rot8right);                                    /*Function call to convert decimal to binary */
    printf("\n");


    return 0;

}

void dec2bin(int Decimal)                            /*Function declaration to convert decimal to binary */
{
    int i = 1;                                       /*Initializing value i needed to be used later*/
    int length = 16;                                 /*length of binary bits which the decimal has to be converted into*/
    char bin[17];                                    /*Initializing array where binary value will be stored*/
    bin[16] = '\0';                                  /*Putting the lats value of array as null*/
    int j = 15;                                      /*Initializing value j which will be the last element of array*/
    while (length)                                   /*while length of binary bits remains more than 1 while loop executes*/
    {
        if(Decimal&i)                                /*Checking if bitwise and of Decimal Value and i is 1 */
            bin[j--] = '1';                          /*If the bitwise operation value is less than 1,
                                                        then print 1 at end of array else print 0*/
        else
            bin[j--] = '0';
        i = i << 1;                                 /*shift i by 1 in each loop iteration and do bitwise operation everytime*/
        length--;                                        /*Decrement value of length of binary bits */
    }
    printf("%s", bin);                              /*print the binary value*/

}
