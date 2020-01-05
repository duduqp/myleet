#include "pch.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "Utility.h"
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
int main()
{
// 	string s(5, ' ');
// 	binary_string(0, s);
// 	k_string(0, s, 3);
	int mat[10][10]{ 0 };
	vector<int> chioces{ 1,0};
	gen_matrix(chioces,mat, 10);
	print_matrix(mat, 10, 10);
	return 0;
}

