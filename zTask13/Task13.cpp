#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>



int main(int argc, char** argv)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    if (argc == 1)
    {
        printf("Не достаточно аргуметов коммандной строки!\n");
        return 0;
    }

    FILE* in, * out;

    in = fopen(argv[1], "r");
    if (!in)
    {
        printf("Не могу открыть файл %s\n", argv[1]);
        return 0;
    }

    out = fopen("out.txt", "w");
    if (!out)
    {
        printf("Не могу открыть файл out.txt\n");
        fclose(in);
        return 0;
    }

    char word_1[BUFSIZ];
    char word_2[BUFSIZ];
    char word_3[BUFSIZ];
    int index = 1;
    char* ptr = word_1;

    char c = ' ';
    c = getc(in);

    while (!feof(in))
    {
        if (isspace(c))
        {
            *ptr = '\0';
            index++;
            if (index == 4)
            {
                index = 1;
                fprintf(out, "%s %s %s\n", word_3, word_1, word_2);
            }

            switch (index)
            {
            case 1: ptr = word_1; break;
            case 2: ptr = word_2; break;
            case 3: ptr = word_3; break;
            }

            c = getc(in);
        }
        else
        {
            *ptr = c;
            ++ptr;
            c = getc(in);
        }
    }

    if (index == 3)
    {
        *ptr = '\0';
        fprintf(out, "%s %s %s\n", word_3, word_1, word_2);
    }

    fclose(in);
    fclose(out);

    printf("Успешно\n");

    return 0;
}