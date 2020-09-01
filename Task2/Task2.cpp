#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include <iostream>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int num = 0;

	printf("������� �����, � ������� ����� ��������.\n");

	if (scanf("%d", &num) != 1)
	{
		printf("������ �����!\n");
		return 0;
	}

	if (!num)
	{
		printf("������ ����.\n");
		return 0;
	}

	num = abs(num);
	int sqrtNum = (int)sqrt(num);

	for (int i = 2; i <= sqrtNum; ++i)
	{
		if (num % i == 0)
		{
			printf("����� ��������!\n");
			return 0;
		}
	}

	printf("����� �������!\n");
	return 0;
}