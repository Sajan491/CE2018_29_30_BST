#include "bintreelinked.h"
#include<iostream>
using namespace std;

LinkedBST::LinkedBST(){
	root=NULL;
}

LinkedBST::~LinkedBST()

/*LinkedBST::void preordertraversal()
{


}*/



void LinkedBST::add(int data){
   Node *newNode=new Node();
   newNode->data=data;
   newNode->left=Null;
   newNode->right=NULL;

   if(root == Null){
        this->root = newNode;
   }
   else{
        this->add(root, newNode);
   }

}

void LinkedBST::add(Node *subTree, Node *newNode){
    if(data < subTree->data){
        if(subtree->left==NULL){
            subtree->left = newNode;
        }
        else{
            add(subtree->left,newNode);

        }
    }

    else{


    }

}



/*LinkedBST::bool searchh(int data){


}*/

int main(){
    LinkedBST li;
    li.add(2);
    li.add(3);


}
