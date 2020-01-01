#pragma once
#include <iostream>
template<class T>
class LinkedList {
private:
	struct LNode {
		LNode * n;
		T e;
		LNode(LNode * _n,T _e):e(_e),n(_n){ }
		LNode(T _e):n(nullptr),e(_e){ }
	};

	LNode * head;
	LNode * tail;
	int size;
public:
	 const int Size() const {
		return size;
	 }
	 bool isempty() const {
		return size == 0;
	 }
	 T Front() const {
		return head->n ? *(head->n) : head->e;
	 }
	 T Tail() const {
		return *tail;
	 }
	 void insertfront(T e)
	 {
		head->n= new LNode(head->n, e);
		size++;
	 }
	 void inserttail(T e)
	 {
		 tail->n = new LNode(nullptr, e);
		 tail = tail->n;
		 size++;
	  }
	  T removetail(T e)
	  {
		 T ret;
		 LNode * tmp = head;
		 while (tmp->n!=tail)
		 {
			 tmp = tmp->n;
		 }
		 ret = tail->e;
		 delete tail;
		 tail = tmp;
		 tail->n = nullptr;
		 return ret;
	}
	T removefront(T e)
	{
		  if (isempty())
		  {
			  return head->e;
		  }
		  T ret = head->n->e;
		  delete head->n;
		  head->n = head->n->n;
		  return ret;
	}
	static void print_list(const LinkedList<T> & l)
	{
		LNode * tmp = l.head;
		while(tmp)
		{
			std::cout << tmp->e <<"->" <<std::ends;
			tmp = tmp->n;
		}
		std::cout <<"#"<< std::endl;
	}

	void clear()
	{
		while (!isempty())
		{
			std::cout << removefront() << "be removed" << std::ends;
		}
	}

	LinkedList():head(new LNode(nullptr,T())),tail(head),size(0) { }
	LinkedList(const LinkedList<T> & l)
	{
		//deep copy
		copyfrom(l);
	}
	LinkedList<T> & operator=(const LinkedList<T> & l)
	{
		//deep copy
		copyfrom(l);
		return *this;
	}

	void copyfrom(const LinkedList<T> & l)
	{
		if (&l == this)
		{
			//self ref
			return;
		}
		clear();

		LNode * l_tmp = l.head;
		while (l_tmp->n)
		{
			insertfront(l_tmp->e);
			l_tmp = l_tmp->n;
		}
		tail = l_tmp;
	}
};

