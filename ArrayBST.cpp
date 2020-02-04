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
    cout<<element[i]<<endl;
    preordertraversal(get_left_child(i));
    preordertraversal(get_right_child(i));
}

void BST_array :: preordertraversal(int index){
    if(index != -1){
        cout<<element[index]<<endl;
    }
    preordertraversal(get_left_child(index));
    preordertraversal(get_right_child(index));
}

int BST_array :: get_left_child(int index){
    cout<<"left_child function "<<index<<endl;
    if(element[2*index]!=0){
        return 2*index;
    }
    else return -1;
}

int BST_array :: get_right_child(int index){
    cout<<"rigt_child function"<<endl;
    if(element[2*index + 1]!=0){
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
	cout<<"I";
	return 0;
}


int main(){
    BST_array a;
    a.add(40);
    a.add(5);
    a.add(71);
    a.add(17);
    if(a.search_value(17)){
        cout<<"The value 17 is in the tree."<<endl;
    }
    a.preordertraversal();
	return 0;
}


