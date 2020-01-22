#include "pch.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;
//void dfs(vector<vector<int>> &ret, vector<int>& cur, vector<int>& candidates, int target, int index);

/*vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> ret;
	if (candidates.empty())
	{
		return ret;
	}
	sort(candidates.begin(), candidates.end());
	if (target < candidates[0])
	{
		return ret;
	}

	candidates.erase(remove_if(candidates.begin(), candidates.end(), [target](const int & i)
	{
		return i > target;
	}), candidates.end());

	//dfs
	vector<int > cur;
	std::cout << candidates.size() << std::endl;
	dfs(ret, cur, candidates, target, candidates.size() - 1);


	return ret;
}
*/
/*
void dfs(vector<vector<int>> &ret, vector<int>& cur, vector<int>& candidates, int target, int index)
{
	if (target < 0)
	{
		return;
	}

	if (target == 0)
	{
		ret.push_back(cur);
		return;
	}

	if (index >= 0)
	{
		cur.push_back(candidates[index]);
		dfs(ret, cur, candidates, target - candidates[index], index - 1);
		cur.pop_back();
		dfs(ret, cur, candidates, target, index - 1);
	}

}
*/
bool dfs_b(const vector<vector<char> > & board, const int & x, const int & y, bool *vis[], const int& m, const int& n, const string & word, const pair<int, int> * dir, int k);
bool exist(vector<vector<char>>& board, string word) {
	if (word.empty())
	{
		return false;
	}



	int m = board.size();
	int n = board[0].size();
	bool **vis = new bool*[m];
	for (int i = 0; i < m; ++i)
	{
		vis[i] = new bool[n];
		fill(vis[i], vis[i] + n, false);
	}

	
	int i, j;
	bool havenomatch = true;
	vector<pair<int, int> > start;
	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			if (board[i][j] == word[0])
			{
				vis[i][j] = true;
				havenomatch = false;
				start.push_back(make_pair(i, j));
			}
		}
	}
	if (havenomatch)
	{
		return false;
	}

	pair<int, int> dir[4] = { pair<int,int>(-1,0),pair<int,int>(1,0),pair<int,int>(0,-1),pair<int,int>(0,1) };
	for (const auto &p : start)
	{
		int k = 0;//from word[0 ... size-1]
		if (dfs_b(board, p.first, p.second, vis, m, n, word, dir, k))
		{
			return true;
		}
	}
	return false;
}

bool dfs_b(const vector<vector<char> > & board, const int & x, const int & y, bool *vis[], const int& m, const int& n, const string & word, const pair<int, int> * dir, int k)
{
	if (k > word.size())
	{
		return false;
	}

	if (board[x][y] != word[k])
	{
		return false;
	}
	else {
		//board[x][y]==word[k-1]
		k++;
		vis[x][y] = true;
		if (k == word.size())
		{
			return true;
		}
		else {
			for (int l = 0; l < 4; l++)
			{
				int nextx = x + dir[l].first;
				int nexty = y + dir[l].second;
				
				if ((nextx >= 0) && (nextx <= (m - 1)) && (nexty >= 0) && (nexty <= (n - 1)))
				{
					std::cout << vis[nextx][nexty] << std::endl;
					if (!vis[nextx][nexty] && dfs_b(board, nextx, nexty, vis, m, n, word, dir, k))
					{
						return true;
					}
				}
			}
		}
		vis[x][y] = false;
	}
	return false;
}
int main(void)
{
	vector<vector<char>> board{
		{'A','B','C','E' },
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'}
	};
	exist(board, "ABCCED");
	//combinationSum2(vec, 8);
	return 0;
}