#include "pch.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>


using namespace std;
bool check(const string & s, int lens[]);
void dfs(vector<string> & ret, int index, const string & s, int lens[]);


vector<string> restoreIpAddresses(string s) {
	vector<string> ret;
	string cache;
	int cur = 0;
	if (s.empty())
	{
		return ret;
	}
	int sz = s.size();
	int lens[4]{ 0 };

	dfs(ret, 0, s, lens);
	return ret;



}

void dfs(vector<string> & ret, int index, const string & s, int lens[])
{
	if (index > 3&&accumulate(lens,lens+4,0)==s.size())
	{
		if (check(s, lens))
		{
			//push into ret
			int start = 0;
			string valid;
			for (int i = 0; i < 4; ++i)
			{
				valid.append(s.substr(start, lens[i]));
				valid.push_back('.');
				start += lens[i];
			}
			valid.pop_back();
			ret.push_back(valid);
		}
		return;
	}

	int curlen = accumulate(lens, lens + index, 0);
	if (curlen + (4 - index) * 3 < s.size() || curlen + (4 - index) > s.size())
	{
		return;
	}
	else {
		//lens[index] = 1 2 3
		for (int i = 1; i <= 3; ++i)
		{
			lens[index] = i;
			dfs(ret, index + 1, s, lens);
			lens[index] = 0;
		}
	}


}

bool check(const string & s, int lens[])
{
	string tmp;
	int start = 0;
	
	for (int i = 0; start <= s.size() - 1 && i < 4; i++)
	{
		tmp = s.substr(start, lens[i]);
		if (stoi(tmp) < 0 || stoi(tmp) > 255)
		{
			return false;
		}
		start += lens[i];
	}

	return true;

}




void dfs_c(const string & s, vector<bool> & bits, int & num, int index);
int numDecodings(string s) {
	if (s.empty() || s[0] == '0')
	{
		return 0;
	}

	if (s.size() == 1 && s[0] != '0')
	{
		return 1;
	}
	vector<bool> bits(s.size(), 0);
	int num = 0;
	bits[0] = false;
	dfs_c(s, bits, num, 1);
	bits[0] = true;
	dfs_c(s, bits, num, 1);
	return num;
}

void dfs_c(const string & s, vector<bool> & bits, int & num, int index)
{

	if (index == s.size() - 1)
	{
		if ((bits[index - 1] && s[index] != '0') || (!bits[index - 1] && stoi(s.substr(index - 1, 2)) >= 1 && stoi(s.substr(index - 1, 2)) <= 26))
		{
			num++;
		}
		return;
	}

	if (bits[index - 1] == false)
	{
		bits[index] = true;
		string last = s.substr(index - 1, 2);
		if (stoi(last) < 1 || stoi(last) > 26)
		{
			bits[index] = false;
			return;
		}
		dfs_c(s, bits, num, index + 1);
		bits[index] = false;
	}
	else {
		if (s[index] != '0')
		{
			bits[index] = true;
			dfs_c(s, bits, num, index + 1);
			bits[index] = false;
			dfs_c(s, bits, num, index + 1);
		}
	}


}
//int main(void)
//{
//	vector<string> rIP;
//	rIP =  restoreIpAddresses("25525525511");
//	cout << numDecodings("101");
//	return 0;
//}