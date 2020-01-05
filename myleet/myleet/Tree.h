#pragma once
#include <iostream>
#include <memory>
#include <algorithm>
#include <stack>
#include <memory>
using namespace std;
enum OD {
	PRE,IN,POST,LEVEL
};
class tree
{
public:
	struct node {
		struct node *l;
		struct node *r;
		struct node *f;
		int d, h;
		node(struct node *_l, struct node *_r, int _d, int _h, struct node * _f) :l(_l), r(_r), d(_d), h(_d), f(_f) { }
	};

	static void show(OD od,node * root)
	{
		stack<node *> s;
		switch (od)
		{
			node * tmp=root;
		case OD::PRE:
			s.push(tmp);
			while (!s.empty())
			{
				tmp = s.top();
				s.pop();
				while (tmp)
				{
					cout << tmp->d << ends;
					if (tmp->r)
					{
						s.push(tmp->r);
						tmp = tmp->l;
					}
				}
			}
			break;
		case OD::IN:
			s.push(root);
			while (!s.empty()||tmp)
			{
				while (tmp)
				{
					s.push(tmp);
					tmp = tmp->l;
				}
				if (s.empty())
				{
					break;
				}
				tmp = s.top();
				s.pop();
				cout << tmp->d << ends;
				tmp = tmp->r;
			}
			break;
		case OD::POST:
			node * aux=nullptr;
			s.push(tmp);
			while (!s.empty())
			{
				tmp = s.top();
				if (tmp->l&&aux != tmp->l&&aux!=tmp->r)
				{
					s.push(tmp->l);
				}
				else if (tmp->r&&aux != tmp->r)
				{
					s.push(tmp->r);
				}
				else {
					cout << tmp->d << ends;
					aux = tmp;
					s.pop();
				}
			}
			break;
		default:

		}



	}
	
	static void reconstruct(node * &root, node * &rl, node *&rr, node *&rll, node *&rlr, node *&rrl, node *&rrr)
	{
		root->l = rl;
		root->r = rr;
		rl->l = rll;
		rl->r = rlr;
		rr->l = rrl;
		rr->r = rrr;
	}

	tree() :root(nullptr), _size(0) { }
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
		insert_at(root, d);
	}

	void remove(int d)
	{
		remove_at(root, d);
	}

	node * search(int d)
	{
		return search_at(root, d);
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
			return search_at(root->r, d);
		}
		else {
			return search_at(root->l, d);
		}
	}

	node * insert_at(node * &root, int d)
	{
		if (!root)
		{
			root = new node(nullptr, nullptr, d, 1, root);
		}
		else if (root->d == d)
		{
			return root;
		}
		else if (root->d < d)
		{
			root->r = insert_at(root->r, d);
		}
		else {
			root->l = insert_at(root->l, d);
		}
		_size++;
		return root;
	}

	node * remove_at(node * root, int d)
	{
		node * tmp = search_at(root, d);
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
			_size--;
			delete tmp;
		}
		else if (tmp->l && (!tmp->r))
		{
			//has left child but not a right child
			if (tmp == f->l)
			{
				f->l = tmp->l;
			}
			else {
				f->r = tmp->l;
			}
			_size--;
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
			_size--;
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
			tmp->r=remove_at(tmp->r, precedentor->d);
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