#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include <iostream>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a, b;

	printf("Введите первое число: ");
	if (scanf("%d", &a) != 1)
	{
		printf("Ошибка ввода!\n");
		return 0;
	}

	printf("Введите второе число: ");
	if (scanf("%d", &b) != 1)
	{
		printf("Ошибка ввода!\n");
		return 0;
	}

	if (b == 0)
	{
		printf("Ошибка ввода! Второе число не может быть равно нулю!\n");
		return 0;
	}

	if (a % b)
	{
		printf("Число %d не кратно числу %d\n", a, b);
	}
	else
	{
		printf("Число %d кратно числу %d\n", a, b);
	}

	return 0;
}