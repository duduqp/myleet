#include "pch.h"
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <limits>
using namespace std;
class A {
public:
	static int s;
	A() { cout << "A default" << endl; }
	int a;
	virtual void vf() { cout << "vf" << endl; };
	virtual void vf2() { cout << "vf2" << endl; };

};

class B {
public:

	A a;
	int b;
	B() {
		b = 0;
		cout << "only init member b=0" << endl;
	}
	B(const B& rhs, int b = 0) { cout << "copy constructor" << endl; }
};

class C :public  A {
public:
	int c;
};



bool isPalindrome(int x) {
	if (x < 0 || (x != 0 && x % 10 == 0))
	{
		return false;
	}

	if (x / 10 == 0)
	{
		return true;
	}

	int digits = 1;
	int num = x;
	while (num / 10)
	{
		digits++;
		num = num / 10;
	}

	int len = (digits >> 1);
	int left = x / (pow(10, (digits - len)));
	int right = x % (int)(pow(10, len));
	if (len == 1)
	{
		return left == right;
	}
	std::cout << left << " : " << right << std::endl;
	int i = 1;
	std::cout << i << ":i" << std::endl;
	std::cout << (int)(left % ((int)(pow(10, i)))) << ":l" << endl;;
	std::cout << (int)(right / pow(10, len - i)) << ":r" << endl;
	while (i <= len && ((int)(left % (int)(pow(10, 1))) == ((int)(right / pow(10, len - i)))))
	{
		std::cout << i << "::" << left << " :: " << right << std::endl;
		left = left / 10;
		right = right % (int)pow(10, len - i);
		i++;
	}
	return i >= len;
}

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> ret;
	if (nums.size() < 3)
	{
		return ret;
	}

	sort(begin(nums), end(nums));
	int Max = *(std::max_element(nums.begin(), nums.end()));
	int Min = *(std::max_element(nums.begin(), nums.end()));
	if (Max == Min && Max == 0)
	{
		ret.push_back(vector<int>{0, 0, 0});
		
	}
	else if (Max <= 0)
	{
		return ret;
	}
	else {
		int sz = nums.size();
		// for_each(cbegin(nums), cend(nums), [](const int & i) {std::cout << " " << i << " "; });
		for (int i = 0; i < (sz - 2); ++i)
		{
			int j = i + 1;
			int k = sz - 1;
			// std::cout << i << "|" << j << "|" << k << std::endl;
			while (j < k)
			{
				while ((j < k) && (nums[j] + nums[k] + nums[i]) > 0)
				{
					k--;
				}
				// std::cout << i << "|" << j << "|" << k << std::endl;
				while ((j < k) && (nums[j] + nums[k] + nums[i]) < 0)
				{
					j++;
				}
				// std::cout << i << "|" << j << "|" << k << std::endl;
				// std::cout << nums[i] << "|" << nums[j] << "|" << nums[k] << std::endl;
				if (j < k&&nums[j] + nums[k] + nums[i] == 0)
				{
					ret.push_back(vector<int>{nums[i], nums[j], nums[k]});
					j++; k--;
				}
				else if (j >= k)
				{
					break;
				}
			}
		}
		sort(begin(ret), end(ret));
		auto last = std::unique(ret.begin(), ret.end(), [](const vector<int> &l, const vector<int> &r) {
			return (l[0] == r[0]) && (l[1] == r[1]) && (l[2] == r[2]);
		});

		ret.erase(last, ret.end());
	}
	return ret;
}
	//int main()
	//{
	//	//vector
	//	vector<double >  v(10, 100.0);
	//	v.erase(begin(v), end(v));
	//	//cout << v.size() << boolalpha << v.empty() << endl;
	//	v.assign(5, 6);
	//	for (auto &d : v)//const auto & element = *const-iterator
	//	{
	//		//already deref
	//		d = 8;
	//	}
	//	//for_each(cbegin(v), cend(v), [](const double & d) {cout << d << ends; });

	//	/*C c;
	//	cout << sizeof(A)<<sizeof c << endl;*/
	//	B b1;
	//	B b2(b1);
	//	//cout << sizeof b1 << endl;
	//	A a;
	//	//cout << sizeof(A) << sizeof a << endl;
	//	//isPalindrome(222222);
	//	vector<int> nums{ -4,-1,-4,0,2,-2,-4,-3,2,-3,2,3,3,-4 };
	//	threeSum(nums);
	//	return 0;
	//}


