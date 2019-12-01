#include "pch.h"
#include <vector>
#include <iostream>
using namespace std;

int minimum_index(const  vector<int > & v)
{
	if (v.empty() || v.size() == 1)
	{
		return -1;
	}

	if (v.size() == 2)
	{
		return v[0] > v[1] ? 1 : 0;
	}

	//v.size()>2
	//binary
	int l = 0, r = v.size() - 1;
	if(v[l]<v[l+1])
	{
		return l;
	}
	else if (v[r] < v[r - 1])
	{
		return r;
	}
	else {
		int mid;
		while (l<r)
		{
			mid = (l + r) >> 1;
			if (v[mid] > v[mid - 1])
			{
				//index must locate in [l,mid-1]
				r = mid - 1;
			}
			else if (v[mid] > v[mid + 1])
			{
				l = mid + 1;
			}
			else {
				return mid;//v[mid-1]>v[mid]<v[mid+1]
			}
		}
		return l;
	}

}
