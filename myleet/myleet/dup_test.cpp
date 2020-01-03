#include "pch.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
enum class ORDER {
	MIN,MAX
};
void percolate_down(vector<int> &v,int index,int r,ORDER od)
{
	while(index << 1 <= r)
	{
		int l = index << 1;//left child index
		int cursor = l;
		if(cursor + 1 <= r)
		{
			//has right child
			if ((v[l + 1] < v[l] && od == ORDER::MIN) || (v[l + 1] >= v[l] && od == ORDER::MAX))
			{
				cursor = l + 1;
			}
			
			
		}
		//swap down
		if ((v[cursor] < v[index]&&od==ORDER::MIN)&&(v[cursor]>=v[index]&&od==ORDER::MAX))
		{
			v[index] = v[cursor];
			index = cursor;
		}
		else {
			break;
		}
		
	}
}
void build_heap(ORDER od,int l,int r,vector<int> & v)
{
		for (int i = l+(r-l)/2;i>=l;--i)
		{
			percolate_down(v,i,r,od);
		}
}

void print_heap(const vector<int> & hp,int l,int r)
{
	int num = r - l + 1;
	if (num <= 0)
	{
		return;
	}
	int h = 0;
	while (num > 0)
	{
		h = h + 1;
		num = num >> 1;
	}

	//calcu the width to print
	int width = pow(2, h )-1;
	string s(width, ' ');
	string backup = s;
	int stride = pow(2, h );
	int cursor = l;
	int start = (width >> 1) ;
	while (cursor < r)
	{
		int i = start;
		while (i<width)
		{
			s[i] = hp[cursor++]+'0';
			i += stride;
		}
		cout << s << endl;
		s = backup;
		//update start and stride
		start = start >> 1;
		stride = stride >> 1;
	}
}
bool k_smallest(const vector<int>)
{

	return true;
}


//int main()
//{
//	vector<int > v{ 8,1,2,3,4,5,6,7,8 };
//	build_heap(ORDER::MIN, 1, v[0], v);
//	print_heap(v, 1, v[0]);
//	return 0;
//}