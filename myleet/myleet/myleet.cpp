#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
#include <map>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
	//for(each sorted elem)
	//{ considered ...  current  l  ...    ...   r}
	sort(begin(nums), end(nums));
	int pair_sum = target;
	int cur_min = INT_MAX;
	for (int i = 0; i < nums.size(); ++i)
	{
		pair_sum = target - nums[i];
		//two_ptr maintain minimum var
		int l = i + 1;
		int r = nums.size() - 1;
		while (l < r)
		{
			if (nums[l] + nums[r] == pair_sum)
			{
				return target;
			}
			while (l < r&&nums[l] + nums[r] < pair_sum)
			{
				if (abs(pair_sum - nums[l] - nums[r]) < abs(cur_min))
				{
					cur_min = (pair_sum - nums[l] - nums[r]);
				}
				else if (cur_min == 0)
				{
					return target;
				}
				l++;
			}

			while (l<r &&nums[l] + nums[r] > pair_sum)
			{
				if (abs(pair_sum - nums[l] - nums[r]) < abs(cur_min))
				{
					cur_min = (pair_sum - nums[l] - nums[r]);
				}
				else if (cur_min == 0)
				{
					return target;
				}
				r--;
			}

		}
	}

	return target - cur_min;
}

string digit_trans(int d, int BASE = 16)
{
	string ret;
	if (BASE < 0 || BASE>16)
	{
		return ret;
	}
	if (!d || !BASE)
	{
		return "0";
	}
	string lex("0123456789ABCDEF");
	lex = lex.substr(0, BASE);
	while (d)
	{
		ret.push_back(lex.at(d % BASE));
		d /= BASE;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

bool searchMatrix_a(vector<vector<int>>& matrix, int target) {
	//smaller left bigger down ,start at right up corner
	int r = matrix[0].size() - 1;
	int u = 0;
	while (u <= matrix.size() - 1 && r >= 0)
	{
		if (target > matrix[u][r])
		{
			u++;
		}
		else if (target < matrix[u][r])
		{
			r--;
		}
		else {
			break;
		}
	}

	if ((u == matrix.size() - 1) && r == 0)
	{
		return false;
	}

	return true;
}
bool searchmat(vector<vector<int>>& matrix, int target) {
	int midx;
	int midy;
	int lx = 0, ly = 0, rx = matrix[0].size() - 1, ry = matrix.size();
	while (ly < ry)//[)
	{
		midy = ly + ((ry - ly) >> 1);
		if (target < matrix[midy][0])
		{
			ry = midy;
		}
		else
		{
			ly = midy + 1;
		}
	}

	if (ly >= matrix.size() )
	{
		midy = matrix.size() - 1;
	}
	else if (ly <= 0)
	{
		return false;
	}


	midy = ly - 1;
	while (lx < rx)//[]
	{
		midx = lx + (rx - lx) >> 1;
		if (target < matrix[midx][midy])
		{
			rx = midx - 1;
		}
		else if (target > matrix[midx][midy])
		{
			lx = midx + 1;
		}
		else {
			break;
		}
	}

	if (lx > matrix[0].size() - 1 || lx < 0)
	{
		return false;
	}

	return matrix[midy][lx] == target;

}

string minWindow(string s, string t) {
	int left, right;
	if (t.empty() || s.empty())
	{
		return "";
	}

	map<char, int> curmap;
	int validcount = 0;
	for (int i = 0; i < t.size(); ++i)
	{
		if (curmap.count(t[i]) == 0)
		{
			curmap.insert(make_pair(t[i], 1));
		}
		else {
			curmap[t[i]]++;
		}
	}
	left = right = 0;
	int Min =INT_MAX;
	int minleft = 0;
	while (right < s.size())
	{
		if (curmap.count(s[right]) == 0)
		{
			right++;
			continue;
		}
		else {
			curmap[s[right]]--;
			
			if (curmap[s[right]] == 0)
			{
				validcount++;
			}
			if (validcount == curmap.size())
			{
				//check
				while (curmap.count(s[left]) == 0 || (curmap[s[left]]<0))
				{
					if (curmap.count(s[left]) != 0)
					{
						curmap[s[left]]++;
					
					}
					left++;
				}
				if (right - left+1 < Min)
				{
					Min = right - left+1;
					minleft = left;
				}
			}
			right++;
		}
	}//end while

	return Min == INT_MAX? "":s.substr(minleft, Min);
}

//int main()
//{
//	//vector<vector<int>> m{ {1, 4, 7, 11, 15}, { 2, 5, 8, 12, 19}, { 3, 6, 9, 16, 22}, { 10, 13, 14, 17, 24}, { 18, 21, 23, 26, 30} };
//	//std::cout << searchMatrix_a(mat, 3);
//	std::cout << minWindow("cabwefgewcwaefgcf"
//		,"cae");
//
//}
