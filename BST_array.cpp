#include "BST_array.h"
#include<iostream>
using namespace std;

BST_array::BST_array(){
	for(int i=0;i<MAX_SIZE;i++){
		this->element[i]=0;
	}
}

BST_array::~BST_array(){

}

void BST_array :: preordertraversal(){
    int i = 1;
    cout<<element[i];
    preordertraversal(get_left_child(i));
    preordertraversal(get_right_child(i));
	cout<<endl;
}

void BST_array :: preordertraversal(int index){
    if(index != -1){
        cout<<", "<<element[index];
		preordertraversal(get_left_child(index));
 		preordertraversal(get_right_child(index));
    }
    
}

int BST_array :: get_left_child(int index){
    if(element[2*index]!=0 && 2*index<MAX_SIZE){
        return 2*index;
    }
    else return -1;
}

int BST_array :: get_right_child(int index){
    if(element[2*index + 1]!=0 && 2*index+1<MAX_SIZE){
        return 2*index + 1;
    }
    else return -1;
}

void BST_array::add(int data){
	if(this->element[0]==0){
		element[1]=data;
	}
	else{
		for(int i=1;i<=MAX_SIZE; ){
			if(data<this->element[i]){
				i=2*i;
			}
			else{
				i=2*i+1;
			}
			if(this->element[i]==0){
				this->element[i]=data;
				break;
			}
		}
	}
	this->element[0]=this->element[0]+1;
}

bool BST_array::search_value(int data){
	int current_index=1;
	while(current_index<=MAX_SIZE){
	    if(element[current_index]==data){
	        return true;
	        break;
	    }
	    else if(element[current_index]>data){
	        current_index=2*current_index;
	    }
	    else if(element[current_index]<data){
	        current_index=2*current_index+1;
	    }
	}
	return false;
}

int BST_array::minimum(){
	int temp;
	for(int i = 1; i<MAX_SIZE; ){
		if(this->element[2*i]!=0){
			temp = this->element[2*i];
		i = i * 2;
		}
		else break;
	}
	return temp;
}


int main(){
    BST_array a;	
	a.add(12);
	a.add(10);
	a.add(15);
	a.add(11);
	a.add(9);
	a.add(22);
	a.add(32);
	if(a.search_value(9)){
		cout<<"9 is in the BST."<<endl;
	}
	cout<<"The pre-order traversal of the tree is ";
	a.preordertraversal();
	cout<<"The minimum value in the tree is "<<a.minimum();
	return 0;
}


