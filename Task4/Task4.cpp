#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include <iostream>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a, b, c;

	printf("���������� ��������� : ax^2 + bx + c = 0\n");

	printf("������� a: ");
	if (scanf("%d", &a) != 1)
	{
		printf("������ �����!\n");
		return 0;
	}

	printf("������� b: ");
	if (scanf("%d", &b) != 1)
	{
		printf("������ �����!\n");
		return 0;
	}

	printf("������� c: ");
	if (scanf("%d", &c) != 1)
	{
		printf("������ �����!\n");
		return 0;
	}

	int dis = b * b - 4 * a * c;

	if (dis < 0)
	{
		printf("�������������� ������ ���!\n");
	}
	else if (dis == 0)
	{
		printf("���� ������ %f\n", (-1 * (float)b) / (2 * a));
	}
	else
	{
		printf("������ ������ %f\n", (-1 * (float)b + (float)sqrt(dis)) / (2 * a));
		printf("������ ������ %f\n", (-1 * (float)b - (float)sqrt(dis)) / (2 * a));
	}

	return 0;
}