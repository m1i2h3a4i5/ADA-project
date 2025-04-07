#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define ASCII 256
#define DEBUG 1

typedef struct freqency
{
    int count;
    char character;
}frequency;

void parse(FILE* input, frequency frequency_check[])
{
    int aux_char;
    while((aux_char = fgetc(input)) != EOF)
    {
        frequency_check[(unsigned char)aux_char].count++;
    }
}


void compress(FILE* compression_file)
{
    frequency frequency_check[ASCII];

    for(int i = 0; i < ASCII; i ++)
    {
        frequency_check[i].character = (char)i; //typecast ca sa l faca ascii
        frequency_check[i].count = 0;
    }

    parse(compression_file, frequency_check);

#if DEBUG
for (int i = 0; i < ASCII; i++)
{
    if (isprint(frequency_check[i].character) != 0) { //la facut debugging in afisare daca nu folosesc isprint imi da aiurea 

        printf("%c appears %d times\n", frequency_check[i].character, frequency_check[i].count);
    } 
    else {

        printf("ASCII %d appears %d times\n", i, frequency_check[i].count);
    }
}
#endif
}

void decompress(FILE* decompression_file)
{

}

int main (int argc, char *argv[])
{
    if(argc != 3) //m-am gandit ca inputul va fi de forma prog.exe <input_file> <action type>
    {
        perror("Invalid number of arguments: prog.exe <input_file> <action_type>; For action type, input c for compression or d for decompression");
        exit(EXIT_FAILURE);
    }

    FILE* input_file  = fopen(argv[1], "r");

    if(input_file == NULL)
    {
        perror("Error encountered while opening the input file");
        exit(EXIT_FAILURE);
    }

    if(strcmp(argv[2], "c") == 0)
    {
        compress(input_file);
    }

    else if(strcmp(argv[2], "d") == 0)
    {
        decompress(input_file);
    }

    return 0;
}