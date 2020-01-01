#include "pch.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int min_path(const vector<vector<int> > & v)
{
	int col = v[0].size();
	int row = v.size();
	vector<int> aux(min(col,row),0);
	//dp status compress
	aux[0] = v[0][0];
	if (col > row)
	{
		//initial boundary
		
		for (int i = 1; i < row; ++i)
		{
			aux[i] = aux[i - 1] + v[i][0];
		}
		for (int i = 0; i < col ;++i)
		{
			//update by col
			aux[0] = aux[0] + v[0][i];
			for (int j = 1 ; j<row;++j)
			{
				aux[j] = min(aux[j], aux[j - 1]);//(aux[j - 1] > aux[j]) ? aux[j] : aux[j - 1]
				aux[j] += v[j][i];
			}
		}
	}
	else {
		//initial boundary

		for (int i = 1; i < col; ++i)
		{
			aux[i] = aux[i - 1] + v[0][i];
		}
		for (int i = 0; i < row; ++i)
		{
			//update by col
			aux[0] = aux[0] + v[i][0];
			for (int j = 1; j < col; ++j)
			{
				aux[j] = min(aux[j], aux[j - 1]);//(aux[j - 1] > aux[j]) ? aux[j] : aux[j - 1]
				aux[j] += v[i][j];
			}
		}
	}
	return aux.back();
}

int min_with_stride(const vector<vector<int> > & v, const vector<int > & stride)
{
	//different with previous , update by stride 
	//with status compress,in direction of non_stride!

	return 0;




}