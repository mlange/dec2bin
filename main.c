#include <stdio.h>
#include <stdlib.h>

#define LIBRARY "/mnt/d1/seamles/dev/lib/SeamLES"



/*
 *  Decimal     Hex        Binary
 *  String      String     String 
 *  ------- --> ------ --> --------
 *  213         d5         11010101
 */

long utilsConvertToBits(char *i_hex_string_value, 
			long **i_bit_array_ptr, 
			char **i_bit_array_value_ptr, 
			char **i_digit_array_ptr)
{   
    long num_of_bits = 0;

    if(i_hex_string_value && *i_hex_string_value)
    {
        char bits_array[] = { 0x1,0x2,0x4,0x8 };
        long ii;
        long len=strlen(i_hex_string_value);

        num_of_bits = len*4;

        if(i_bit_array_ptr)
        {
            *i_bit_array_ptr = (long *) calloc(1, num_of_bits * sizeof(long));
        }

        if(i_bit_array_value_ptr)
        {
            *i_bit_array_value_ptr = (char*) calloc(1, num_of_bits * sizeof(char));
        }

        if(i_digit_array_ptr)
        {
            *i_digit_array_ptr = (char*) calloc(1, num_of_bits * sizeof(char));
        }

        for(ii=0;ii<len;ii++)
        {  long bit;
           long dec_digit;
           char hex_digit[2];

           hex_digit[0]=i_hex_string_value[ii];
           hex_digit[1]='\0';
           sscanf(hex_digit, "%x", &dec_digit);
           /* 4 bits */
           for (bit=3;bit>=0;bit--)
           {   long arr_idx = ii*4+(4-bit-1);
               if(i_bit_array_ptr)
               {
                   (*i_bit_array_ptr)[arr_idx] = (len-ii-1)*4+bit;
               }
               if(i_bit_array_value_ptr)
               {
                   (*i_bit_array_value_ptr)[arr_idx] = (dec_digit & bits_array[bit])?1:0;
               }
               if(i_digit_array_ptr)
               {
                   (*i_digit_array_ptr)[arr_idx] = i_hex_string_value[ii];
               }
           }
        }
    }

    return num_of_bits;
}

int main(int argc, char *argv[])
{
    double decNumber;

    char decString[100];
    char hexString[100];
    char binString;

    decNumber = atol(argv[1]);

    /*
     *  Double --> Decimal String
     */

    sprintf(decString, "%.0f", decNumber);

    /*
     * Decimal String --> Double
     */

    string

printf("Decimal Number: %0f\n", decNumber);
printf("Decimal String: %s \n", decString);

    /* 
     * Decimal String --> Hex String 
     */

    sprintf(hexString, "%x", decString);

printf("Hex String: %s\n", hexString);

    /*
     * Hex String --> Binary String
     */

{
    long ii;

    long num_of_bits;

    long *bit_array       = NULL;
    char *bit_array_value = NULL;
    char *digit_array     = NULL;

    num_of_bits = utilsConvertToBits(hexString, 
                                     &bit_array, 
                                     &bit_array_value, 
                                     &digit_array);

    for (ii=0; ii<num_of_bits && bit_array && bit_array_value; ii++)
    {
        char digit[2];

        digit[0] = digit_array[ii];
        digit[1] = '\0';

        printf("%s  %ld  %ld\n", digit, bit_array[ii], (bit_array_value[ii])?1:0);
    }
}

/*
    printf("Decimal: %s\n", decString);
*/

    exit(0);
}
