#pragma once
/*
implement a binary search tree
*/
class Tree
{
public:
	struct TreeNode {
		struct TreeNode * l;
		struct TreeNode * r;
		char d;
		int h;
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
	const void display() const {
		//based on traverse procedure
		;
	}
	virtual ~Tree();
private:
	TreeNode * root;
	int _size;
};

