#pragma once
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <stdexcept>
#include <exception>
#include <queue>
namespace dudu {
	template<typename T>
	class sharedstack {
		/*
		implement a double stack shared single vector<T> with fix size

		*/
	public:
		sharedstack() = default;
		sharedstack(const T & defaultval, int _size = 32) :data(std::vector<T>(_size, defaultval)), size(_size)
			, sl(0), sr(0) {

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


	template<typename T>
	class MinStack {
	public:
		MinStack() = default;
		T Top() const
		{
			if (mainstack.empty())
			{
				throw std::runtime_error("stack is empty!");
			}
			return mainstack.top();
		}

		T Pop()
		{
			if (mainstack.empty())
			{
				throw std::runtime_error("stack is empty!");
			}
			while(mainstack.top() < minstack.top())
			{
				minstack.pop();
			}
			T ret = mainstack.top();
			mainstack.pop();
			return ret;
		}

		void Push(const T & t)
		{
			if (minstack.empty() || t < minstack.top())
			{
				minstack.push(t);
			}
			mainstack.push(t);
		}

		T GetMin() const
		{
			if (minstack.empty())
			{
				throw std::runtime_error("stack is empty!");
			}
			return minstack.top();
		}
	private:
		std::stack<T> mainstack;
		std::stack<T> minstack;

	};

	template<typename T>
	class qqStack{
	public:
		qqStack() = default;
		T Top() const  {
			if (qa.empty())
			{
				throw std::runtime_error("stack is empty!");
			}
			return top;
		}


		T Pop() {
			if (qa.empty())
			{
				throw std::runtime_error("stack is empty!");
			}
			T ret = top;
			while (qa.size() > 2)
			{
				qb.push(qa.top());
				qa.top();
			 }

			top = qa.front();
			qa.pop();
			qa.pop();
			while (!qb.empty())
			{
				qa.push(qb.top());
				qb.pop();
			}

			return ret;
		}

		void Push(const T & t) {
			top = t;
			qa.push(t);
		}



	private:
		T top;//cache the top
		std::queue<T> qa;
		std::queue<T> qb;//aux

	};
}