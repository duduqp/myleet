#include "pch.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int median(const vector<int> & v1, int l1, int r1,const vector<int >& v2,int l2,int r2)
{
	int amid = l1 + ((r1-l1) >> 1);
	int a_median = v1[amid];
	int bmid = l2 + ((r2-l2) >> 1);
	int b_median = v2[bmid];
	if (((r1 - l1) + (r2 - l2)) < 3)
	{
		//boundary case
		if ((r1 - l1) == 1)
		{
			if ((r2 - l2) == 1)
			{
				return (v1[r1] + v2[l2]) >> 1;
			}
			else
			{
				//(r2 - l2) == 0
				return (v1[r1] > v2[l2] ? max(v1[l1], v2[l2]) : v1[r1]);
			}
			
		}
		else if ((r2 - l2) == 1)
		{
				//(r1 - l1) == 0
				return (v2[r2] > v1[l1] ? max(v2[l2], v1[l1]) : v2[r2]);
		}
		else {
			return (v1[r1] + v2[l2]) >> 1;
		}
	}

	if (a_median < b_median)
	{
		return median(v1, amid + 1, r1, v2, l2, bmid - 1);
	}
	else if (a_median == b_median)
	{
		return a_median;
	}
	else {
		return median(v1, l1, amid-1, v2, bmid+1, r2);
	}
}

int median_of_two(const vector<int > &v1, const vector<int > &v2)
{
	if (v1.size() != v2.size())
	{
		return -1;
	}
	else {
		return median(v1, 0, v1.size() - 1, v2, 0, v2.size() - 1);
	}

}

//int main()
//{
//	vector<int > v1{ 1,3,5,6 };
//	vector<int > v2{ 2,4,7,8 };
//	std::cout << median_of_two(v1, v2);
//}

