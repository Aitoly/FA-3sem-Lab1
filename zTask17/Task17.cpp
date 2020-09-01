#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define ISGOOD(x) (isalnum(x))

int val(char c)
{
    if (c >= '0' && c <= '9') return (int)c - '0';
    else return (int)c - 'A' + 10;
}

int toTen(char *str, int base)
{
    int len = strlen(str), power = 1, num = 0, i;
    for (i = len - 1; i >= 0; i--)
    {
        if (val(str[i]) >= base) return -1;
        num += val(str[i]) * power;
        power = power * base;
    }
    return num;
}

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FILE *in = NULL, * out = NULL;
    if ((in = fopen("in.txt", "r")) == NULL) perror("in.txt");
    if ((out = fopen("out.txt", "w")) == NULL) perror("out.txt");
    char buf[BUFSIZ] = {}, *ptr = buf;
    int max = 0, sch = 0, NM;
    while (!feof(in))
    {
        fscanf(in, "%s", buf);
        ptr = buf;
        while (isalnum(*ptr))
        {
            *ptr = toupper(*ptr);
            sch = (isdigit(*ptr) ? (int)*ptr - '0' : (int)*ptr - 'A' + 10);
            if (sch > max) max = sch;
            ptr++;
        }
        ptr = buf;
        NM = toTen(ptr, max + 1);
        printf("Минимальная система счисления для числа %s: %d. ", ptr, max + 1);
        printf("Это число в дестяричной системе: %d\n", NM);

        fprintf(out, "Минимальная система счисления для числа %s: %d. ", ptr, max + 1);
        fprintf(out, "Это число в дестяричной системе: %d\n", NM);
    }
    fclose(in); fclose(out);
    return 0;
}
