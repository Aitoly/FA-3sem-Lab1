#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include <iostream>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a, b;

	printf("������� ������ �����: ");
	if (scanf("%d", &a) != 1)
	{
		printf("������ �����!\n");
		return 0;
	}

	printf("������� ������ �����: ");
	if (scanf("%d", &b) != 1)
	{
		printf("������ �����!\n");
		return 0;
	}

	if (b == 0)
	{
		printf("������ �����! ������ ����� �� ����� ���� ����� ����!\n");
		return 0;
	}

	if (a % b)
	{
		printf("����� %d �� ������ ����� %d\n", a, b);
	}
	else
	{
		printf("����� %d ������ ����� %d\n", a, b);
	}

	return 0;
}