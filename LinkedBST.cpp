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

bool LinkedBST::search(int data){}

int LinkedBST::maxx(){}

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

void LinkedBST::deleteitem(node *root,int data){
    if (!root){
        return;}
    else if (data<root->data){
        return deleteitem(root->left,int data)
    }
    else if(data>root->data){
        return deleteitem(root->left,int data)
    }
    else{
        if (root->left==NULL){
            root->right = root;
        }
        else if (root->right==NULL){
            root->left = root;
        }
        else{
            pass;
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



int LinkedBST::maxx(node *root){
    if(root->data == 0){
        cout<<"it is a null tree"<<endl;
    }
    else if(root->right == nullptr){
        return root->data;
    }
    else{
        maxx(root->right);
    }


}


int main(){
	LinkedBST tree1;
    int a;
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
    a = tree1.maxx(&tree1.root);
    cout<<"the max term in the tree is "<<a<<endl;

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
