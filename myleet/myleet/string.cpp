#include "pch.h"
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
using namespace std;


vector<int > gen_next(string & needle)
{
	vector<int > next;
	return next;
}
int strStr(string haystack, string needle) {
	if (needle.empty())
	{
		return 0;
	}
	int index = -1;

}

bool palindrome_test(const string & s)
{
	int l = 0;
	int r = s.size() - 1;
	while (l < r)
	{
		while (l < r && !isalnum(s[l]))
		{
			l++;
		}

		while (l < r && !isalnum(s[r]))
		{
			r--;
		}

		if (tolower(s[l]) != tolower(s[r]))
		{
			return false;
		}
	}

	return true;
}

void reverse_word(string & s)
{
	reverse(s.begin(), s.end());

	//reverse_each_word to correct
	size_t start = 0, end = 0;
	while ((end = s.find(' ', start)) != string::npos)
	{
		reverse(s.begin() + start, s.begin() + end);
		start = end + 1;
	}

	//last word!
	reverse(s.begin() + start, s.end());
}



void gen_bc(map<char, int> & res, const string & p)
{
	for (int i = p.size() - 1; i >= 0; --i)
	{
		if (res.count(p[i]) == 0)
		{
			res.insert(make_pair(p[i], i));
		}
	}
}

int bm(map<char, int> & bc, const string & t, const string & p)
{
	int i = 0;
	int skip = 1;
	for (; i <= t.size() - p.size(); i += skip)
	{
		skip = 0;
		for (int j = p.size() - 1; j >= 0; j--)
		{
			if (t[i + j] != p[j])
			{
				int inc = bc.count(t[i + j]) == 0 ? -1 : bc[t[i + j]];
				skip = j - inc;
				skip = max(1, skip);
				break;
			}
		}
		if (skip == 0)
		{
			return i;
		}
	}
	return -1;
}

int match(string haystack, string needle) {
	if (needle.empty() || haystack.empty() || haystack.size() < needle.size())
	{
		return -1;
	}

	if (haystack.size() == needle.size())
	{
		return haystack == needle;
	}
	map<char, int> dir;
	gen_bc(dir, needle);
	return bm(dir, haystack, needle);
}

vector<int> findSubstring(string s, vector<string>& words) {
	vector<int> ret;
	int win_len = 0;
	if (words.empty() || (win_len = words.size()*words[0].size()) > s.size())
	{
		return ret;
	}
	int s_len = words[0].size();
	map<string, int> cache;
	map<string, int> backup;
	for (int i = 0; i < words.size(); ++i)
	{
		if (cache.count(words[i]) == 0)
		{
			cache.insert(make_pair(words[i], 1));
		}
		else {
			cache[words[i]]++;
		}
	}
	backup = cache;
	int l = 0;
	int r = win_len;
	int i;
	string tmp;
	while (r <= s.size())
	{

		for (i = l; i <= r - s_len; i += s_len)
		{
			tmp = s.substr(i, s_len);
			if (cache.count(tmp) == 0)
			{
				break;
			}
			else {
				if ((cache[tmp] - 1) < 0)
				{
					break;
				}
				else {
					cache[tmp]--;
				}
			}
		}


		if (i == r)
		{
			ret.push_back(l);
		}
		l++; r++;
		cache = backup;
	}

	return ret;
}
string getPermutation(int n, int k) {

	vector<int> product(n, 1);
	vector<int> digits(n, 1);
	string ret;
	int i = 1;
	for (; i < n; i++)
	{
		product[i] = product[i - 1] * (i + 1);
		digits[i] = i + 1;
	}
	if (k > product[n - 1])
	{
		return ret;
	}
	i = n - 1;
	int j = 0;
	int m = 0;
	while (i >= 0 && k)
	{
		i--;
		m = 0;
		int rank = k % product[i] == 0 ? k / product[i] : (k / product[i]) + 1;
		for (j = 0; j < n; ++j)
		{
			if (digits[j] > 0)
			{
				m++;
			}
			if (m == rank)
			{
				break;
			}
		}
		ret.push_back(digits[j] + '0');
		digits[j] = -digits[j];
		k = k % product[i];
		std::cout << k << " ------ " << i << " ------ " << ret << std::endl;
	}
	std::cout << k << "  " << i << "  " << ret << std::endl;

	if (i >= 0)
	{
		std::cout << k << " ------ " << i << " ------ " << ret << std::endl;
		for (j = 0; j < n; ++j)
		{
			if (digits[j] > 0)
			{
				ret.push_back(digits[j]);
			}

		}
	}
	return ret;
}
void process(int & i, const string & path, deque<string> & cache);
string simplifyPath(string path) {
	deque<string> cache;
	string ret;
	int i = 0;
	for (; i < path.size();)
	{
		if (path[i] == '.' || path[i] == '/')
		{
			process(i, path, cache);
		}
		else {
			int j = i;
			while (i < path.size() && (path[i] != '.'&&path[i] != '/'))
			{
				i++;
			}
			cache.push_back(path.substr(j, i - j));

		}
	}


	while (!cache.empty())
	{
		ret.push_back('/');
		ret.append(cache.front());
		cache.pop_front();
	}

	return ret;
}

void process(int & i, const string & path, deque<string> & cache)
{
	if (path[i] == '/')
	{
		while (i < path.size() && path[i] == '/')
		{
			i++;
		}
	}

	while (i < path.size() && (path[i] == '.' || path[i] == '/'))
	{
		if (path[i] == '/')
		{
			while (i < path.size() && path[i] == '/')
			{
				i++;
			}
		}
		else {
			i++;
			if (i < path.size())
			{
				if (path[i] == '/')
				{
					i++;
				}
				else if (path[i] == '.')
				{
					if (i + 1 < path.size() && path[i + 1] == '.')
					{
						int j = i - 1;
						i++;
						while (i < path.size() && path[i] == '.')
						{
							i++;
						}
						cache.push_back(path.substr(j, i - j));
						continue;
					}
					if (!cache.empty())
					{
						cache.pop_back();
					}
					i++;
				}
				else {
					break;
				}
			}
		}
	}
}
//int main(void)
//{
//	//string s = "wordgoodgoodgoodbestword";
//	//vector<string> v{ "word","good","best","good" };
//	//auto ret = findSubstring(s,v);
//	//simplifyPath("/a/../../b/../c//.//");
//	cout << a << b;
//	return 0;
//}