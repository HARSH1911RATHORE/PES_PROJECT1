#include<stdio.h>
void dec2bin(int Decimal);                      /*Function prototype to convert decimal to binary */
int main()
{
    int a,input=0xCAFE,b,c,d,e,f,g,z,z1,z2;
    printf("The input in Hexadecimal=");
    printf("0X%X\n",input);                     /*Print the Hexadecimal input*/
    a=input&0xF;                                /*Bitwise and operation */
    if (a==0X7||a==0XB||a==0XD||a==0XE)         /*check if 3 of the last 4 bits are on */
    {
        printf("TRUE that 3 of the last 4 bits are on \t");                      /*if 3 of the last 4 bits are on print True and then print the binary value*/
        printf("The binary value=");
        printf("0b");
        dec2bin(input);                           /*Function call to convert decimal to binary */
        printf("\n");                              /*goto next line*/
        printf("\nThe Reverse of the byte order in Hexadecimal=");
        b=((input>>8)|(input<<8));                 /*Reverse the byte order  by shifting the input bitwise left and right by 8 bits and bitwise or*/
        z=b&0x0000FFFF;                            /* Bitwise or with  0x0000FFFF to get the required output*/
        printf("0X%X\n",z);
        c=input&0XF;
        if (c==0X7||c==0XB||c==0XD||c==0XE)
        {
            printf("TRUE that 3 of the last 4 bits are on \t");
            printf("The binary value=");
            printf("0b");
            dec2bin(z);                        /*Function call to convert decimal to binary */
            printf("\n");
            printf("\nThe Rotation of result by 4 bits to the left in Hexadecimal=");
            d=((b<<4)|(b>>12));                /*Rotate bits left by 4 bits by shifting the input bitwise left and right by 4 and bits respectively and bitwise or*/
            z1=d&0x0000FFFF;
            printf("0X%X\n",z1);
            e=input&0XF;
            if (e==0X7||e==0XB||e==0XD||e==0XE) /*check if 3 of the last 4 bits are on */
            {
                printf("TRUE that 3 of the last 4 bits are on \t");
                printf("The binary value=");
                printf("0b");
                dec2bin(z1);                         /*Function call to convert decimal to binary */
                printf("\n");
                printf("\nThe Rotation of result by 8 bits to the right in Hexadecimal=");
                f=((d>>8)|(d<<8));              /*Rotate bits right by 8 bits by shifting the input bitwise left and right by 8 and bitwise or*/
                z2=f&0x0000FFFF;
                printf("0X%X\n",z2);
                g=input&0XF;

                if (g==0X7||g==0XB||g==0XD||g==0XE) /*check if 3 of the last 4 bits are on */
				{
                    printf("TRUE that 3 of the last 4 bits are on \t");
                    printf("The binary value=");
                    printf("0b");
                    dec2bin(z2);                     /*Function call to convert decimal to binary */
                    printf("\n");
				}
            }
        }


    }

    else
    {
        printf("FALSE");
    }
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
            bin[j--] = '1';                          /*If the bitwise operation value is less than 1, then print 1 at end of array else print 0*/
        else
            bin[j--] = '0';
        i = i << 1;                                 /*shift i by 1 in each loop iteration and do bitwise operation everytime*/
        length--;                                        /*Decrement value of length of binary bits */
    }
    printf("%s", bin);                              /*print the binary value*/

}
