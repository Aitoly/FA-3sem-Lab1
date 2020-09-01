#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>
#include <ctime>

#define SIZE_A 20
#define SIZE_B 15

struct Element
{
	int val;
	int i;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(0));

	int arr_A[SIZE_A];
	int arr_B[SIZE_B];
	int arr_C[SIZE_A];

	struct Element nearest = { INT_MAX, 0 };

	printf("Исходный массив A: ");
	for (int i = 0; i < SIZE_A; ++i)
	{
		arr_A[i] = rand() % 100;

		printf("%d ", arr_A[i]);
	}
	printf("\n");

	printf("Исходный массив B: ");
	for (int i = 0; i < SIZE_B; ++i)
	{
		arr_B[i] = rand() % 100;

		printf("%d ", arr_B[i]);
	}
	printf("\n");

	printf("Mассив C: ");
	for (int i = 0; i < SIZE_A; ++i)
	{
		int plus = arr_B[0];
		int dist = INT_MAX;
		for (int j = 0; j < SIZE_B; ++j)
		{
			if (abs(arr_A[i] - arr_B[j]) < dist)
			{
				dist = abs(arr_A[i] - arr_B[j]);
				plus = arr_B[j];
			}
		}

		arr_C[i] = arr_A[i]+ plus;

		printf("%d ", arr_C[i]);
	}
	printf("\n");
}