#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
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

string digit_trans(int d,int BASE=16)
{
	string ret;
	if (BASE < 0 || BASE>16)
	{
		return ret;
	}
	if (!d||!BASE)
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
//int main()
//{
//   std::cout << digit_trans(16,16); 
//}
