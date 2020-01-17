#include "pch.h"
#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
void stradd(string & s1, const string & s2, int leftshift);
string mult_digit(const string & s1, int d);


string multiply(string num1, string num2) {
	int len = num1.size() + num2.size();
	string addee(len, '0');
	string &multer = num1.size() <= num2.size()?num1:num2;
	string &multee = multer == num1 ? num2 : num1;
	map<char, string> m;
	for (int i = 0; i < 10; ++i)
	{
		m.insert(make_pair(i + '0', mult_digit(multee, i)));
	}
	for (int i = 0; i < multer.size(); ++i)
	{
		// string tmp(len,'0');
		const string &adder = m[multer[multer.size() - i - 1]];
		// tmp.replace(len-adder.size(),adder.size(),adder);
		stradd(addee, adder, i);
	}
	
	return addee[0]=='0'?addee.substr(1,len-1):addee;
}

string mult_digit(const string & s1, int d)
{
	int sz = s1.size();
	int carry = 0;
	string ret(sz+1, '0');
	for (int i = 0; i < sz; i++)
	{
		ret[i] = (carry + (d*(s1[sz - i - 1] - '0'))) % 10 + '0';
		carry = (carry + (d*(s1[sz - i - 1] - '0'))) / 10;
	}
	if (carry != 0)
	{
		ret[sz] = carry + '0';
	}
	else {
		ret.pop_back();
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
void stradd(string & s1, const string & s2, int leftshift)
{
	//add s1[0...s1.size()-1-leftshift] by s2
	int i = s1.size() - 1 - leftshift;
	int carry = 0;
	int sum = 0;
	for (int j = s2.size() - 1; j >= 0; j--)
	{
		sum = s2[j] - '0' + s1[i] - '0' + carry;
		s1[i] = (sum % 10) + '0';
		carry = sum / 10;
		i--;
	}
	while (carry != 0)
	{
		sum = carry + s1[i] - '0';
		s1[i] = (sum % 10) + '0';
		carry = sum / 10;
		i--;
	}
}
const char * tonight = "tonight";
//int main(void)
//{
//	printf("%d\n", tonight);
//	//string ret = mult_digit("124", 9); 
//	//cout << multiply("456","123")<< "\n";
//	const char * liffer[] = { "tonight","go","die" };
//	cout << liffer << &liffer << "\n";
//	exit(0);
//}