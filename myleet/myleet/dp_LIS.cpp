#include "pch.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;
int longestValidParentheses(string s) {
	if (s.empty())
	{
		return 0;
	}
	int M = 0;
	vector<int> Max(s.size(), 0);
	
	int current = 0;
	int i = 0;
	while (s[i] == ')')
	{
		Max[i] = 0;
		i++;
	}
	int prefix = 0;
	int last_zero = 0;
	for (; i < s.size(); ++i)
	{
		if (s[i] == '(')
		{
			prefix++;
			Max[i] = i!=0?Max[i - 1]:0;
		}
		else {
			//c==')'
			if (prefix >= 1)
			{
				prefix--;
				current++;
				if (prefix == 0)
				{
					Max[i] = Max[i - 1] + 1;
					last_zero = i;
				}else {
					Max[i] = max(Max[i - 1], current - Max[last_zero]);
				}
				if (Max[i] > M)
				{
					M = Max[i];
				}
			}
			else
			{
				prefix = 0;
				current = 0;
				Max[i] = Max[i-1];
			}
		}
	}
	M = max(Max[i - 1], M);

	return M<<1;
}



bool test(const vector<vector<bool>> & m)
{
	bool flag = true;
	for (const auto & r : m)
	{
		for (const auto & e : r)
		{
			flag = (flag && e);
		}
	}
	return flag;
}

void fill_sudoku(const int & x, const int& y, vector<vector<char>> & board, vector<vector<vector<bool>>>& sq_choice, vector<vector<bool>>& r_choice
	, vector<vector<bool>>& c_choice, bool & flag)
{
	if (x > 8)
	{
		flag = true;
		return;
	}

	if (board[x][y] != '.')//unfillable
	{
		if (y < 8)
		{
			fill_sudoku(x, y + 1, board, sq_choice, r_choice, c_choice, flag);
		}
		else {
			fill_sudoku(x + 1, 0, board, sq_choice, r_choice, c_choice, flag);
		}
	}
	else {
		//fillable
		for (int i = 1; i <= 9; i++)
		{
			if (!r_choice[x][i - 1] && !c_choice[y][i - 1] && !sq_choice[x / 3][y / 3][i - 1])
			{
				board[x][y] = i + '0';
				r_choice[x][i - 1] = c_choice[y][i - 1] = sq_choice[x / 3][y / 3][i - 1] = true;
				if (y < 8)
				{
					fill_sudoku(x, y + 1, board, sq_choice, r_choice, c_choice, flag);
				}
				else {
					fill_sudoku(x + 1, y, board, sq_choice, r_choice, c_choice, flag);
				}
				if (!flag)
				{
					board[x][y] = '.';
					r_choice[x][i - 1] = c_choice[y][i - 1] = sq_choice[x / 3][y / 3][i - 1] = false;
				}
			}
		}
	}
}
void solveSudoku(vector<vector<char>>& board) {
	vector<vector<bool>> board_vis(9, vector<bool>(9, false));
	vector<vector<vector<bool>>> square_set(3, vector<vector<bool>>(3, vector<bool>(9,
		false)));//3*3*9
	vector<vector<bool>> row_set(9, vector<bool>(9,false));//9*9
	vector<vector<bool>> col_set(9, vector<bool>(9, false));
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9 ; ++j)
		{
			if (board[i][j] != '.')
			{
				int num = board[i][j] - '0'-1;//num = (1,2,3,4...9)-1
				square_set[i / 3][j / 3][num] = true;
				row_set[i][num] = col_set[j][num] = true;
			}
		}
	}
	bool flag = false;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (!flag)
			{
				fill_sudoku(i, j, board,square_set, row_set, col_set,flag );
			}
		}
	}


}


void print_2d_vec(const vector<vector<char> >& m)
{
	for (const auto & row : m)
	{
		for (const auto & e : row)
		{
			cout << e << " ";
		}
		cout << "\n";
	}
	cout.flush();
}
int main(void)
{
	//cout << longestValidParentheses('()(((())((((((()(()))');
	vector<vector<char> > m{ {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
	print_2d_vec(m);
	solveSudoku(m);
	print_2d_vec(m);
	return 0;
}