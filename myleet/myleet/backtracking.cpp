#include "pch.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "Utility.h"
#include <utility>
using namespace std;

void binary_string(int n,string & s)
{
	if (s.size()== n)
	{
		//reach end,recursive base
		cout << s << endl;
	}
	else {
		s[n] = '0';
		binary_string(n + 1, s);
		s[n] = '1';
		binary_string(n + 1, s);
	}
}

void k_string(int n, string & s,int k)
{
	if (n == s.size())
	{
		cout << s << endl;
	}
	else {
		for (int i = 0; i < k; i++)
		{
			s[n] = i + '0';
			k_string(n + 1, s,k);
		}
	}
}
template<typename T>
void gen_matrix(vector<T> chioce, T mat[][10], int edge)
{
	srand(3);
	for (int c = 0; c < rand() % (edge*edge); ++c) {
		int i = rand() % (edge-1);
		int j = rand() % (edge-1);
		int k = rand() % (chioce.size() - 1);
		mat[i][j] = chioce[k];
	}
}
template<typename T>
void print_matrix(T mat[][10], int row, int col)
{
	for (int i =0;i<row;i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << mat[i][j] << ends;
		}
		cout << endl;
	}


}

void blocks(int mat[][10],int row,int col,int x,int y,bool vis[][10],int current_size,int & max_size) {
	if (x >= row || y >= col || x < 0 || y < 0||vis[x][y])
	{
		return ;
	}

	//legal 
	vis[x][y] = true;
	if (mat[x][y] == 1) {
		if (current_size + 1 > max_size)
		{
			max_size = current_size + 1;
		}
		for (int i = -1; i < 2; ++i)
		{
			for (int j = -1; j < 2; ++j)
			{
				if(abs(i - j)==1)
				{
					blocks(mat, row, col, x + i, y + j, vis, current_size + 1, max_size);
				}
			}

		}
	}else {
		for (int i = -1; i < 2; ++i)
		{
			for (int j = -1; j < 2; ++j)
			{
				if ((abs(i - j) == 1))
				{
					blocks(mat, row, col, x + i, y + j, vis, 0, max_size);
				}
			}

		}
	}


}
//int main()
//{
//// 	string s(5, ' ');
//// 	binary_string(0, s);
//// 	k_string(0, s, 3);
//	int mat[10][10]{ 0 };
//	vector<int> chioces{ 1,0};
//	gen_matrix(chioces,mat, 10);
//	print_matrix(mat, 10, 10);
//	bool vis[10][10] = { false };
//	fill(vis[0], vis[0] + 100, false);
//	int max_size = 0;
//	blocks(mat, 10, 10, 0, 0, vis, 0, max_size);
//	cout << max_size << endl;
//	return 0;
//}

