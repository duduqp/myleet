#pragma once
#include <cmath>

extern void matrix_gen(int col, int row, int *a)
{
	int rand_count = rand() % (col*row);
	for (int i = 0; i < rand_count; ++i)
	{
		int col_n = rand() % col;
		int row_n = rand() % row;
		*(a + col * row_n + col_n) = 1;
	}
}