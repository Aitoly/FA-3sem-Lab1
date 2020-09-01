#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include <iostream>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a, b, c;

	printf("Введите первую сторону треугольника: ");
	if (scanf("%d", &a) != 1)
	{
		printf("Ошибка ввода!\n");
		return 0;
	}

	printf("Введите вторую сторону треугольника: ");
	if (scanf("%d", &b) != 1)
	{
		printf("Ошибка ввода!\n");
		return 0;
	}

	printf("Введите третью сторону треугольника: ");
	if (scanf("%d", &c) != 1)
	{
		printf("Ошибка ввода!\n");
		return 0;
	}


	if (a + b > c)
	{
		printf("Такой треугольник существуюет!\n");
	}
	else if (a + c > b)
	{
		printf("Такой треугольник существуюет!\n");
	}
	else if (b + c > a)
	{
		printf("Такой треугольник существуюет!\n");
	}
	else
	{
		printf("Такой треугольник не существуюет!\n");
	}

	return 0;
}