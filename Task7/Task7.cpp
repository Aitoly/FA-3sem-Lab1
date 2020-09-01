#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include <iostream>

void PrintNum(int num)
{
	if (num > 9)
		PrintNum(num / 10);

	printf("%d ", num % 10);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int num;

	printf("¬ведите число от 1 до 10: ");
	if (scanf("%d", &num) != 1)
	{
		printf("ќшибка ввода!\n");
		return 0;
	}

	if (num < 1 || num > 10)
	{
		printf("ќшибка ввода!\n");
		return 0;
	}

	for (int i = 1; i < 11; ++i)
	{
		int pow = i;
		printf("%d : ", i);
		for (int j = 1; j < num + 1; ++j)
		{
			printf("%d ", pow);
			pow *= i;
		}
		printf("\n");
	}

	return 0;
}