#ifndef BINARYTREE_h
#define BINARYTREE_h


class BinarySearchTree{
	public:
		virtual void preordertraversal()=0;
		virtual void add(int data)=0;
		virtual bool search_value(int data)=0;
		//virtual int maxx() = 0;
		virtual int minimum() = 0;
};
#endif
