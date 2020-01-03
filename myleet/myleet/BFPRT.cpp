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

int k_largest(vector<int> v,int k)
{
	//return the index of the second largest element
	make_heap(v.begin(), v.begin()+k, [](const int & l,const int & r){ return l>r; });

	//from the kth

	for (int i = k; i < v.size(); ++i)
	{
		//for each element ,compare with the smallest(down_thresh) of the k heap
		if (v[i] > v[0])
		{
			//update the k heap
			swap(v[0], v[i]);
		}
		//else continue 
	}

	return v[0];
}

//version2: partition technique
//int k_largest_partition(vector<int> v, int k)
//{
//
//
//}
//

int median_of_three(int & a, int & b, int &c)
{
	int ret = (a + b + c) - max({ a,b,c }) - min({ a,b,c });
	int min_one = min({ a,b,c });
	int max_one = max({ a,b,c });
	a = min_one;
	b = ret;
	c = max_one;
	return ret;
}
int partition_aux(vector<int > &v,int l,int r)
{
	//random choose the pivot
	int mid = l + (r - l) >> 1;
	int pivot = median_of_three(v[l],v[mid],v[r]);
	//partition
	/*
	version a:error
	int i = l + 1, j = r - 2;
	swap(v[r - 1], v[mid]);
	while (i<j)
	{
		while (v[i] < pivot&&i<j)
		{
			i++;
		}
		while (v[j] > pivot&&j>i)
		{
			j--;
		}
		if (i < j)
		{
			swap(v[i], v[j]);
		}
	}

	swap(v[i],v[r - 1]);*/
	

	//modified:correct
	int i = l, j = r - 1;
		 swap(v[r - 1], v[mid]);
		 while (i < j)
		 {
			 while (v[++i] < pivot)
			 {

			 }
			 while (v[--j] > pivot)
			 {
				 j--;
			 }
			 if (i < j)
			 {
				 swap(v[i], v[j]);
			 }
		 }

		 swap(v[i], v[r - 1]);

	return i;
}


int main()
{
	vector<int > v1{ 6,5,1 };
	vector<int > v2{ 2,4,7,8 };
	//std::cout << median_of_two(v1, v2);
	vector<int> v3{ 2,3,9,6,8,6,4,5,6 };//error case for version_a
	//cout << k_largest(v3, 5);
	/*cout << median_of_three(v1[0], v1[1], v1[2]) << endl;*/
	int pivot = partition_aux(v3,0,8);
	cout << pivot << endl;
	for_each(v3.cbegin(), v3.cend(), [](const int & i) {cout << i << ends; });
}

