#include "pch.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <utility>
#include <algorithm>
#include<map>
using namespace std;
using point = pair<int, int>;
using vec = pair<int, int>;
int inner_product(vec x1, vec x2)
{
	return x1.first*x2.first + x1.second*x2.second;
}

bool inedge(point p1, point p2,point x)
{
	if ((x.first == p1.first&&x.second == p1.second) || (x.first == p2.first&&x.second == p2.second))
	{
		return true;
	}
	if ((x.first - p1.first)*(x.first - p2.first) > 0 || (x.second - p1.second)*(x.second - p2.second) > 0)
	{
		return false;
	}

	double k1 = ((double)(p1.second - p2.second)) / ((double)(p1.first - p2.first));
	double k2 = ((double)(x.second - p2.second)) / ((double)(x.first - p2.first));
	return k1 == k2;
}


bool contain(point p1,point p2, point p3,point x)
{

	auto v1 = vec((p1.first - x.first), (p1.second - x.second));
	auto v2 = vec((p2.first - x.first), (p2.second - x.second));
	auto v3 = vec((p3.first - x.first), (p3.second - x.second));
	int r1=inner_product(v2, v3);
	int r2=inner_product(v2, v3);
	int r3=inner_product(v2, v3);

	return inedge(p1,p2,x)||inedge(p1,p3,x)||inedge(p2,p3,x)||r1*r2*r3<0||
		(r1 == 0 && r2 < 0 && r3 < 0)|| (r2 == 0 && r1 < 0 && r3 < 0)|| (r3 == 0 && r1 < 0 && r3 < 0);

}




bool wordBreak(string s, vector<string>& wordDict) {
	const int h = s.size();
	const int w = wordDict.size();
	sort(wordDict.begin(), wordDict.end(), [](const string & s1, const string & s2) { return s1.size() < s2.size(); });

	vector<vector<bool>> dp(w, vector<bool>(h, false));
	bool contain = false;
	for (int i = wordDict[0].size() - 1; i < h; ++i)
	{
		/*if (contain)
		{
			while (i <= h - 1)
			{
				dp[0][i++] = true;

			}
			break;
		}
		else {*/
		for (int k = 0; k <= wordDict.size() - 1; ++k)
		{
			int l = i - wordDict[k].size() + 1;
			if (l == 0)
			{
				dp[0][i] = (s.substr(0, wordDict[k].size()) == wordDict[k]);
			}
			else if (l > 0) {
				cout << l;
				dp[0][i] = dp[0][l - 1] && (s.substr(l, wordDict[k].size()) == wordDict[k]);
			}
		}
		//contain = dp[0][i];
	//}
	}


	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; ++j)
		{
			cout << boolalpha << dp[i][j] << "  ";
		}
		cout << "\n";
	}
	//sub(j- win +1,win)
	for (int i = 1; i < w; ++i)
	{
		/*contain = false;*/
		for (int j = wordDict[0].size() - 1; j < h; ++j)
		{
			/*if (contain)
			{
				while (j < h)
				{
					dp[i][j++] = true;
				}
				break;
			}
			else {*/
				for (int k = 0; k <= i; ++k)
				{
					int l = j - wordDict[k].size() + 1;
					if (l== 0)
					{
						dp[i][j] = (s.substr(0, wordDict[k].size()) == wordDict[k]);
					}
					else if(l>0){
						dp[i][j] = dp[i][l-1] && (s.substr(l, wordDict[k].size()) == wordDict[k]);
					}
					if (dp[i][j])
					{
						break;
					}
				}
				/*contain = dp[i][j];
			}*/
		}
	}

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; ++j)
		{
			cout << boolalpha << dp[i][j] << "  ";
		}
		cout << "\n";
	}
	return dp[w - 1][h - 1];

}


int longestConsecutive(vector<int>& nums) {
	if (nums.empty() || nums.size() == 1)
	{
		return nums.size();
	}
	map<int, int> interval;
	for (int i = 0; i < nums.size(); ++i)
	{
		interval[nums[i]] = i;
		nums[i] = -1;
	}

	//merge
	auto end = interval.end();
	for (auto it = interval.begin(); it != end; ++it)
	{
		if (interval.count(((*it).first + 1)) != 0)
		{
			int current = (*it).first;
			int current_index = interval[current];
			int right = (*it).first + 1;
			int father_index = interval[right];
			int tmp = nums[current_index];
			nums[current_index] = father_index;
			//find 
			while (nums[current_index] >= 0)
			{
				current_index = nums[current_index];
			}
			nums[current_index]+=tmp;
//			interval[current] = -1;
		}
		else if (interval.count(((*it).first - 1)) != 0)
		{
			int current = (*it).first;
			int current_index = interval[current];
			int left_index = interval[current - 1];
			int tmp = left_index;
			nums[left_index] = current_index;
			//find 
			while (nums[tmp] >= 0)
			{
				tmp = nums[tmp];
			}
			nums[tmp]+=nums[left_index];
			//interval[current] = -1;
		}
		else {
			;
		}
	}
	int Min = INT_MAX;
	for (auto & e : nums)
	{
		if (e < Min)
		{
			Min = e;
		}
	}
	return -Min;
}



int main(void)
{
	/*point p1(1, 1);
	point p2(3, 3);
	point x(2, 2);
	cout << boolalpha << inedge(p1, p2, x);*/
	/*string s = "applepenapple";
	vector<string> words = { "apple", "pen"};
	cout << wordBreak(s, words);*/
	
	vector<int> nums{ 100, 4, 200, 1, 3, 2 };
	longestConsecutive(nums);
	
	return 0;
}