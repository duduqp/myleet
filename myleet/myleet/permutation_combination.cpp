#include "pch.h"
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <bitset>
#include <limits>
#include <cmath>
using namespace std;
template <typename T>
vector<vector<T>>  subset(const vector<T> & total)
{
	vector<vector<T> > ret;
	const int n = total.size();
	bitset<numeric_limits<unsigned long>::digits> mp(pow(2,n));
	vector<T> cur;
	cout << mp << endl;
	for (long i = 0; i < mp.to_ulong(); ++i)
	{
		
		bitset<numeric_limits<unsigned long>::digits> tmp(i);
		cout << tmp << "\n";
		for (int j = 0; j < n; ++j)
		{
			if (tmp.test(j))
			{
				cur.push_back(total[j]);
			}
		}
		ret.push_back(cur);
		cur.clear();
	}

	return ret;
}

vector<bitset<8>> graycode()
{
	vector<bitset<8> > ret{bitset<8>("00000000"),bitset<8>("00000001")};
	for (int i = 1; i < 8; i++)
	{
		int c = ret.size();
		
			for (int j = c - 1; j >= 0; --j)
			{
				bitset<8> tmp(ret[j]);
				tmp.set(i);
				ret.push_back(tmp);
			}
		
		cout << " now on i : " << i << endl;
		for_each(ret.begin(), ret.end(), [](const bitset<8> & b) { cout << b << "\n"; });
	}

	return ret;
}

//template<typename T>
//vector<vector<T> >  partition(const vector<T> & v)
//{
//	vector<int> sets(v.size(),1);// v[0] 属于 sets[0] 集合 从 1 开始标号
//	vector<int> maxset(v.size(),2);//maxset[i]表示 v[0 1 2 ... i]最多可以分割成了多少个集合
//	//初始化所有元素属于集合1  sets[i] = 1  ,  所有i可以另外单独成一个集合 所以 maxset[i] = 2
//
//
//
//
//}

void n_queue(vector<vector<string> > & ret, vector<int> & cur, int index, int n, vector<bool> & filled);
vector<vector<string> > n_puzzle(int n)
{
	vector<int> cur(n, -1);
	vector<bool> filled(n, false);
	vector<vector<string> > ret;
	n_queue(ret, cur, 0, n, filled);
	return ret;
}

void n_queue(vector<vector<string> > & ret, vector<int> & cur, int index,int n,vector<bool> & filled)
{
	if (index == n)
	{
		vector<string> tmp(n, string(n, '.'));
		for (int i = 0; i < n; ++i)
		{
			tmp[i][cur[i]] = 'Q';
		}
		ret.push_back(tmp);
	}
	else {
		for (int i = 0; i < n; ++i)
		{
			if (!filled[i])
			{
				bool flag = true;
				for (int j = index-1; j >= 0; --j)
				{
					if (abs(j - index) == abs(cur[j]-i))
					{
						flag = false;
						break;
					}
				}
				if (flag)
				{
					//can fill
					cur[index] = i;
					filled[i] = true;
					n_queue(ret, cur, index + 1, n, filled);
					cur[index] = -1;
					filled[i] = false;
				}
			}
		}
	}




}

void traval_round(const vector<vector<int> > & mat,vector<int> & ret, int lx, int ly, int rx, int ry)
{
	if (lx == rx)
	{
		while (ly <= ry)
		{
			ret.push_back(mat[lx][ly++]);
		}
	}
	else if (ly == ry)
	{
		while (lx <= rx)
		{
			ret.push_back(mat[lx++][ly]);
		}
	}
	else {
		int i = ly;
		for (; i <= ry; ++i)
		{
			ret.push_back(mat[lx][i]);
		}

		i = lx+1;
		for (; i <= rx; ++i)
		{
			ret.push_back(mat[i][ry]);
		}

		i = ry-1;
		for (; i >= ly; --i)
		{
			ret.push_back(mat[rx][i]);
		}

		i = rx-1;
		for (; i >= lx+1; --i)
		{
			ret.push_back(mat[i][ly]);
		}
	}
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> ret;
	if (matrix.empty())
	{
		return ret;
	}
	int row = matrix.size()-1;
	int col = matrix[0].size()-1;
	int lx = 0, ly = 0;
	int rx = row, ry = col;
	while (lx <= rx && ly <= ry)
	{
		traval_round(matrix, ret, lx, ly, rx, ry);
			lx++;
			rx--;
			ly++;
			ry--;
	}
	return ret;
}


bool canJump(vector<int>& nums) {
	if (nums[0] == 0)
	{
		return false;
	}
	int rightmost = 0;
	int i = 0;
	while (i >= 0 && i < nums.size() - 1)
	{
		if (i + nums[i] > rightmost)
		{
			rightmost = i + nums[i];
			if (rightmost >= nums.size() - 1)
			{
				return true;
			}
			i = rightmost;
			continue;
		}

		i--;
	}
	if (i<(nums.size() - 1))
	{
		return false;
	}
	/*if (std::less<int>()(i,(nums.size() - 1)))
	{
		return false;
	}*/
	return true;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	return {};
}

string GetPermutation(int n, int k) {

	vector<int> product(n, 1);
	vector<bool> digits(n, false);
	string ret;
	int i = 1;
	for (; i < n; i++)
	{
		product[i] = product[i - 1] * (i + 1);
	}
	if (k > product[n - 1])
	{
		return ret;
	}
	i = n - 1;
	int j = 0;
	int m = 0;
	while (i >= 0 && k)
	{
		i--;
		m = 0;
		int rank = ((k - 1) / product[i]) + 1;
		k = k % product[i];
		for (j = 0; j < n; ++j)
		{
			if (!digits[j])
			{
				m++;
			}
			if (m == rank)
			{
				break;
			}
		}

		ret.push_back(j + 1 + '0');
		digits[j] = true;
	}

	if (k == 0 && (ret.size() < n))
	{
		for (int j = n - 1; (ret.size() < n)&&j >= 0; j--)
		{
			if (!digits[j])
			{
				ret.push_back(j + 1 + '0');
			}
		}
	}
	return ret;
}
int main(void)
{
	/*vector<int> t{ 1,2,3,4,5,6,7 };
	auto ret = subset(t);
	for (const auto  & row : ret)
	{
		for (const auto & e : row)
		{
			cout << e << " ";
		}
		cout << "s\n";
	}
	cout.flush();*/
	/*vector<vector<int> > mat{ {1},{2},{3},{4} };
	auto ret = spiralOrder(mat);
	for (const auto & e : ret)
	{
		cout << e << " ";
	}
	cout << endl;*/
	/*auto ret= n_puzzle(4);
	for (const auto & row : ret)
	{
		for (const auto & s : row)
		{
			cout << s << "\n";
		}
		cout << endl;
	}*/
	//auto it = graycode();
	vector<int> nums{ 3,2,1,0,5 };
	//cout << canJump(nums);
	GetPermutation(3, 4);
	return 0;
}



