#include "pch.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <utility>
using namespace std;

constexpr int MAX_N = 1e+5;

int max_rectangle_core(const vector<int > & height)
{
	//core routine to calcu max_rectangle area
	//using a auxiliary stack
	int current_max = 0;
	int max_rec = 0;
	stack<int> s;//store the index
	for (size_t i = 0; i < height.size(); ++i)
	{
		if (s.empty())
		{
			s.push(i);
		}
		else {
			while (!s.empty() && ((i == height.size() - 1) || height[i] < height[s.top()]))
			{
				int top = s.top();
				s.pop();
				int start = s.empty() ? -1 : s.top();
				current_max = (i - (start + 1)) * height[top];
				if (current_max > max_rec)
				{
					max_rec = current_max;
				}
			}
		}
	}
	return max_rec;
}
int max_rectangle(int mat[][MAX_N], int row = MAX_N, int col = MAX_N)
{
	vector<int > height(MAX_N, 0);
	int max_rectangle = 0;
	for (size_t i = 0; i < row; ++i)
	{
		for (size_t j = 0; j < col; j++)
		{
			//update height
			height.at(j) = mat[i][j] == 1 ? height.at(j) + 1 : height.at(j);
			//calcu max_rectangle

		}
	}

	return max_rectangle;
}

//int main()
//{
//	vector<int > v{ 3,4,5,6,4,3 };
//	std::cout << max_rectangle_core(v);
//
//
//}