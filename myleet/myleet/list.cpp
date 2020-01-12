#include "pch.h"
#include <iostream>
#include <vector>
#include "LinkedList.h"
#include <stack>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		int digit = 0;
		ListNode *ret = nullptr, *tail = nullptr;
		ret = tail;
		while (l1 || l2)
		{
			if (l1&&l2)
			{
				digit = (l1->val + l2->val + carry) % 10;
				carry = (l1->val + l2->val + carry) / 10;
				insert_tail(tail, digit);
				l1 = l1->next;
				l2 = l2->next;
			}
			else if (l1 && (!l2)) {
				while (l1 || (carry != 0))
				{
					if (l1)
					{
						digit = (l1->val + carry) % 10;
						carry = (l1->val + carry) / 10;
						insert_tail(tail, digit);
					}
					else {
						if (carry != 0)
						{
							insert_tail(tail, carry);
							return ret;
						}
					}
				}
			}
			else {
				while (l2 || (carry != 0))
				{
					if (l2)
					{
						digit = (l2->val + carry) % 10;
						carry = (l2->val + carry) / 10;
						insert_tail(tail, digit);
					}
					else {
						if (carry != 0)
						{
							insert_tail(tail, carry);
							return ret;
						}
					}
				}
			}
		}
		if (carry != 0) {
			insert_tail(tail, carry);
		}
			return ret;
	}

	void insert_tail(ListNode * &node, int val)
	{
		ListNode * ret = new ListNode(val);
		if (!node) {
			node = ret;
			return;
		}
		ret->next = nullptr;
		node->next = ret;
		node = node->next;
	}
};

class Solution2{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int > s1;
		stack<int > s2;
		while (l1)
		{
			s1.push(l1->val);
			l1 = l1->next;
		}

		while (l2)
		{
			s2.push(l2->val);
			l2 = l2->next;
		}


		ListNode * ret;
		int carry = 0;
		int digit = 0;
		int sum = 0;
		while (!s1.empty() || !s2.empty())
		{
			if (!s1.empty() && (!s2.empty()))
			{
				int top1 = s1.top();
				int top2 = s2.top();
				sum = top1 + top2 + carry;
				carry = sum / 10;
				digit = sum % 10;
				s1.pop();
				s2.pop();
				insert_before(ret, digit);
			}
			else if (s1.empty() && (!s2.empty())) {
				if (carry == 0)
				{
					//insert before
					while (!s2.empty())
					{
						int top = s2.top();
						insert_before(ret, top);
						s2.pop();
					}
					break;
				}
				int top = s2.top();
				sum = top + carry;
				carry = sum / 10;
				digit = sum % 10;
				s2.pop();
				insert_before(ret, digit);
			}
			else {
				if (carry == 0)
				{
					while (!s1.empty())
					{
						int top = s1.top();
						insert_before(ret, top);
						s1.pop();
					}
					break;
				}

				int top = s1.top();
				sum = top + carry;
				carry = sum / 10;
				digit = sum % 10;
				s1.pop();
				insert_before(ret, digit);
			}
		}
		if (carry != 0)
		{
			insert_before(ret, carry);
		}
		return ret;
	}

	void insert_before(ListNode * & node, int val)
	{

		if (!node)
		{
			node = new ListNode(val);
			return;
		}

		ListNode * newnode = new ListNode(val);
		newnode->next = node;
		node = newnode;
	}
};
//int main()
//{ 
//	LinkedList<int > l;
//	l.insertfront(2);
//	l.insertfront(4);
//	l.insertfront(6);
//	LinkedList<int >::print_list(l);
//	return 0;
//
//
//
//}