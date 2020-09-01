#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include <iostream>
#include <ctype.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE* in, * out;

	in = fopen("in.txt", "r");
	if (!in)
	{
		printf("Не могу открыть файл in.txt\n");
		return 0;
	}

	out = fopen("out.txt", "w");
	if (!out)
	{
		printf("Не могу открыть файл out.txt\n");
		fclose(in);
		return 0;
	}

	char c;
	c = getc(in);

	while (!feof(in))
	{
		if (!isdigit(c))
			putc(c, out);

		c = getc(in);
	}

	fclose(in);
	fclose(out);

	printf("Успешно\n");
	return 0;
}