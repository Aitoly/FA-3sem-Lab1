#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include <iostream>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a, b, c;

	printf("������� ������ ������� ������������: ");
	if (scanf("%d", &a) != 1)
	{
		printf("������ �����!\n");
		return 0;
	}

	printf("������� ������ ������� ������������: ");
	if (scanf("%d", &b) != 1)
	{
		printf("������ �����!\n");
		return 0;
	}

	printf("������� ������ ������� ������������: ");
	if (scanf("%d", &c) != 1)
	{
		printf("������ �����!\n");
		return 0;
	}


	if (a + b > c)
	{
		printf("����� ����������� �����������!\n");
	}
	else if (a + c > b)
	{
		printf("����� ����������� �����������!\n");
	}
	else if (b + c > a)
	{
		printf("����� ����������� �����������!\n");
	}
	else
	{
		printf("����� ����������� �� �����������!\n");
	}

	return 0;
}