#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int i;                                                                               /*i is a counter for the loop*/
    char Type1[25]="digit     ";                                                         /*store the character code results in array*/
    char Type2[25]="lowercase";
    char Type3[25]="uppercase";
    char Type4[25]="whitespace";
    char Type5[25]="spec_character";
    char Type[25];
    char input[21]={66,114,117,99,101,32,83,97,121,115,32,72,105,33,7,9,50,48,49,57};    /*store the input values in array input*/
    for (i=0;i<=19;i++)
    {
                                                                                         /*Check each character code in input whether
                                                                                         it is digit,lower case,upper case, white space
                                                                                         or special character*/
        if (isdigit ( input[i] ))
        {
            strcpy(Type,Type1);
        }
        else if (islower(input[i]))
        {
            strcpy(Type,Type2);
        }
        else if (isupper(input[i]))
        {
            strcpy(Type,Type3);
        }
        else if(isspace(input[i]))
        {
            strcpy(Type,Type4);
        }
        else
        {
            strcpy(Type,Type5);
        }
                                                                                        /*Prints the input character code,
																						its type and ascii value*/

        printf("Code:%d  \t \t type:%s         \t \t ASCII:%c\n",input[i],Type,input[i]);
    }


return 0;

}

