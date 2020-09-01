#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include <iostream>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int num;

	printf("Введите число (num > 0): ");
	if (scanf("%d", &num) != 1)
	{
		printf("Ошибка ввода!\n");
		return 0;
	}

	if (num < 1)
	{
		printf("Ошибка ввода!\n");
		return 0;
	}

	int output = 0;

	for (int i = 1; i < num + 1; ++i)
	{
		output += i;
	}

	printf("%d\n", output);

	return 0;
}