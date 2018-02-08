#include <stdio.h>
#include <stdlib.h>

#include <oslib.h>

long utilsConvertToBits(char *i_hex_string_value, long **i_bit_array_ptr, char **i_bit_array_value_ptr, char **i_digit_array_ptr)
{   long num_of_bits = 0;

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

