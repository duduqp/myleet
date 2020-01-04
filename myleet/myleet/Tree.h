#pragma once
#include <stdexcept>
#include <exception>
#include <algorithm>
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
		return search_at(tmp, d);
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
		if ((ret=search_at(tmp,d)))
		{
			//already exists
			return ret;
		}
		//not exists ,note the tmp cursor has moved to the proper node to insert
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

	TreeNode * search_at(TreeNode *& root, int d)
	{
		while (root)
		{
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
	void update_height(TreeNode * root)
	{
		if (root->l&&root->r)
		{
			root->h = max(root->l->h, root->r->h) + 1;
		}
		else if (root->l)
		{
			root->h = root->l->h + 1;
		}
		else if(root->r){
			root->h = root->r->h + 1;
		}
		else {
			root->h = 1;
		}
	}
	
	TreeNode * root;
	int _size;
};

