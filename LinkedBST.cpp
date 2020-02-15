#include"LinkedBST.h"
#include<iostream>
using namespace std;

node::node(){
    data=0;
    left=right=nullptr;
}

node::node(int value){
    data=value;
    left=right=nullptr;
}

node::~node(){}


LinkedBST::LinkedBST(){
}

LinkedBST::~LinkedBST(){}

void LinkedBST::add(int data){
}

void LinkedBST::preordertraversal(){}
void LinkedBST::inordertraversal(){}

bool LinkedBST::search(int data){}

int LinkedBST::maximum(){}

int LinkedBST::minimum(){}

void LinkedBST::add(node *root,int data){
if (root->data==0){
    root->data=data;
}else{
        if (data < root->data){
            if (!root->left){
                node *newnode=new node(data);
                root->left=newnode;
            }
            else{
                add(root->left,data);
            }
        }
        else if (data > root->data){
            if (!root->right){
                node *newnode=new node(data);
                root->right=newnode;
            }
            else{
                add(root->right,data);
            }
        }
    }
}


bool LinkedBST::search(node *root,int targetKey){
    if(root->data==0){
        cout<<"It is an empty tree"<<endl;
    }
    else{
        node *p=new node();
        p=root;
        while(p){
            if(targetKey>p->data){
                p=p->right;
            }
            else if(targetKey<p->data){
                p=p->left;
            }
            else if(targetKey==p->data){
                cout<<targetKey<<" is in the tree"<<endl;
                return 1;

            }
            else{
                cout<<targetKey<<" is not in the tree"<<endl;
                return 0;
            }
        }
    }
    cout<<targetKey<<" is not in the tree"<<endl;
    return 0;
}


void LinkedBST::preordertraversal(node* root) {
    if (!root)
    return;


    cout << root->data << "\t";


    preordertraversal(root->left);


    preordertraversal(root->right);
}

void LinkedBST::inordertraversal(node* root) {
    if (!root)
    return;


    inordertraversal(root->left);

    cout << root->data << "\t";


    inordertraversal(root->right);
}



int LinkedBST::maximum(node *root){
    if(root->data == 0){
        cout<<"it is a null tree"<<endl;
    }
    else if(root->right == nullptr){
        return root->data;
    }
    else{
        maximum(root->right);
    }


}

int LinkedBST::minimum(node *root){
    if(root->data == 0){
        cout<<"it is a null tree"<<endl;
    }
    else if(root->left == nullptr){
        return root->data;
    }
    else{
        minimum(root->left);
    }


}



int main(){
	LinkedBST tree1;
    int a,b;
	tree1.add(&tree1.root,6);
	tree1.add(&tree1.root,4);
	tree1.add(&tree1.root,7);
	tree1.add(&tree1.root,2);
	tree1.add(&tree1.root,9);
	tree1.add(&tree1.root,5);
	tree1.add(&tree1.root,3);
	tree1.add(&tree1.root,11);
	cout<<"Preorder Traversal of the tree is"<<endl;
	tree1.preordertraversal(&tree1.root);
	cout<<endl;
    a = tree1.maximum(&tree1.root);
    cout<<"the max term in the tree is "<<a<<endl;
    
    b = tree1.minimum(&tree1.root);
    cout<<"the min term in the tree is "<<b<<endl;


	int number;
	char character;
	search:
	cout<<"Enter any number you want to search for in the tree"<<endl;
	cin>>number;
	tree1.search(&tree1.root,number);
	cout<<"Do you want to search again(y/n)??"<<endl;
	cin>>character;
	if((character=='y') || (character=='Y')) goto search;


}
