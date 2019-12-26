#include "BinaryTree.h"

#define MAX_SIZE 20

class ArrayBST : public BinarySearchTree{
	private:
		int elements[MAX_SIZE];
	public:
		ArrayBST();
		void preordertraversal();
		void add(int data);
		bool search(int data);
};
