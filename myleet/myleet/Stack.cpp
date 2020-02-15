#include "pch.h"
#include "Stack.h"
#include <iostream>
#include <stack>
#include <string>
#include <ctype.h>
#include <map>
using namespace std;
using SharedIntStack = dudu::sharedstack<int>;
string to_postfix(const string & s)
{
	// xx  +x *xxx // 
	map<char, int> priority{pair<char,int>('+',0),pair<char,int>('-',0), pair<char,int>('*',1), 
	pair<char,int>('/',1)};
	string ret(s.size(), ' ');
	stack<char>  ops;
	int i = 0;
	int j = 0;
	for (; j < s.size(); ++j)
	{
		if (isalnum(s[j])||s[j]==' ')
		{
			ret[i++] = s[j];
		}
		else {
			//s[j] == '+'£¬'-'£¬'*'£¬'/'£¬'(' ,')'
			if (s[j] == ')')
			{
				while (ops.top() != '(')
				{
					ret[i++] = ops.top();
					ops.pop();
				}
				ops.pop();
			}
			else if (s[j] == '(')
			{
				ops.push(s[j]);
			}
			else {
				while (!ops.empty()&&priority[s[j]] <= priority[ops.top()])
				{
					ret[i++] = ops.top();
					ops.pop();
				}
				ops.push(s[j]);

			}
		}
	}

	while (!ops.empty())
	{
		ret[i++] = ops.top();
		ops.pop();
	}
	return ret;

}
int process(const string & post, int &i);
int calcu_postfix(const string & post)
{
	stack<int> cache;
	int i = 0;
	while (i < post.size())
	{
		if (isdigit(post[i]))
		{
			int num = process(post, i);
			cache.push(num);
		}
		else {
			//post[i] == 'ops';
			int rhs = cache.top() ;
			cache.pop();
			int lhs = cache.top() ;
			cache.pop();
			int res;
			if (post[i] == '+')
			{
				res = lhs + rhs;
			}
			else if (post[i] == '-')
			{
				res = lhs - rhs;
			}
			else if (post[i] == '*')
			{
				res = lhs * rhs;
			}
			else {
				res = lhs / rhs;
			}
			i++;
			cache.push(res);
		}
	}
	return cache.top();
}

int process(const string & post, int &i)
{
	string tmp;
	while (isdigit(post[i]))
	{
		tmp.push_back(post[i++]);
	}
	int ret = stoi(tmp);
	i++;
	return ret;
}

int Maxspan(const vector<int> &arr)
{
	int maxspan = INT_MIN;
	int width = -1;
	std::stack<int> non_decreasing; 

	for (int i = 0; i < arr.size(); ++i)
	{
		while (!non_decreasing.empty() && arr[i] > arr[non_decreasing.top()])//empty or taller than previous
		{
			//note that if equal can be taken into consideration
			non_decreasing.pop();
		}


		if (non_decreasing.empty())
		{
			//if the case empty
			width=-1;//width can reach start 
		}
		else {
			width = non_decreasing.top();//some point first smaller than
		}

		int curarea = (i - width)*arr[i];
		maxspan = max(maxspan, curarea);
		non_decreasing.push(i);
	}
	return maxspan;
}

int largestRectangleArea(vector<int>& heights) {
	//stack
	if (heights.empty())
	{
		return 0;
	}
	stack<int> increasing;
	int pre = -1;//init left bound index
	int maxarea = INT_MIN;
	for (int i = 0; i < heights.size(); ++i)
	{
		while (!increasing.empty() && heights[increasing.top()] >= heights[i])
		{
			

				int height = 0;
				if (increasing.empty())
				{
					pre = -1;
				}
				else {
					height = heights[increasing.top()];
					increasing.pop();
					pre = increasing.empty()?-1:increasing.top();
				}
				int width = i - pre - 1;
				int curarea = width * height;
				maxarea = max(maxarea, curarea);
			
		}
		increasing.push(i);
	}

	//if stack not empty
	while (!increasing.empty())
	{
		int height = heights[increasing.top()];
		increasing.pop();
		pre = increasing.empty() ? -1 : increasing.top();
		int curarea = (heights.size() - pre-1 )*height;
		maxarea = max(curarea, maxarea);
	}

	return maxarea;
}
//int main(void)
//{
//	/*string post = to_postfix("12 +1 *32 +9 ");
//	cout << post<<"\n";
//	cout << calcu_postfix(post);*/
//
//
//	//test minstack
//	/*dudu::MinStack<int> ms;
//	ms.Push(1);
//	ms.Push(2);
//	ms.Push(3);
//	cout << ms.GetMin() << endl;*/
//	
//	
//	//test maxarea
//	vector<int> heights{ 2,2,2,2,2,2,3};
//	cout << largestRectangleArea(heights);
//	
//	return 0;
//}

