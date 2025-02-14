#include <stdio.h>
#include <stdlib.h>

char** hexadecimal_to_bits(const char* hex_string); // Need to return array of strings

int main(int argc, char* argv[])
{

    printf("My bitwise_operations document\n");

    //char s[] = "ABCD";


    char s1[] = "0xefcdab89";
    char s2[] = "0x25afeb1d";


    char **result = hexadecimal_to_bits(s1);
    
    if(result != NULL)
    {
        printf("Format: \n");

        for(int i=0; i<8; i++)
        {
            printf("%s ", result[i]);
        }
        printf("\n");

        for(int i=0; i<8; i++)
        {
                free(result[i]);
        }
        free(result);
    }
    // bitwise OR |


    


    return 0;
}