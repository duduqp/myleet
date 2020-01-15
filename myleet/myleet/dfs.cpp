#include "pch.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void dfs(vector<vector<int>> &ret, vector<int>& cur, vector<int>& candidates, int target, int index);

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> ret;
	if (candidates.empty())
	{
		return ret;
	}
	sort(candidates.begin(), candidates.end());
	if (target < candidates[0])
	{
		return ret;
	}

	candidates.erase(remove_if(candidates.begin(), candidates.end(), [target](const int & i)
	{
		return i > target;
	}), candidates.end());

	//dfs
	vector<int > cur;
	std::cout << candidates.size() << std::endl;
	dfs(ret, cur, candidates, target, candidates.size() - 1);
	return ret;
}

void dfs(vector<vector<int>> &ret, vector<int>& cur, vector<int>& candidates, int target, int index)
{
	if (index < 0 || target < 0)
	{
		return;
	}

	if (target == 0)
	{
		std::cout << "\n";
		for_each(cur.begin(), cur.end(), [](const int & i) {std::cout << i << " "; });
		ret.push_back(cur);
		return;
	}

	
		cur.push_back(candidates[index]);
		dfs(ret, cur, candidates, target - candidates[index], index - 1);
		cur.pop_back();
		dfs(ret, cur, candidates, target, index - 1);
	

}
int main(void)
{
	combinationSum2({ 10,1,2,7,6,1,5 }, 8);
	return 0;
}