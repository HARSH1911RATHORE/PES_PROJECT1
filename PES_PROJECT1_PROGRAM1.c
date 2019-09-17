/**
 *@file PES_PROJECT1_PROGRAM1.c
 *@brief TAKES NUMERICAL INPUT OF RADIX VALUE, OPERAND SIZE AND NUMBER AND PRINTS THE OUTPUT
 *used online gdb,code blocks and gcc development environment on windows for compiling,debugging, running the program
 *@author Harsh Rathore
 *@date September 14 2019
 *@version 1.0
 *
 */

#include "PES_PROJECT1_PROGRAM1.h"

int main ()
{
char dec_max[20]="15",bin_max[20]="0b1111",octal_max[20]="017",        /*Char array to store the max and min of all
                                                                                        the numerical representations*/
hex_max[20]="0xF",sgn_1_max[20]="0b0111",sgn_2_max[20]="0b0111",
sgn_mag_max[20]="0b0111";
char dec_min[20]="0",bin_min[20]="0b0000",octal_min[20]="0",
hex_min[20]="0x0",sgn_1_min[20]="0b1000",sgn_2_min[20]="0b1000",
sgn_mag_min[20]="0b1111";
char dec_max1[20]="255",bin_max1[20]="0b11111111",octal_max1[20]="0377",
hex_max1[20]="0XFF",sgn_1_max1[20]="0b01111111",
sgn_2_max1[20]="0b01111111",sgn_mag_max1[20]="0b01111111";
char dec_min1[20]="0",bin_min1[20]="0b00000000",
octal_min1[20]="0",hex_min1[20]="0x0",sgn_1_min1[20]="0b10000000",
sgn_2_min1[20]="0b10000000",sgn_mag_min1[20]="0b11111111";
char dec_max2[20]="65535",bin_max2[20]="0b1111111111111111",
octal_max2[20]="0177777",hex_max2[20]="0XFFFF",
sgn_1_max2[20]="0b0111111111111111",sgn_2_max2[20]="0b0111111111111111",
sgn_mag_max2[20]="0b0111111111111111";
char dec_min2[20]="0",bin_min2[20]="0b0000000000000000",octal_min2[20]="0",
hex_min2[20]="0x0",sgn_1_min2[20]="0b1000000000000000",
sgn_2_min2[20]="0b1000000000000000",sgn_mag_min2[20]="0b1111111111111111";

int32_t num, Decimal,Decimal_absolute, radix, op_size, Octal, Hexadecimal,
 Sign1complement_dec, Sign2complement_dec,Signed_magnitude_dec;

printf ("enter the value of radix");                       /*take base value of input*/
scanf ("%d", &radix);

if (radix == 8 || radix == 10 || radix == 16)             /*Check if radix value meets requirements*/
{
      printf ("enter operand size");                      /*take size of input*/
      scanf ("%d", &op_size);
      if (op_size == 4 || op_size == 8 || op_size == 16)  /*Check if operand size meets requirements*/
      {


        if(op_size==4)
        {                                                  /*if operand size is 4, take input and final the decimal equivalent of it*/
            printf ("Take the input");
            scanf ("%d", &num);
            Decimal = dec (radix, num);

            if (num < 0)                                  /*if number is negative Decimal is complement of Decimal absolute value*/
            {
                Decimal = (Decimal * -1);
                Decimal_absolute=abs(Decimal);
                if (abs(Decimal)<=(pow (2, (op_size)) - 1) && abs(Decimal)>=0) /*Check if absolute decimal value of input is in range*/
                {
                    printf("\nOutput \t \t \t Value \t \t Maximum \t Minimum\n"); /*Print all the unsigned numerical representations
                                                                                 whose absolute value is in range*/
                    printf ("Decimal(abs)  \t \t %d       \t %s     \t %s\n",
                             Decimal_absolute,dec_max,dec_min);
                    printf("Binary(abs)  \t \t 0b");
                    dec2bin (abs(Decimal), op_size);
                    printf(" \t %s \t %s",bin_max,bin_min);
                    Octal = dec2oct (Decimal);
                    printf ("\nOctal(abs) \t \t 0%d     \t %s     \t %s\n",
                             Octal,octal_max,octal_min);
                    Hexadecimal = dec2hex (Decimal);
                    printf ("hexadecimal(abs)  \t 0x%d    \t %s    \t %s\n",
                             Hexadecimal,hex_max,hex_min);
                    if (Decimal >= (((pow (2, (op_size)))/2)*-1)+1)     /*Check if input falls in the range, where signed
                                                                                        representations of that input exist*/
                    {
                        Sign1complement_dec = sign1comp (abs (Decimal), op_size);
                        printf("Sign1complement \t 0b");                /*Print all the signed numerical representations
                                                                                of input which fall in range*/
                        sign1comp_dec2bin (Sign1complement_dec, op_size);
                        printf(" \t %s \t %s",sgn_1_max,sgn_1_min);
                        Sign2complement_dec = Sign1complement_dec + 1;
                        printf("\nSign2complement \t 0b");
                        sign2comp_dec2bin (Sign2complement_dec, op_size);
                        printf(" \t %s \t %s",sgn_2_max,sgn_2_min);
                        Signed_magnitude_dec=sign_magnitude_dec( Decimal, op_size);
                        printf("\nSigned_magnitude  \t 0b");
                        sign_mag_dec2bin (Signed_magnitude_dec,op_size);
                        printf(" \t %s \t %s \t",sgn_mag_max,sgn_mag_min);

                    }
                    else                                                 /*Print error if signed numerical representation
                                                                                    of input has been exceeded*/
                    {
                        printf("Sign magnitude representation range is exceeded");
                    }

                }

                else                                                /*Print invalid input if the value of decimal of that input
                                                                            has exceeded the range it can represent*/
                {
                printf("Invalid Input");
                }
            }


            else                                                    /*if number is positive Decimal is same of Decimal absolute value*/
            {
                Decimal_absolute=abs(Decimal);
                if (abs(Decimal)<=(pow (2, (op_size)) - 1) && abs(Decimal)>=0) /*Check if absolute decimal value of input is in range*/
                {
                    printf("\nOutput \t \t \t Value \t \t Maximum \t Minimum\n");
                    printf ("Decimal(abs)  \t \t %d       \t %s     \t %s\n",
                             Decimal_absolute,dec_max,dec_min);
                    printf("Binary(abs)  \t \t 0b");                            /*Print all the unsigned numerical representations
                                                                                 whose absolute value is in range*/
                    dec2bin (abs(Decimal), op_size);
                    printf(" \t %s \t %s",bin_max,bin_min);
                    Octal = dec2oct (Decimal);
                    printf ("\nOctal(abs) \t \t 0%d     \t %s     \t %s\n",
                             Octal,octal_max,octal_min);
                    Hexadecimal = dec2hex (Decimal);
                    printf ("hexadecimal(abs)  \t 0x%d    \t %s    \t %s\n",
                             Hexadecimal,hex_max,hex_min);

                    if (Decimal <= (((pow (2, (op_size)))/2))-1)     /*Check if input falls in the range, where signed
                                                                                        representations of that input exist*/
                    {
                        printf("Sign1complement  \t 0b");
                        sign1comp_dec2bin (Decimal_absolute, op_size); /*Print all the signed numerical representations
                                                                                of input which fall in range*/
                        printf(" \t %s \t %s",sgn_1_max,sgn_1_min);
                        Sign2complement_dec = Decimal_absolute ;
                        printf("\nSign2complement  \t 0b");
                        sign2comp_dec2bin (Sign2complement_dec, op_size);
                        printf(" \t %s \t %s",sgn_2_max,sgn_2_min);
                        printf("\nSigned_magnitude  \t 0b");
                        dec2bin (Decimal, op_size);
                        printf(" \t %s \t %s",sgn_mag_max,sgn_mag_min);
                    }
                    else                                                 /*Print error if signed numerical representation
                                                                                    of input has been exceeded*/
                    {
                        printf("Sign magnitude representation range is exceeded");
                    }

                }

                else                                                    /*Print invalid input if the value of decimal of that input
                                                                            has exceeded the range it can represent*/
                {
                printf("Invalid Input");
                }
            }



        }

        else if (op_size==8)                                        /*if operand size is 8, take input and final
                                                                                                    the decimal equivalent of it*/
        {
            printf ("Take the input");
            scanf ("%d", &num);
            Decimal = dec (radix, num);

            if (num < 0)                                          /*if number is negative Decimal is complement of
                                                                                Decimal absolute value*/
            {
                Decimal = (Decimal * -1);
                Decimal_absolute=abs(Decimal);
                if (abs(Decimal)<=(pow (2, (op_size)) - 1) && abs(Decimal)>=0) /*Check if absolute decimal value of input is in range*/
                {
                    printf("\nOutput \t \t \t Value \t \t Maximum \t Minimum\n"); /*Print all the unsigned numerical representations
                                                                                 whose absolute value is in range*/
                    printf ("Decimal(abs)  \t \t %d       \t %s  \t \t %s\n",
                             Decimal_absolute,dec_max1,dec_min1);
                    printf("Binary(abs) \t \t 0b");
                    dec2bin (abs(Decimal), op_size);
                    printf(" \t %s \t %s",bin_max1,bin_min1);
                    Octal = dec2oct (Decimal);
                    printf ("\nOctal(abs) \t \t 0%d     \t %s     \t %s\n",
                             Octal,octal_max1,octal_min1);
                    Hexadecimal = dec2hex (Decimal);
                    printf ("hexadecimal(abs)  \t 0x%d    \t %s    \t %s\n",
                             Hexadecimal,hex_max1,hex_min1);
                    if (Decimal >= (((pow (2, (op_size)))/2)*-1)+1)             /*Check if input falls in the range, where signed
                                                                                        representations of that input exist*/
                    {
                        Sign1complement_dec = sign1comp (abs (Decimal), op_size);
                        printf("Sign1complement \t 0b");                            /*Print all the signed numerical representations
                                                                                       of input which fall in range*/
                        sign1comp_dec2bin (Sign1complement_dec, op_size);
                        printf(" \t %s \t %s",sgn_1_max1,sgn_1_min1);
                        Sign2complement_dec = Sign1complement_dec + 1;
                        printf("\nSign2complement \t 0b");
                        sign2comp_dec2bin (Sign2complement_dec, op_size);
                        printf(" \t %s \t %s",sgn_2_max1,sgn_2_min1);
                        Signed_magnitude_dec=sign_magnitude_dec( Decimal, op_size);
                        printf("\nSigned_magnitude  \t 0b");
                        sign_mag_dec2bin (Signed_magnitude_dec,op_size);
                        printf(" \t %s \t %s \t",sgn_mag_max1,sgn_mag_min1);
                     }
                    else                                                         /*Print error if signed numerical representation
                                                                                   of input has been exceeded*/
                    {
                        printf("Sign magnitude representation range is exceeded");
                    }

                }

                else                                                  /*Print invalid input if the value of decimal of that input
                                                                        has exceeded the range it can represent*/
                {
                printf("Invalid Input");
                }
            }


            else                                                                /*if number is positive Decimal is same
                                                                                        of Decimal absolute value*/
            {
                Decimal_absolute=abs(Decimal);
                if (abs(Decimal)<=(pow (2, (op_size)) - 1) && abs(Decimal)>=0)   /*Check if absolute decimal value of input is in range*/
                {
                    printf("\nOutput \t \t \t Value \t \t Maximum \t Minimum\n");  /*Print all the unsigned numerical representations
                                                                                 whose absolute value is in range*/
                    printf ("Decimal(abs)  \t \t %d       \t %s  \t \t %s\n",
                            Decimal_absolute,dec_max1,dec_min1);
                    printf("Binary(abs) \t \t 0b");
                    dec2bin (abs(Decimal), op_size);
                    printf(" \t %s \t %s",bin_max1,bin_min1);
                    Octal = dec2oct (Decimal);
                    printf ("\nOctal(abs) \t \t 0%d     \t %s     \t %s\n",
                            Octal,octal_max1,octal_min1);
                    Hexadecimal = dec2hex (Decimal);
                    printf ("hexadecimal(abs)  \t 0x%d    \t %s    \t %s\n",
                             Hexadecimal,hex_max1,hex_min1);
                    if (Decimal <= (((pow (2, (op_size)))/2))-1)                    /*Check if input falls in the range, where signed
                                                                                        representations of that input exist*/
                    {
                        Sign1complement_dec = abs (Decimal);                        /*Print all the signed numerical representations
                                                                                        of input which fall in range*/
                        printf("Sign1complement\t \t 0b");
                        sign1comp_dec2bin (Decimal_absolute, op_size);
                        printf(" \t %s \t %s",sgn_1_max1,sgn_1_min1);
                        Sign2complement_dec = Sign1complement_dec ;
                        printf("\nSign2complement\t \t 0b");
                        sign2comp_dec2bin (Sign2complement_dec, op_size);
                        printf(" \t %s \t %s",sgn_2_max1,sgn_2_min1);
                        printf("\nSigned_magnitude \t 0b");
                        dec2bin (Decimal, op_size);
                        printf(" \t %s \t %s",sgn_mag_max1,sgn_mag_min1);
                    }
                    else                                                            /*Print error if signed numerical representation
                                                                                      of input has been exceeded*/
                    {
                        printf("Sign magnitude representation range is exceeded");
                    }

                }

                else                                                  /*Print invalid input if the value of decimal of that input
                                                                            has exceeded the range it can represent*/
                {
                printf("Invalid Input");
                }
            }

        }


        else                                                                     /*if operand size is 16, take input and final
                                                                                                    the decimal equivalent of it*/
        {
            printf ("Take the input");
            scanf ("%d", &num);
            Decimal = dec (radix, num);

            if (num < 0)                                                        /*if number is negative Decimal is complement
                                                                                                of Decimal absolute value*/
            {
                Decimal_absolute=abs(Decimal);
                Decimal = (Decimal * -1);
                if (abs(Decimal)<=(pow (2, (op_size)) - 1) && abs(Decimal)>=0)  /*Check if absolute decimal value of input is in range*/
                {
                    printf("\nOutput \t \t Value \t \t     Maximum     \t \t Minimum\n");
                                                                                /*Print all the unsigned numerical representations
                                                                                             whose absolute value is in range*/
                    printf ("Decimal(abs) \t %d\t\t\t%s \t \t \t %s\n",
                             Decimal_absolute,dec_max2,dec_min2);
                    printf("Binary(abs) \t 0b");
                    dec2bin (abs(Decimal), op_size);
                    printf("  %s     \t %s",bin_max2,bin_min2);
                    Octal = dec2oct (Decimal);
                    printf ("\nOctal(abs)     \t 0%d\t\t\t%s              \t %s\n",
                             Octal,octal_max2,octal_min2);
                    Hexadecimal = dec2hex (Decimal);
                    printf ("Hexadecimal(abs) 0x%d\t\t\t%s                \t %s\n",
                             Hexadecimal,hex_max2,hex_min2);
                    if (Decimal >= (((pow (2, (op_size)))/2)*-1)+1)                 /*Check if input falls in the range, where signed
                                                                                        representations of that input exist*/
                    {
                        Sign1complement_dec = sign1comp (abs (Decimal), op_size);   /*Print all the signed numerical representations
                                                                                       of input which fall in range*/
                        printf("Sign1complement  0b");
                        sign1comp_dec2bin (Sign1complement_dec, op_size);
                        printf("  %s \t %s",sgn_1_max2,sgn_1_min2);
                        Sign2complement_dec = Sign1complement_dec + 1;
                        printf("\nSign2complement  0b");
                        sign2comp_dec2bin (Sign2complement_dec, op_size);
                        printf("  %s \t %s",sgn_2_max2,sgn_2_min2);
                        Signed_magnitude_dec=sign_magnitude_dec ( Decimal, op_size);
                        printf("\nSigned_magnitude 0b");
                        sign_mag_dec2bin (Signed_magnitude_dec,op_size);
                        printf("  %s \t %s",sgn_mag_max2,sgn_mag_min2);
                    }
                    else                                                           /*Print error if signed numerical representation
                                                                                      of input has been exceeded*/
                    {
                        printf("Sign magnitude representation range is exceeded");
                    }

                }

                else                                             /*Print invalid input if the value of decimal of that input
                                                                 has exceeded the range it can represent*/
                {
                    printf("Invalid Input");
                }
            }

            else                                                                /*if number is positive Decimal is same
                                                                                        of Decimal absolute value*/
            {
                Decimal_absolute=abs(Decimal);
                if (abs(Decimal)<=(pow (2, (op_size)) - 1) && abs(Decimal)>=0)    /*Check if absolute decimal value of input is in range*/
                {
                    printf("\nOutput \t \t Value \t \t     Maximum     \t \t Minimum\n");
                    printf ("Decimal(abs) \t %d\t\t     %s     \t\t\t%s\n",
                             Decimal_absolute,dec_max2,dec_min2);
                    printf("Binary(abs) \t 0b");                                  /*Print all the unsigned numerical representations
                                                                                    whose absolute value is in range*/
                    dec2bin (abs(Decimal), op_size);
                    printf("  %s     \t %s",bin_max2,bin_min2);
                    Octal = dec2oct (Decimal);
                    printf ("\nOctal(abs)     \t 0%d       \t \t%s \t1  \t %s\n",
                             Octal,octal_max2,octal_min2);
                    Hexadecimal = dec2hex (Decimal);
                    printf ("Hexadecimal(abs) 0x%d \t \t    %s\t \t \t %s\n",
                             Hexadecimal,hex_max2,hex_min2);
                    if (Decimal <= (((pow (2, (op_size)))/2))-1)                /*Check if input falls in the range, where signed
                                                                                        representations of that input exist*/
                    {
                        Sign1complement_dec = abs (Decimal);
                        printf("Sign1complement  0b");                          /*Print all the signed numerical representations
                                                                                        of input which fall in range*/
                        sign1comp_dec2bin (Sign1complement_dec, op_size);
                        printf("  %s \t %s",sgn_1_max2,sgn_1_min2);
                        Sign2complement_dec = Sign1complement_dec ;
                        printf("\nSign2complement  0b");
                        sign2comp_dec2bin (Sign2complement_dec, op_size);
                        printf("  %s \t %s",sgn_2_max2,sgn_2_min2);
                        printf("\nSigned_magnitude 0b");
                        dec2bin (Decimal, op_size);
                        printf("  %s \t %s",sgn_mag_max2,sgn_mag_min2);
                     }
                    else                                                         /*Print error if signed numerical representation
                                                                                      of input has been exceeded*/
                    {
                        printf("Sign magnitude representation range is exceeded");
                    }

                }

                else                                                    /*Print invalid input if the value of decimal of that input
                                                                         has exceeded the range it can represent*/
                {
                printf("Invalid Input");
                }
            }
        }


      }

      else                                                                        /*If operand size is not within requirements,
                                                                                            print invalid input*/
      {
		  printf ("Invalid input");
      }

}

else                                                                             /*If radix value is not within requirements,
                                                                                            print invalid input*/
{
	  printf ("Invalid input");
}

  return 0;
}

int32_t dec (int32_t r, int32_t n)                                                 /*Function to calculate decimal equivalent of input
                                                                                    with a radix value of 8,10 or 16*/
{
    int32_t remainder, sum = 0, x = 0;
    if (r == 8)                            /*if radix is 8, calculate decimal equivalent of input by storing remainder of division
                                            by 10 which is decremented in each loop iteration and calculate sum by multiplying
                                            the remainder by 8 raise to the equivalent digit position */
    {
        while (abs (n) != 0)
        {
            remainder = abs (n) % 10;
            sum = sum + (pow (8, x) * remainder);
            n = abs (n) / 10;
            x++;
        }
     return abs (sum);
    }
    else if (r == 16)                       /*if radix is 16, calculate decimal equivalent of input by storing remainder of division
                                            by 10 which is decremented in each loop iteration and calculate sum by multiplying
                                            the remainder by 8 raise to the equivalent digit position */
    {
        while (abs (n) != 0)
        {
            remainder = abs (n) % 10;
            sum = sum + (pow (16, x) * remainder);
            n = abs (n) / 10;
            x++;
        }
    return abs (sum);
    }

    else                                                /*if radix is 10, decimal is same as input */
    return abs (n);
}

void dec2bin(int32_t Decimal,int32_t op_size)
{

    int32_t i = 1;
    int32_t l = op_size;
    char bin[op_size+1];
    bin[op_size] = '\0';
    int32_t j = op_size-1;
    while (l)
    {
        if(abs(Decimal)&i)
            bin[j--] = '1';
        else
            bin[j--] = '0';
        i = i << 1;
        l--;
    }
    printf("%s", bin);

}

int32_t dec2oct (int32_t dec)                                   /*calculate octal equivalent of decimal by storing remainder of division
                                                        by 8 which is decremented in each loop iteration and calculate sum by storing
                                                        remainder in reverse order*/
{
    int32_t sum = 0, x = 1, rem;
    while (abs (dec) != 0)
    {
        rem = abs (dec) % 8;
        sum = sum + rem * x;
        dec = abs (dec) / 8;
        x = x * 10;
    }
    return sum;

}

int32_t dec2hex (int32_t dec)                                   /*calculate hexadecimal equivalent of decimal by storing remainder of division
                                                        by 8 which is decremented in each loop iteration and calculate sum by storing
                                                        remainder in reverse order*/
{
    int32_t sum = 0, x = 1, rem;
    while (abs (dec) != 0)
    {
        rem = abs (dec) % 16;
        sum = sum + rem * x;
        dec = abs (dec) / 16;
        x = x * 10;
    }
    return sum;

}

int32_t sign1comp (int32_t Decimal, int32_t op_size)
{                                           /* calculate the sign 1 complement of the input which
                                                is the complement of the bits of input if input is negative */
    int32_t Sign1complement_dec;
    if (op_size == 4)                       /*if operand size is 4, calculate sign1 complement by doing bitwise Xor operation
                                                with all ones */
    {
        Sign1complement_dec = Decimal ^ 0xF;
        return Sign1complement_dec;

    }

    else if (op_size == 8)                  /*if operand size is 8, calculate sign1 complement by doing bitwise Xor operation
                                                with all ones */
    {
        Sign1complement_dec = Decimal ^ 0XFF;
        return Sign1complement_dec;
    }
    else                                    /*if operand size is 16, calculate sign1 complement by doing bitwise Xor operation
                                                with all ones */
    {
        Sign1complement_dec = Decimal ^ 0XFFFF;
        return Sign1complement_dec;
    }

}

void
sign1comp_dec2bin (int32_t Sign1complement_dec, int32_t op_size)          /*calculate the binary equivalent of sign 1 complement*/
{
    int32_t i = 1;                                                  /*Initializing value i needed to be used later*/
    int32_t l = op_size;                                            /*length of binary bits which the decimal has to be converted into*/
    char bin[op_size+1];                                        /*Initializing array where binary value will be stored*/
    bin[op_size] = '\0';                                        /*Putting the lats value of array as null*/
    int32_t j = op_size-1;                                          /*Initializing value j which will be the last element of array*/
    while (l--)                                                 /*while length of binary bits remains more than 1 while loop executes*/
    {
        if(abs(Sign1complement_dec)&i)                              /*Checking if bitwise and of Decimal Value and i is 1 */
            bin[j--] = '1';                                         /*If the bitwise operation value is less than 1,
                                                                            then print 1 at end of array else print 0*/
        else
            bin[j--] = '0';
        i = i << 1;                                     /*shift i by 1 in each loop iteration and do bitwise operation everytime*/
    }
    printf("%s", bin);                                              /*print the binary value*/
}

void
sign2comp_dec2bin (int32_t Sign2complement_dec, int32_t op_size)
{
    int32_t i = 1;                                                  /*Initializing value i needed to be used later*/
    int32_t l = op_size;                                            /*length of binary bits which the decimal has to be converted into*/
    char bin[op_size+1];                                        /*Initializing array where binary value will be stored*/
    bin[op_size] = '\0';                                        /*Putting the lats value of array as null*/
    int32_t j = op_size-1;                                          /*Initializing value j which will be the last element of array*/
    while (l--)                                                 /*while length of binary bits remains more than 1 while loop executes*/
    {
        if(abs(Sign2complement_dec)&i)                          /*Checking if bitwise and of Decimal Value and i is 1 */
            bin[j--] = '1';                                     /*If the bitwise operation value is less than 1,
                                                                            then print 1 at end of array else print 0*/
        else
            bin[j--] = '0';
        i = i << 1;                                             /*shift i by 1 in each loop iteration and do bitwise operation everytime*/
    }
    printf("%s", bin);                                          /*print the binary value*/
}


int32_t sign_magnitude_dec (int32_t Decimal, int32_t op_size)       /* calculate the sign_magnitude whose msb is 1 if input is negative and msb is 0
                                                            input is positive*/
{
    int32_t Sign_mag_dec;                          /*if operand size is 4, calculate sign_magnitude by doing bitwise Xor operation
                                                with all a number having one at msb and zero's at other bits  */
    if (op_size == 4)
    {
        Sign_mag_dec = abs(Decimal) | 0x8;
        return Sign_mag_dec;

    }
    else if (op_size == 8)                   /*if operand size is 8, calculate sign_magnitude by doing bitwise Xor operation
                                                with all a number having one at msb and zero's at other bits  */
    {
        Sign_mag_dec = abs(Decimal) | 0X80;
        return Sign_mag_dec;
    }
    else                                    /*if operand size is 16, calculate sign_magnitude by doing bitwise Xor operation
                                                with all a number having one at msb and zero's at other bits  */
    {
        Sign_mag_dec = abs(Decimal) | 0X8000;
        return Sign_mag_dec;
    }

}

void
sign_mag_dec2bin (int32_t Signed_magnitude_dec,int32_t op_size)
{
    int32_t i = 1;                                                    /*Initializing value i needed to be used later*/
    int32_t l = op_size;                                             /*length of binary bits which the decimal has to be converted into*/
    char bin[op_size+1];                                         /*Initializing array where binary value will be stored*/
    bin[op_size] = '\0';                                         /*Putting the lats value of array as null*/
    int32_t j = op_size-1;                                           /*Initializing value j which will be the last element of array*/
    while (l--)                                                  /*while length of binary bits remains more than 1 while loop executes*/
    {
        if(abs(Signed_magnitude_dec)&i)                          /*Checking if bitwise and of Decimal Value and i is 1 */
            bin[j--] = '1';                                       /*If the bitwise operation value is less than 1,
                                                                    then print 1 at end of array else print 0*/
        else
            bin[j--] = '0';
        i = i << 1;                                        /*shift i by 1 in each loop iteration and do bitwise operation everytime*/
    }
    printf("%s", bin);                                               /*print the binary value*/
}





