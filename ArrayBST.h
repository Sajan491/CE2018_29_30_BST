#include "BinaryTree.h"

#define MAX_SIZE 20

class ArrayBST : public BinarySearchTree{
	private:
		int element[MAX_SIZE];
	public:
		ArrayBST();
		void preordertraversal();
		void preordertraversal(int index);
		void add(int data);
		bool search(int data);
		int get_left_child(int index);
		int get_right_child(int index);
};
