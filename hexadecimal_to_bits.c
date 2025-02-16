#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **hexadecimal_to_bits(const char* hex_string)
{

    char *s = malloc(strlen(hex_string) + 1); // +1 for the NULL terminator aka \0 to end string

    if(s != NULL)
    {
        strcpy(s, hex_string);
    }
    else{
        printf("Memory allocation failed in hexadecimal_to_bits program for 's' malloc\n");
        return NULL;
    }

    // Need to remove 0x from beginning
    char s_without0x[9]; // Needs to be large enough for \0 as well 
    strncpy(s_without0x, s + 2, 8);
    s_without0x[8] = '\0';

    /*
    for(int i = 0; i < 8; i++)
    {
        if(i == 0){
            s_without0x[0] = s[2];
            i+=2;
        } 
        else if(i > 0){
            s_without0x[i] = s[i];
        }
    }*/

    char hexadecimal_characters[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    char *bits[] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010","1011","1100", 
                   "1101", "1110", "1111"};
                   
    char **s_bits = malloc(8 * sizeof(char *));

    if(s_bits == NULL)
    {
        printf("Memory allocation failed in hexadecimal_to_bits program\n");
        return NULL;
    }

    for(int j = 0; j < 8; j++){
        for(int i = 0; i < 16; i++)
        {
            if(s_without0x[j] == hexadecimal_characters[i])
            {
                s_bits[j] = malloc(strlen(bits[i])+1); // Trying to allocate memory for string
                if(s_bits[j] == NULL)
                {
                    printf("Memory allocation failed in hexadecimal_to_bits\n When allocating memory for string");
                    return NULL;
                }
                strcpy(s_bits[j], bits[i]);
                break;
            }
        }
    }

    printf("My word in hexadecimal: %s\n", s_without0x);
    printf("Word in bits: ");
    for(int i = 0; i<8; i++)
    {
        printf("%s ", s_bits[i]);
    }
    
    printf("\n");
    
    free(s); // Free the allocated memory for s

    return s_bits;
}