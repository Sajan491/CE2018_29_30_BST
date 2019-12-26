#ifndef bintreelinked.h
#define bintreelinked.h
#include<iostream>
#include "BinaryTree.h"
using namespace std;


class Node{
    public:
        int data;
        Node *right;
        Node *left;

};

class LinkedBST:public BinaryTree{
    private:
        Node *root;

    public:
        lindedBST();
        ~ lindedBST();

        void preordertraversal();
        void add(int data);
        void add(Node *subTree, Node *newNode);
        bool searchh(int data);
};

#endif
