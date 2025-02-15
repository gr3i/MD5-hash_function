/*
    Made by: Blixyk

    Program for converting decimals to hexadecimal numbers

    I needed to create this program for MD5 hash function

*/

#include <stdio.h>
//#include <stdbool.h>
#include <stdlib.h>

// function for reverse the order in array
void reverse_array(int arr[], int size)
{
    int left = 0, right = size - 1;

    while(left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

int decimal_to_hexadecimal(int decimal, char* result_array)
{

    // hexadecimal characters
    char hexadecimal_characters[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};


    // need required_size to know how big will be my array
    // f.e. decimal = 20, I will need array which can hold two numbers/characters --> _ _ or [0][1]
    int required_size = decimal;
    int size = 0;

    while(required_size > 0)
    {
        required_size /= 16;
        size++; // this tell me, how many characters will my hexadecimal number have
    }

    // dynamically allocate memory for hexadecimal array
    int *hexadecimal = (int *) malloc(size * sizeof(int));
    //char *result_array = (char *) malloc(size * sizeof(char));

    if(hexadecimal == NULL)
    {
        printf("Something went wrong when allocating memory.\n");
        return 1;
    }

    int remainder = 0;
    int quotient = decimal;
    int i = 0;

    // convert decimal to hexadecimal
    do{
        remainder = quotient % 16;
        quotient = quotient / 16;
        
        hexadecimal[i] = remainder;
        //printf("Note: %d\n", hexadecimal[i]);
        i++; 
        

    }while(quotient != 0);
    
    // reverse the order of elements -> The first one have to be last etc.
    reverse_array(hexadecimal, size);


    // convert numbers to hexadecimal characters -> Need to use my array "hexadecimal_characters"
    for (int i = 0; i < size; i++) {
        result_array[i] = hexadecimal_characters[hexadecimal[i]];
    }

    printf("Input: %d\n", decimal);
    printf("Output in hexadecimal: 0x");   //0x for meaning that it is hexadecimal number
    for (int i = 0; i < size; i++) {
        printf("%c", result_array[i]);
    }
    printf("\n");

    // free memory
    free(hexadecimal);
    //free(result_array);
    
    return size;
}