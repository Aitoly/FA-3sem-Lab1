#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>



int main(int argc, char** argv)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    if (argc < 3)
    {
        printf("Не достаточно аргуметов коммандной строки!\n");
        return 0;
    }

    FILE* in1, *in2, * out;

    in1 = fopen(argv[1], "r");
    if (!in1)
    {
        printf("Не могу открыть файл %s\n", argv[1]);
        return 0;
    }

    in2 = fopen(argv[2], "r");
    if (!in2)
    {
        printf("Не могу открыть файл %s\n", argv[2]);
        return 0;
    }

    out = fopen("out.txt", "w");
    if (!out)
    {
        printf("Не могу открыть файл out.txt\n");
        fclose(in1);
        fclose(in2);
        return 0;
    }

    char word[BUFSIZ];
    bool index_1 = true;
    char* ptr = word;

    bool end_1 = true;
    bool end_2 = true;

    char c = ' ';

    while (end_1 || end_2)
    {
        if (index_1)
        {
            c = getc(in1);
        }
        else
        {
            c = getc(in2);
        }

        if (isspace(c))
        {
            *ptr = '\0';
            if(end_1 && end_2)
                index_1 = !index_1;
            fprintf(out, "%s ", word);
            ptr = word;
            *ptr = '\0';
        }
        else if (c == EOF)
        {
            *ptr = '\0';
            
            if (index_1)
                end_1 = false;
            else 
                end_2 = false;

            index_1 = !index_1;
            fprintf(out, "%s ", word);
            ptr = word;
            *ptr = '\0';
        }
        else
        {
            *ptr = c;
            ++ptr;
        }
    }

    fprintf(out, "%s ", word);

    fclose(in1);
    fclose(in2);
    fclose(out);

    printf("Успешно\n");

    return 0;
}