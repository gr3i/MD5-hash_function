#include <stdio.h>
#include <stdlib.h>

int decimal_to_hexadecimal(int decimal, char *result_array);

void process_result(char *result_array, int size)
{
    // Just an example of processing - you can modify this function to do what you need
    printf("Processing result: ");
    for (int i = 0; i < size; i++) {
        printf("%c", result_array[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[])
{

    if(argc < 2)
    {
        printf("You need to write number after file name. Example: ./your_file 300 \n");
        return 1;
    }

    int decimal = atoi(argv[1]);

    if(decimal <= 0)
    {
        printf("Enter positive number.\n");
        return 1;
    }

    int max_size = 10;
    char result_array[max_size];

    int size = decimal_to_hexadecimal(decimal, result_array);

    printf("Hexadecimal: ");
    for(int i = 0; i < size; i++)
    {
        printf("%c", result_array[i]);
    }

    printf("\n");

    process_result(result_array, size);

    return 0;
}