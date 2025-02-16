#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 4

char** hexadecimal_to_bits(const char* hex_string); // Need to return array of strings


// bitwise OR function -> SUM two array words in bits
int** bitwise_OR_result(char** result_1, char** result_2)
{
    int** sum_result = (int**) malloc(ROWS * sizeof(int*));

    for(int i = 0; i < ROWS; i++)
    {
        sum_result[i] = (int*) malloc(COLS * sizeof(int));
    }

    for(int i = ROWS-1; i >= 0; i--)
    {
        for(int j = COLS-1; j >= 0; j--){
            printf("%d: %d: %c\n", i, j,result_1[i][j]);
            printf("%d: %d: %c\n", i, j, result_2[i][j]);

            sum_result[i][j] = (result_1[i][j] - '0') + (result_2[i][j] - '0');
            if(sum_result[i][j] == 0)
            {
                sum_result[i][j] = 0;
            }
            else sum_result[i][j] = 1;
        }
    }

    return sum_result;
}

// bitwise AND function
int** bitwise_AND_result(char** result_1, char** result_2)
{
    int** sum_result = (int**) malloc(ROWS * sizeof(int*));

    for(int i = 0; i < ROWS; i++)
    {
        sum_result[i] = (int*) malloc(COLS * sizeof(int));
    }

    for(int i = ROWS-1; i >= 0; i--)
    {
        for(int j = COLS-1; j >= 0; j--)
        {
            sum_result[i][j] = (result_1[i][j] - '0') + (result_2[i][j] - '0');
            if(sum_result[i][j] == 2)
            {
                sum_result[i][j] = 1;
            }
            else sum_result[i][j] = 0;
        }
    }
    
    return sum_result;
}

// bitwise XOR function (XOR: ^)

int **bitwise_XOR_result(char** result_1, char** result_2)
{
    int** sum_result = (int**) malloc(ROWS * sizeof(int*));

    for(int i = 0; i < ROWS; i++)
    {
        sum_result[i] = (int*) malloc(COLS * sizeof(int));
    }

    for(int i = ROWS-1; i >= 0; i--)
    {
        for(int j = COLS-1; j>= 0; j--)
        {
            sum_result[i][j] = (result_1[i][j] - '0') + (result_2[i][j] - '0');
            if(sum_result[i][j] == 1)
            {
                sum_result[i][j] = 1;
            }
            else sum_result[i][j] = 0;
        }
    }

    return sum_result;
}

// bitwise NOT function 

int **bitwise_NOT_result(char** result)
{
    int** NOT_result = (int**) malloc(ROWS * sizeof(int*));

    for(int i = 0; i < ROWS; i++)
    {
        NOT_result[i] = (int*) malloc(COLS * sizeof(int));
    }

    for(int i = ROWS-1; i >= 0; i--)
    {
        for(int j = COLS-1; j >= 0; j--)
        {
            NOT_result[i][j] = (result[i][j] - '0');

            if(NOT_result[i][j] == 1)
            {
                NOT_result[i][j] = 0;
            } 
            else NOT_result[i][j] = 1;
        }
    }

    return NOT_result;
}

// bit rotation

int **bit_rotation_result(char** result, int count_of_bits_to_shift)
{
    int** bits_to_shift_result = (int**) malloc(ROWS * sizeof(int*));

    for(int i = 0; i < ROWS; i++)
    {
        bits_to_shift_result[i] = (int*) malloc(COLS * sizeof(int));
    }


    // save whole result array to work with
    int help_array[32];
    int counter=0;
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            help_array[counter] = (result[i][j] - '0');
            counter++;
        }
    }

    // save bits to shift
    int *array_for_shift_bits = (int*) malloc(count_of_bits_to_shift * sizeof(int));

    if(array_for_shift_bits == NULL)
    {
        printf("Memory allocation failed in bit_rotation_result function\n");
        return NULL;
    }

    // bits to shift
    for(int i = 0; i < count_of_bits_to_shift; i++)
    {
        array_for_shift_bits[i] = help_array[i];
    }

    // shift whole array
    int not_shift_bit_location = count_of_bits_to_shift;
    for(int i = 0; i < 32-count_of_bits_to_shift; i++)
    {
        help_array[i] = help_array[not_shift_bit_location];
        not_shift_bit_location++;
    }

    int position = 0;
    for(int i = 32-count_of_bits_to_shift; i < 32; i++) // Maybe try to control if I am on right position with or without +1
    {
        help_array[i] = array_for_shift_bits[position];
        position++;
    }

    int final_position_of_bits = 0;
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            bits_to_shift_result[i][j] = help_array[final_position_of_bits];
            final_position_of_bits++;
        }
    }

    // shift whole array to the left

    free(array_for_shift_bits);

    return bits_to_shift_result;

}

// bitwise addition +

int** bitwise_ADD_result(char** result_1, char** result_2)
{
    int** add_result = (int**) malloc(ROWS * sizeof(int*));
    
    for(int i = 0; i < ROWS; i++)
    {
        add_result[i] = (int*) malloc(COLS * sizeof(int));
        if(add_result[i] == NULL)
        {
            printf("Memory allocation failed in bitwise_ADD_result\n");
            for(int j = 0; j < i; j++)
            {
                free(add_result[j]);
            }
            free(add_result);
            return NULL;
        }
    }

    int carry = 0;

    for(int i = ROWS - 1; i >= 0; i--)
    {
        for(int j = COLS - 1; j >= 0; j--)
        {
            add_result[i][j] = (result_1[i][j] - '0') + (result_2[i][j] - '0');

            if(add_result[i][j] + carry == 2)
            {
                carry = 1;
                add_result[i][j] = 0;
            }
            else if(add_result[i][j] + carry == 1)
            {
                if(carry == 1) carry = 0;
                add_result[i][j] = 1;
            }
            else if(add_result[i][j] + carry == 0)
            {
                add_result[i][j] = 0;
            }
            else if(add_result[i][j] + carry == 3)
            {
                add_result[i][j] = 1;
                carry = 1;
            }
        }
    }

    return add_result;    
}



int main(int argc, char* argv[])
{

    printf("My bitwise_operations document\n");

    //char s[] = "ABCD";


    char s1[] = "0xefcdab89";
    char s2[] = "0x25afeb1d";


    char **result_1 = hexadecimal_to_bits(s1);
    char **result_2 = hexadecimal_to_bits(s2);
    
    //int sum_result[8][4];

    // bitwise OR |

    printf("Trying to use 1 bit each time: \n");

    int** sum_result_bitwise_OR = bitwise_OR_result(result_1, result_2);

    printf("Bitwise OR |:\n");
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%d", sum_result_bitwise_OR[i][j]);
        }
        printf(" ");
    }
    printf("\n");

    // end of bitwise OR |

    // bitwise AND &

    int** sum_result_bitwise_AND = bitwise_AND_result(result_1, result_2);
    printf("Bitwise AND &:\n");

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%d", sum_result_bitwise_AND[i][j]);
        }
        printf(" ");
    }
    printf("\n");

    // end of bitwise AND |

    // bitwise XOR ^


    int** sum_result_bitwise_XOR = bitwise_XOR_result(result_1, result_2);
    printf("Bitwise XOR ^:\n");

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%d", sum_result_bitwise_XOR[i][j]);
        }
        printf(" ");
    }
    printf("\n");

    // end of bitwise XOR ^

    // bitwise NOT

    int** result_bitwise_NOT = bitwise_NOT_result(result_1);
    printf("Bitwise NOT:\n");

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%d", result_bitwise_NOT[i][j]);
        }
        printf(" ");
    }
    printf("\n");

    // end of bitwise NOT
    
    // bit rotation
    int how_many_bits_to_rotate = 12;
    int** result_bit_rotation = bit_rotation_result(result_1, 12);
    printf("Bit rotation:\n");
    printf("Rotated number of bits: %d\n", how_many_bits_to_rotate);
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%d", result_bit_rotation[i][j]);
        }
        printf(" ");
    }
    printf("\n");

    // end of bit rotation

    // bitwise addition ADD

    int** result_bitwise_addition = bitwise_ADD_result(result_1, result_2);
    printf("Bitwise addition:\n");

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%d", result_bitwise_addition[i][j]);
        }
        printf(" ");
    }
    printf("\n");


    // end of bitwise addition ADD

    // free allocated memory
    if(result_1 != NULL)
    {
        printf("Format 1: \n");

        for(int i=0; i<ROWS; i++)
        {
            printf("%s ", result_1[i]);
        }
        printf("\n");

        for(int i=0; i<COLS; i++)
        {
                free(result_1[i]);
        }
        free(result_1);
    }

    if(result_2 != NULL)
    {
        printf("Format 2: \n");

        for(int i=0; i<ROWS; i++)
        {
            printf("%s ", result_2[i]);
        }
        printf("\n");

        for(int i=0; i<ROWS; i++)
        {
                free(result_2[i]);
        }
        free(result_2);
    }

    return 0;
}