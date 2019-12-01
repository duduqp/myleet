#include "pch.h"
#include <vector>
#include <iostream>
#include <string>
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
	size_t start = 0,end = 0;
	while ((end = s.find(' ', start)) != string::npos)
	{
		reverse(s.begin() + start, s.begin() + end);
		start = end + 1;
	}

	//last word!
	reverse(s.begin() + start, s.end());
}

