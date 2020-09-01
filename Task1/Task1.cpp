#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include <iostream>
#include<ctype.h>

bool isNum(char* str)
{
	if (!str)
		return false;

	int size = strlen(str);
	for (int i = 0; i < size; ++i)
	{
		if (!isdigit(*str))
			return false;

		++str;
	}

	return true;
}

int main(int argc, char** argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (argc == 1)
	{
		printf("�� ���������� ��������� ���������� ������!\n");
		return 0;
	}

	if (!isNum(argv[1]))
	{
		printf("�� �������� �� �����!\n");
		return 0;
	}

	int num = atoi(argv[1]);
	int num_ = 0;

	if (!num || num > 100)
	{
		printf("�� ���� ����� ����� � �������� 100, ������� ����������!\n");
		return 0;
	}

	num_ = abs(num);

	do
	{
		printf("%d ", num);
		num += num_;
	} while (num <= 100);

	return 0;
}