#pragma once
#include <vector>
#include <algorithm>
#include <utility>
namespace dudu {
	template<typename T>
	class sharedstack {
		/*
		implement a double stack shared single vector<T> with fix size
		
		*/
	public:
		sharedstack() = default;
		sharedstack(const T & defaultval, int _size = 32) :data(std::vector<T>(_size, defaultval)), size(_size)
		,sl(0),sr(0){

		}

		sharedstack(const sharedstack<T> & rhs)
		{
			using std::swap;
			std::vector<T> tmp = rhs.data;
			swap(data, tmp);
			this->size = rhs.size;
			this->sl = rhs.sl;
			this->sr = rhs.sr;
		}

		int push_left(const T & elem)
		{
			if (sl + sr > size)
			{
				return -1;
			}
			else
			{
				data[sl++] = elem;
				return 0;
			}
		}

		int pop_left()
		{
			if (sl == 0)
			{
				return -1;
			}
			else
			{
				sl--; 
			}
		}

		int push_right(const T & elem)
		{
			if (sl + sr == size)
			{
				return -1;
			}
			else {
				data[size - sr - 1] = elem;
				sr++;
				return 0;
			}
		}

		int pop_right()
		{
			if (sr == 0)
			{
				return -1;
			}
			else {
				sr--;
			}
		}

		const T top_left()
		{

		}
	private:
		std::vector<T> data;
		int size;
		int sl;
		int sr;
	};




}