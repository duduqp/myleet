#pragma once
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>

namespace dudu {
	const int maxlevel = 5;
	const std::vector<std::vector<int>> range{ {0,15 },{16,23},{24,27},{28,30},{31,31} };
	template<typename T>
	class skiplist {
		public:
			struct Node {
				int level;
				T data;
				struct Node * next[maxlevel];
				Node(const T & _data=T(), int _level = 0) :data(_data), level(_level) {
					std::fill(next, next + maxlevel, nullptr);
				}
			};
			
			Node * insert_elem(const T & elem)
			{
				struct Node * to_be_insert=header;
				struct Node * to_be_update[maxlevel + 1];
				for (int i = listlevel; i >= 0; i--)//from high to low level
				{
					while (to_be_insert->next[i] != header && to_be_insert->next[i]->data < elem)
					{
						to_be_insert = to_be_insert->next[i];//travel across
					}
					to_be_update[i] = to_be_insert;
				}

				to_be_insert = to_be_insert->next[0];
				//check from level 0 to high level
				if (to_be_insert->next[0] != header && to_be_insert->data == elem)
				{
					//already exists 
					return to_be_insert;
				}

				//build a tower
				int new_level = 0;
				//randomly ...
				while (rand(rand()) > RAND_MAX / 2&&new_level<=maxlevel)
				{
					new_level++;
				}

				//if higher than original list_level...
				if (new_level > listlevel)
				{
					for (int i = listlevel + 1; i <= new_level; i++)
					{
						to_be_update[i] = header;//dummy 
					}
				}

				listlevel = new_level;//record highest
				to_be_insert = new Node(elem);
				to_be_insert->data = elem;
				to_be_insert->level = new_level;
				for (int i = 0; i < new_level; ++i)
				{
					to_be_insert->next[i] = to_be_update[i]->next[i];//update each level
					to_be_update->next[i] = to_be_insert;
				}

				return to_be_insert;
			}

			skiplist():listlevel(0),header(new Node())
			{
				this->init();
			}

			Node * search(const T & elem)
			{
				int i;
				struct Node * tmp = header;
				for (i = listlevel; i >= 0; i--)//from high to low level
				{
					while (tmp->next[i] != header && tmp->next[i]->data < elem)
					{
						tmp = tmp->next[i];//travel across
					}
				}

				tmp = tmp->next[0];
				if (tmp->next[0] != header && tmp->data == elem)
				{
					//match 
					return tmp
				}

				return nullptr;//not match
			}


			Node * remove_elem(const T & elem)
			{
				struct Node * to_be_remove = header;
				struct Node * to_be_update[maxlevel + 1];
				for (int i = listlevel; i >= 0; i--)//from high to low level
				{
					//also can implement by adjust from node.level to bottom ... but these header dummies bring convinience
					while (to_be_remove->next[i] != header && to_be_remove->next[i]->data < elem)
					{
						to_be_remove = to_be_remove->next[i];//travel across
					}
					to_be_update[i] = to_be_remove;
				}

				to_be_remove = to_be_remove->next[0];
				if (to_be_remove == header || to_be_remove->data!=elem)
				{
					return nullptr;//not match
				}

				for (int i = 0; i < listlevel; ++i)
				{
					if (to_be_update[i]->next[i] != to_be_remove)
					{
						break;//because the bottom point next one by one! so the higher the sparser!
					}
					//change ptr
					to_be_update->next[i] = to_be_remove->next[i];
				}

				//update list level if any level is empty after delete
				while (listlevel > 0 && header->next[listlevel] == header)
				{
					listlevel--;
				}

				//delete the node
				delete to_be_remove;
				return header;
			}

			void display()
			{
				struct Node * tmp = header;
				int i = 0;
				while (tmp->next[0] != header)
				{
					std::cout << "node :" << i << " has ( " << tmp->level << " ) level(s) ";
					std::cout << " data :  " << tmp->data << "------>";
				}
				std::cout << " # \n";
	private:
		int listlevel;
		struct Node * header;
		
		void init()
		{
			//init in ctor
			for (int i = 0; i <= maxlevel; i++)
			{
				header->next[i] = header;
			}
		}

	};

}