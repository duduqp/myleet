#include "pch.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;
typedef vector<vector<int> > MAT;
template<typename T>
void print_vec(vector<T> vec, std::function<void(T)> vis)
{
	for_each(vec.begin(), vec.end(), vis);
}

MAT mat_mult(const MAT& m1, const MAT & m2)
{
	MAT ret(m1.size(),vector<int>(m1.size()));
	for (int i = 0; i < m1.size(); ++i)
	{
		for (int j = 0; j < m1.size(); ++j)
		{
			for (int k = 0; k < m1.size(); ++k)
			{
				ret[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	return ret;
}

void print_mat(const MAT &mat)
{
	for (const auto & r : mat)
	{
		for (const auto & e : r)
		{
			cout << e << " ";
		}
		cout << "\n";
	}
	cout.flush();
}
void print_2d(int *m[],int n)
{

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << m[i][j] << " ";
		}
		cout << "\n";
	}
	cout.flush();
}
MAT mat_power(MAT m, int exp)
{
	MAT ret(m.size(),vector<int>(m.size(),0));
	for (int i = m.size(); i > 0; --i)
	{
		ret[i-1][i-1] = 1;
	}

	while (exp)
	{
		if (exp & 1)
		{
			ret = mat_mult(ret, m);
		}
		m = mat_mult(m, m);
		exp >>= 1;
	}
	return ret;
}
struct vis_pair {
	void operator()(const pair<int,int> & p) const {
		cout << p.first<< p.second<<" ";
	}
};

pair<vector<pair<int, int>>, int> min_path(const MAT & m)
{
	vector<pair<int, int>> path;
	int ret;
	int sz = m.size();
	//dp-a
	//init
	/*auto dp = new int*[sz];
	for (int i =0;i<sz;++i)
	{
		dp[i] = new int[sz]{0};
	}
	dp[0][0] = m[0][0];
	for (int i = 1; i < sz; ++i)
	{
		dp[0][i] = dp[0][i - 1] + m[0][i];
		dp[i][0] = dp[i-1][0] + m[i][0];
	}*/
	path.push_back({ 0,0 });
	/*for (int i = 1; i < sz; ++i)
	{
		for (int j = 1; j<sz; ++j)
		{
			if (dp[i - 1][j] < dp[i][j - 1])
			{
				path.push_back({ i - 1,j });
			}
			else {
				path.push_back({ i,j-1 });
			}
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + m[i][j];
		}
	}
	path.push_back({ sz - 1,sz - 1 });
	ret = dp[sz - 1][sz - 1];
	print_2d(dp, sz);*/

	//dp-b
	//compact space
	//init
	//int * dp = new int[sz] { 0 };
	vector<int> dp(sz, 0);
	for (int i = 0; i < sz ; i++)
	{
		dp[i] = m[0][i];
	}

	auto vis_1d = [](int i) {cout << i << " "; };
	for (int i = 0; i < sz; ++i)
	{
		for (int j = 0; j < sz; ++j)
		{
			if (j == 0)
			{
				dp[j] = dp[j] + m[i][j];
			}
			else {
				if (dp[j - 1] < dp[j])
				{
					path.push_back({ i,j - 1 });
				}
				else {
					path.push_back({ i,j - 1 });
				}
				dp[j] = min(dp[j - 1] + m[i][j], dp[j] + m[i][j]);
			}
		}
		print_vec<int>(dp, vis_1d);
		cout << endl;
	}
	ret = dp[sz - 1];
	path.push_back({ sz - 1,sz - 1 });
	//auto vis = vis_pair();
	auto vis = [](pair<int, int>  p) { cout << p.first << p.second << " "; };
	print_vec<pair<int,int> >(path, vis);
	return { path,ret };
}

//integer programming
int min_change(vector<int> quota, int target)
{
	//dp-a
	//init
	sort(quota.begin(), quota.end());
	if (quota[0] >= target)
	{
		return target/quota[0];
	}
	int sz = quota.size();
	//vector<vector<int> > dp(sz, vector<int>(target+1, 0));
	//for (int i = 0; i < target+1; ++i)
	//{
	//	if (i != quota[0])
	//	{
	//		dp[0][i] = INT_MAX;
	//	}
	//	else {
	//		dp[0][i] = 1;
	//	}
	//}

	//for (int i = 0; i < sz; ++i)
	//{
	//	dp[i][0] = 0;
	//}
	//
	//for (int i= 0; i < sz; i++)//by row!!!
	//{
	//	for (int j = 0; j < target+1; ++j) {
	//		if (j - quota[i] >= 0 && dp[i][j - quota[i]] != INT_MAX)
	//		{
	//			dp[i][j] = min(dp[i][j - quota[i]] + 1, dp[i - 1][j]);
	//		}else {
	//			dp[i][j] = dp[i - 1][j];
	//		}
	//	}
	//}
	//return dp[sz - 1][target] == INT_MAX ? -1 : dp[sz - 1][target];

	//dp-b
	//init
	vector<int > dp(target+1,INT_MAX);//must convert by row
	dp[quota[0]] = 1;
	
	
	for (int i = 0; i < sz; ++i)
	{
		for (int j = 0; j <target+1; ++j)
		{
			if (j - quota[i] >= 0 && dp[j - quota[i]] != INT_MAX)
			{
				dp[j] = min(dp[j - quota[i]] + 1, dp[j]);
			}
			//remain same as dp"[i-1]"[j]
		}
	}

	return dp[target] == INT_MAX ? -1 : dp[target];
}


//minimum edit distance
int min_edit(const string & s1, const string & s2, vector<int> cost)
{
	if (s1 == s2)
	{
		return 0;
	}


	int insert_cost = cost[0];
	int remove_cost = cost[1];
	int edit_cost = cost[2];


	vector<int> dp(s1.size()+1, 0);
	for (int i = 0; i <= s1.size(); i++)
	{
		dp[i] = insert_cost * i;
	}

	int tmp = dp[0];
	int pre = tmp;
	for (int i = 1; i <= s2.size(); ++i)
	{
		pre = dp[0];
		dp[0] = (i)*remove_cost;
		for (int j = 1; j < dp.size(); ++j)
		{
			tmp = dp[j];
			if (s1[j - 1] == s2[i-1])
			{
				dp[j] = pre;
			}
			else {
				dp[j] = pre + edit_cost;
			}
			dp[j] = min(min(tmp + remove_cost,dp[j]), dp[j - 1] + insert_cost);
			pre = tmp;
		}
	}

	return dp.back();
}




//int main(void)
//{
//	MAT m1{ {1,2,3},{1,2,3} ,{1,2,3} };
//	min_path(m1);
//	print_mat(mat_power(m1, 2));
//	
//	
//	/*string s1("adc");
//	string s2("abc");
//	vector<int > cost{5,3,100};
//	cout << min_edit(s1, s2, cost);
//	exit(0);*/
//}