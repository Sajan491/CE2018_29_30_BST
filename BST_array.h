#include "BinaryTree.h"

#define MAX_SIZE 20

class BST_array : public BinarySearchTree {
    private:
        int element[MAX_SIZE];

    public:
        BST_array();
        ~BST_array();
        void preordertraversal();
        void preordertraversal(int index);
        void add(int data);
        bool search_value(int data);
        int minimum();
        int maxx(){}
        int get_left_child(int index);
        int get_right_child(int index);
};

