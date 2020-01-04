#pragma once
#include <iostream>
#include <memory>
#include <algorithm>
using namespace std;
class tree
{
public:
	struct node {
		struct node *l;
		struct node *r;
		struct node *f;
		int d, h;
		node(struct node *_l, struct node *_r,int _d,int _h,struct node * _f):l(_l),r(_r),d(_d),h(_d),f(_f){ }
	};

	static void rotate_LL(node * root)
	{

	}

	tree(){}
	tree(const tree & rhs)
	{

	}
	~tree()
	{

	}

	tree & operator=(const tree & rhs)
	{

	}
	const int height() const
	{
		return root->h;
	}

	const bool empty() const {
		return _size == 0;
	}

	const int size() const {
		return _size;

	}

	bool contains(int d) {
		return search(d) == nullptr;
	}

	void insert(int d)
	{

	}

	void remove(int d)
	{

	}

	node * search(int d)
	{

	}

private:
	node * root;
	int _size;

	//auxiliary
	node * search_at(node * root, int d)
	{
		if (!root)
		{
			return root;
		}
		if (root->d == d)
		{
			return root;
		}
		else if (root->d < d)
		{
			return search_at(root->r,d);
		}
		else {
			return search_at(root->l, d);
		}
	}

	node * insert_at(node * &root, int d)
	{
		if (!root)
		{
			root = new node(nullptr, nullptr, d, 1,root);
		}
		else if (root->d == d)
		{
			;
		}
		else if (root->d < d)
		{
			root->r = insert_at(root->r, d);
		}
		else {
			root->l = insert_at(root->l, d);
		}
		return root;
	}
	
	node * remove_at(node * root, int d)
	{
		node * tmp = search_at(root,d);
		if (!tmp)
		{
			return root;
		}
		node * f = tmp->f;
		if ((!tmp->l) && ((!tmp->r)))
		{
			//leaf
			if (tmp == tmp->f->l)
			{
				//be a left child
				f->l = nullptr;
			}
			else {
				//be a right child
				f->r = nullptr;
			}

			delete tmp;
		}
		else if (tmp->l&&(!tmp->r))
		{
			//has left child but not a right child
			if (tmp == f->l)
			{
				f->l = tmp->l;
			}
			else {
				f->r = tmp->l;
			}

			delete tmp;
		}
		else if (tmp->r && (!tmp->l))
		{
			//has left child but not a right child
			if (tmp == f->l)
			{
				f->l = tmp->r;
			}
			else {
				f->r = tmp->r;
			}

			delete tmp;
		}
		else {
			//two children
			//find precedentor on right subtree
			node * precedentor = tmp->r;
			while (precedentor->l)
			{
				precedentor = precedentor->l;
			}

			tmp->d = precedentor->d;
			remove_at(tmp->r, precedentor->d);
		}
	}

	int height_update(node * root)
	{
		if (!root)
		{
			return 0;
		}
		else {
			root->h = max(height_update(root->l), height_update(root->r)) + 1;
			return root->h;
		}
	}
};