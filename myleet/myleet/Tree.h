#pragma once
#include <stdexcept>
#include <exception>
#include <algorithm>
#include <memory>
#include <stack>
#include <utility>
#include <iostream>
using namespace std;
/*
implement a binary search tree
*/
enum OD {
	PRE,IN,POST,LEVEL
};
class Tree
{
public:
	struct TreeNode {
		struct TreeNode * l;
		struct TreeNode * r;
		int d;
		int h;
		TreeNode(struct TreeNode * _l, struct TreeNode * _r, int _d
			, int _h) :l(_l), r(_r), d(_d), h(_h) { }
		
	};
	Tree();

	const int height() const {
		if (!root)
		{
			//empty
			return 0;
		}
		else {
			return root->h;
		}
	}
	const int size() const {
		return _size;
	}
	const void display(OD od) const {
		//based on traverse procedure
		switch (od) {
		case OD::PRE:

			break;
		case OD::IN:
			break;
		case OD::POST:
			break;

		default :

		}
	}

	TreeNode * search(int d){
		TreeNode * tmp=root;
		stack<shared_ptr<Tree::TreeNode> > s;
		return search_at(tmp, d,s);
	}
	void insert(int d)
	{
		TreeNode * tmp = root;
		if (!insert_at(tmp, d)) { 
			throw invalid_argument("no such elem");
		}
	}

	void remove(int d)
	{
		TreeNode * tmp = root;
		if (!remove_at(tmp, d))
		{
			throw invalid_argument("no such elem");
		}
	}

	virtual ~Tree();
private:
	TreeNode * insert_at(TreeNode * root, int d)
	{
		TreeNode * tmp = root;
		TreeNode * ret = root;
		stack<shared_ptr<Tree::TreeNode> > s;
		if ((ret=search_at(tmp,d,s)))
		{
			//already exists
			return ret;
		}
		//not exists ,note the tmp cursor has moved to the proper node to insert,and stack cache the path
		cout << s.size() << endl;
		if (tmp->d < d)
		{
			//insert at right
			tmp->r = new TreeNode(nullptr, nullptr, d, 1);
			return tmp->r;
		}
		else {
			tmp->l = new TreeNode(nullptr, nullptr, d, 1);
			return tmp->l;
		}
	}

	TreeNode * remove_at(TreeNode * r, int d)
	{



	}

	TreeNode * search_at(TreeNode *& root, int d,stack<shared_ptr<Tree::TreeNode> > &s)
	{
		while (root)
		{
			auto p = make_shared<Tree::TreeNode>(*root);
			s.push(p);
			if (root->d == d)
			{
				return root;
			}
			else if (root->d > d)
			{
				if (root->l)
				{
					root = root->l;
				}
				else {
					//no left child
					return nullptr;
				}
			}
			else {
				if (root->r)
				{
					root = root->r;
				}
				else {
					return nullptr;
				}
			}
		}
	}
	int height(TreeNode * root)
	{
		if (!root)
		{
			return 0;
		}
		root->h = max(height(root->l), height(root->r)) + 1;
		return root->h;		
	}
	
	TreeNode * root;
	int _size;
};

