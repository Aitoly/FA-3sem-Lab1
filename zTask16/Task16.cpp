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

    char word[BUFSIZ];
    int index = 1;
    char* ptr = word;

    char c = ' ';
    c = getc(in);

    while (!feof(in))
    {
        if (isspace(c))
        {
            *ptr = '\0';
            
            if (index % 2 == 0)
            {
                for (int i = 0; i < strlen(word); ++i)
                    word[i] = tolower(word[i]);
            }

            if(index % 5 == 0)
            {
                for(int i = 0; i < strlen(word); ++i)
                    fprintf(out, "%d", word[i]);

                if (c == '\n')
                    fprintf(out, "\n", word);
                else
                    fprintf(out, " ", word);

                ptr = word;
                *ptr = '\0';
            }
            else
            {
                if (c == '\n')
                    fprintf(out, "%s\n", word);
                else
                    fprintf(out, "%s ", word);

                ptr = word;
                *ptr = '\0';
            }

            index++;

            c = getc(in);
        }
        else
        {
            *ptr = c;
            ++ptr;
            c = getc(in);
        }
    }

    if (strlen(word) > 0)
    {
        if (index % 2 == 0)
        {
            for (int i = 0; i < strlen(word); ++i)
                word[i] = tolower(word[i]);
        }

        if (index % 5 == 0)
        {
            for (int i = 0; i < strlen(word); ++i)
                fprintf(out, "%d", word[i]);

            if (c == '\n')
                fprintf(out, "\n", word);
            else
                fprintf(out, " ", word);

            ptr = word;
            *ptr = '\0';
        }
        else
        {
            if (c == '\n')
                fprintf(out, "%s\n", word);
            else
                fprintf(out, "%s ", word);

            ptr = word;
            *ptr = '\0';
        }
    }

    fclose(in);
    fclose(out);

    printf("Успешно\n");

    return 0;
}