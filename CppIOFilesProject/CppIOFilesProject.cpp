#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

void FileText();

int main()
{
    //FILE* bfile = fopen("file_01.bin", "wb");
    FILE* bfile = fopen("file_01.bin", "rb");

    long long number;
    //fwrite(&number, sizeof(number), 1, bfile);

    /*int array[]{ 65, 66, 67, 68, 69, 70 };
    fwrite(array, sizeof(array[0]), sizeof(array) / sizeof(array[0]), bfile);

    char str[] = "Hello world";
    fwrite(str, sizeof(char), strlen(str), bfile);*/

    /*char symbol;

    fread(&symbol, sizeof(char), 1, bfile);
    std::cout << symbol << "\n";*/

    fclose(bfile);
}

void FileText()
{
    //FILE* file = fopen("file01.dat", "w");
    //FILE* file = fopen("file01.dat", "r");
    FILE* file = fopen("file01.dat", "r+");

    if (!file)
    {
        std::cout << "error\n";
        return;
    }

    /*fputc('$', file);
    fputs("\nHello world", file);*/

    /*char symbol = fgetc(file);
    std::cout << symbol << "\n";

    int size{ 2024 };
    char* str{ new char[size] };

    while (fgets(str, size, file) != nullptr)
        std::cout << str;*/

        //fputs("\n\nAppend string", file);

    char* buffer = new char[1024];
    fseek(file, 5, SEEK_SET);
    int position = ftell(file);

    char str_insert[] = "*****";

    fgets(buffer, sizeof(buffer), file);

    fseek(file, position, SEEK_SET);

    fputs(str_insert, file);
    fputs(buffer, file);

    fclose(file);
}
