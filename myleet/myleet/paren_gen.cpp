#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <stack>
#include <string>
using namespace std;
void generate_sub(int n ,int l, int r, int target, string & cur,vector<string> & ret)
{
	if (target == 0)
	{
		//left have been match with right completely
		//on this occation,push left 
		if (l < n)
		{
			cur[l + r] = '(';
			generate_sub(n, l + 1, r, target + 1, cur, ret);
		}
		else {
			//l == n
			ret.push_back(string(cur));
		}
			return;
	}
	if (target<0)
	{
		if (l < n)
		{
			cur[l + r] = '(';
			generate_sub(n,l+1,r,target+1,cur,ret);
		}
		
		if (r < n)
		{
			cur[l + r] = ')';
			generate_sub(n, l, r + 1, target - 1, cur, ret);
		}
		return;
	}
	else
	{
		if (r < n)
		{
			cur[l + r] = ')';
			generate_sub(n, l, r + 1, target - 1, cur, ret);
		}
		
		if (l < n)
		{
			cur[l + r] = '(';
			generate_sub(n, l+1, r, target + 1, cur, ret);
		}
		return;
	}
	
}

vector<string> generateParenthesis(int n) {
	vector<string > ret;
	string s(2*n, ')');
	for (int i = 0 ; i < n ; ++i)
	{
		s[i] = '(';
	}

	generate_sub(n, 0, 0, 0, s, ret);
	for (auto s : ret)
	{
		std::cout << s << std::endl;
	}
	return ret;
}

int main()
{
	generateParenthesis(3);
}