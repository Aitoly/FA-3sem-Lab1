#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include <iostream>
#include <ctype.h>

int main(int argc, char** argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (argc == 1)
	{
		printf("�� ���������� ��������� ���������� ������!\n");
		return 0;
	}

	FILE* in, * out;

	in = fopen(argv[1], "r");
	if (!in)
	{
		printf("�� ���� ������� ���� %s\n", argv[1]);
		return 0;
	}

	out = fopen("out.txt", "w");
	if (!out)
	{
		printf("�� ���� ������� ���� out.txt\n");
		fclose(in);
		return 0;
	}

	char c;

	int numberOfString = 1, countOfSymbols = 0;

	while (!feof(in))
	{
		c = getc(in);

		if (!isdigit(c) && !isalpha(c) && !isspace(c))
			countOfSymbols++;

		if (c == '\n')
		{
			fprintf(out, "������ �����: %d, ���������� ������� ��������: %d\n", numberOfString, countOfSymbols);
			countOfSymbols = 0;
			numberOfString++;
		}
	}

	if (countOfSymbols > 0)
	{
		fprintf(out, "������ �����: %d, ���������� ������� ��������: %d\n", numberOfString, countOfSymbols);
	}

	fclose(in);
	fclose(out);

	printf("�������\n");
	return 0;
}