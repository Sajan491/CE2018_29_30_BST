//Binary tree

#ifndef BinaryTree_h
#define BinaryTree_h

class BinarySearchTree {
    public:
        virtual void preordertraversal()=0;
        virtual void add(int data)=0;
        virtual bool search(int data)=0;
};

#endif
