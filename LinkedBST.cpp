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

void LinkedBST::deleteitem(int data){
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





void LinkedBST::deleteitem(node* root,int val){
	
	int dat;
	if(root==NULL){
		cout<<"tree is empty"<<endl;
		return;
	}
	if(search(root,val)==true){
		if(val<root->data){
			node* temp=new node();
			temp=root->left;
			if(root->left->data==val && root->left->left==NULL && root->left->right==NULL){
				root->left=NULL;
			}
			deleteitem(temp,val);
			return;
		}
		else if(val>root->data){
			node* temp=new node();
			temp=root->right;
			if(root->right->data==val && root->right->left==NULL && root->right->right==NULL){
				root->right=NULL;
			}
			deleteitem(temp,val);
			return;
		}
		else{
			if(root->left==NULL && root->right==NULL){
				delete root;
				root=NULL;
				return;
			}
			else if(root->left==NULL){
				node* temp=new node();
				temp=root->right;
				root->data=root->right->data;
				root->right=root->right->right;
				delete temp;
				return;
			}
			else if(root->right==NULL){
				node* temp=new node();
				temp=root->left;
				root->data=root->left->data;
				root->left=root->left->left;
				delete temp;
				return;
			}
			else{
				node* nodetoDelete=new node();
				nodetoDelete=root;
				node* newNode=new node();
				newNode=root->left;
				while(newNode->right!=NULL){
					newNode=newNode->right;
				}
				dat=newNode->data;
				deleteitem(nodetoDelete,newNode->data);
				root->data=dat;
				return;
			}
		}
	}
	
	else{
		cout<<"The node to be deleted not found in the tree\n";
		exit(0);
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
                
                return 1;

            }
            else{
                
                return 0;
            }
        }
    }

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
    int a,b,c;
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
	
	

	cout<<"Inorder Traversal of the tree is"<<endl;
	tree1.inordertraversal(&tree1.root);
	cout<<endl;
	
    a = tree1.maximum(&tree1.root);
    cout<<"the max term in the tree is "<<a<<endl;
    
    b = tree1.minimum(&tree1.root);
    cout<<"the min term in the tree is "<<b<<endl<<endl<<endl;
	

    tree1.deleteitem(&tree1.root,7);
    tree1.deleteitem(&tree1.root,5);
	cout<<"After deleting 5 and 7 "<<endl;
    cout<<"Inorder Traversal of the tree is"<<endl;
	tree1.inordertraversal(&tree1.root);
	cout<<endl;
	cout<<"Preorder Traversal of the tree is"<<endl;
	tree1.preordertraversal(&tree1.root);
	cout<<endl;

	int number;
	char character;
	bool s;
	search:
	cout<<"Enter any number you want to search for in the tree"<<endl;
	cin>>number;
	s=tree1.search(&tree1.root,number);
	if(s==1){cout<<number<<" " <<"is in the tree"<<endl;}
	else{cout<<number<<" " <<"is not in the tree"<<endl;}
	cout<<"Do you want to search again(y/n)??"<<endl;
	cin>>character;
	if((character=='y') || (character=='Y')) goto search;


	}
