#include "pch.h"
#include "tree.h"
using namespace std;


static int diameter(const tree & t)
{

	return 0;
}

int main()
{
	tree t;
	t.insert(1);
	cout <<boolalpha<<t.empty() << endl;
	cout << t.size() << endl;
	//tree::show(OD::POST, t);
	//tree::show(OD::IN, t);
	//tree::show(OD::PRE, t);
	t.insert(2);
	cout << t.size() << endl;
}