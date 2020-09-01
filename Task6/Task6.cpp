#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include <iostream>

void PrintNum(int num)
{
	if(num > 9)
		PrintNum(num / 10);

	printf("%d ", num % 10);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int num;

	printf("Введите 7-значное число: ");
	if (scanf("%d", &num) != 1)
	{
		printf("Ошибка ввода!\n");
		return 0;
	}

	if (num < 1000000 || num > 9999999)
	{
		printf("Ошибка ввода! Число не семизначное!\n");
		return 0;
	}

	PrintNum(num);

	return 0;
}