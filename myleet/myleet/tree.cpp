#include "pch.h"
#include "tree.h"
using namespace std;
//bianry tree diameter
struct treenode {
	struct treenode * l;
	struct treenode * r;
	int d;
};
static int max_height(treenode * root)
{
	if (!root)
	{
		return 0;
	}

	return max(max_height(root->l), max_height(root->r)) + 1;
}
static int diameter(const treenode * root)
{
	return max(max(diameter(root->l), diameter(root->r)), (max_height(root->l) + max_height(root->r) + 1));
}

//binary tree max_sum_level
static int max_sum_level(const treenode * root)
{
	queue<const treenode *> q;
	int level = 0;
	int max_sum = 0;
	int max_level = 0;
	int cur_sum = 0;
	q.push(root);
	const treenode * tmp;
	while (!q.empty())
	{
		tmp = q.front();
		q.pop();
		if (tmp)
		{
			cur_sum += tmp->d;
			if (tmp->l)
			{
				q.push(tmp->l);
			}

			if (tmp->r)
			{
				q.push(tmp->r);
			}
		}
		else {
			if (cur_sum > max_sum)
			{
				max_sum = cur_sum;
				max_level = level;
			}
			q.push(nullptr);
			cur_sum = 0;//reset to 0,start next level
			level++;
		}
	}

}
//int main()
//{
//	tree t;
//	t.insert(1);
//	cout <<boolalpha<<t.empty() << endl;
//	cout << t.size() << endl;
//	//tree::show(OD::POST, t);
//	//tree::show(OD::IN, t);
//	//tree::show(OD::PRE, t);
//	t.insert(2);
//	cout << t.size() << endl;
//}