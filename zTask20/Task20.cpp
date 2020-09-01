/*20. Пользователь вводит систему счисления и затем числа в этой системе счисления.
Окончанием ввода является ввод слова Stop.
Найдите среди введенных чисел максимальное.
Переведите найденное максимальное число в 9, 18, 27 и 36-ые системы счисления.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char Scale[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int dig2int(char d)
{
    int i;
    for (i = 0; i < 36; i++)
        if (Scale[i] == d)
            return i;
    return -1;
}

char* IToA_(int from)
{
    int from_ = from;
    int size = 0;
    while (from_ > 0)
    {
        from_ /= 10;
        ++size;
    }

    char* to = (char*)malloc((size + 1) * sizeof(char));
    to[size] = '\0';

    for (int i = size - 1; i > -1; ++i)
    {
        to[size] = from % 10;
        from /= 10;
    }

    return to;
}

char* convert(char* n, int from, int to)
{
    int i, j, l, p, k;
    char* buf;
    l = strlen(n);
    p = 0;
    for (i = 0; i < l; i++) p = p * from + dig2int(n[i]);
    buf = (char*)calloc(100, 1);
    k = 99; l = 0;
    while (1)
    {
        j = p % to;
        buf[k--] = Scale[j];
        l++;
        p = p / to;
        if (p == 0) break;
    }
    j = 0;
    k++;
    while (1)
    {
        buf[j++] = buf[k++];
        if (k == 100) break;
    }
    return buf;
    free(buf);
}

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int base = -1;
    char* num, buf[BUFSIZ];
    int arr[MAX], i = 0, len;
    while (base > 36 || base < 0)
    {
        printf("System: ");
        scanf("%d", &base);
    }
    printf("Number: ");
    scanf("%s", buf);
    while (strcmp(buf, "stop") != 0)
    {
        num = (char*)malloc(sizeof(char) * (strlen(buf) + 1));
        num = convert(buf, base, 10);
        printf("in 10 : %s\n", num);
        len = strlen(num) + 1;
        arr[i] = atoi(num);
        i++;
        free(num);
        printf("Number: ");
        scanf("%s", buf);
    }
    int max = arr[0], kol = i;
    for (i = 0; i < kol; i++)
        if (arr[i] > max) max = arr[i];
    printf("Maximal is %d\n", max);
    char* string = NULL;
    string = IToA_(max);
    for (i = 9; i <= 36; i += 9) 
        printf("%d(10) = %s(%d)\n", max, convert(string, 10, i), i);
    free(string);
    return 0;
}
