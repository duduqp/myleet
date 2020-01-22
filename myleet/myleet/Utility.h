#pragma once
#include <cmath>
#include <vector>
using namespace std;
/*void matrix_gen(int col, int row, int *a)
{
	int rand_count = rand() % (col*row);
	for (int i = 0; i < rand_count; ++i)
	{
		int col_n = rand() % col;
		int row_n = rand() % row;
		*(a + col * row_n + col_n) = 1;
	}
}
*/
template<typename T>
int last_equal(const T & target,const vector<T> & container)
{
	int l = 0;
	int r = container.size();
	int mid = 0;
	while (l < r)
	{
		mid = l + (r - l) >> 1;
		if (container[mid] > target)
		{
			r = mid;
		}
		else {
			l = mid+1;
		}

	}
	return r - 1;

}

template<typename T>
int last_less(const T & target, const vector<T> & container)
{
	int l = 0;
	int r = container.size()-1;
	int mid = 0;
	while (l < r)
	{
		mid = l + (r - l) >> 1;
		if (container[mid] >= target)
		{
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	return l-1;

}



