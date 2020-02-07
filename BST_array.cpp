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
    cout<<"The pre-order traversal of the tree is ";
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

void BST_array::inordertraversal(){

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

void BST_array::deleteitem(int data){
	int left_subtree, right_subtree;
	bool value_found = false;
	for(int i=1;i<MAX_SIZE;i++){
		if(data==this->element[i]){
			left_subtree = get_left_child(i);
			right_subtree =  get_right_child(i);
			if(left_subtree!=-1){
				right_subtree = get_right_child(left_subtree);
				while(right_subtree!=-1){
					right_subtree = get_right_child(right_subtree);
				}
				cout<<this->element[i]<<" is to be deleted now."<<endl;
				this->element[i] = this->element[right_subtree];
				this->element[right_subtree] = 0;
			}
			else if(right_subtree!=-1){
				left_subtree = get_left_child(right_subtree);
				while(left_subtree!=-1){
					left_subtree = get_left_child(left_subtree);
				}
				cout<<this->element[i]<<" is to be deleted now."<<endl;
				this->element[i] = this->element[left_subtree];
				this->element[left_subtree] = 0;
			}
			else{
				cout<<this->element[i]<<" is to be deleted now."<<endl;
				this->element[i] = 0;
			}
			value_found = true;
		}
	}
	if(!value_found){
		cout<<"The value "<<data<<" you entered for deletion is not in the tree."<<endl;
	}
	this->element[0]--;
}

bool BST_array::search(int data){
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

int BST_array::maximum(){
	int temp;
	 for(int i = 0; i<MAX_SIZE; ){
	 	if(this->element[2*i+1] && (2*i+1 < MAX_SIZE)){
	 		temp = this->element[2*i+1];
	 		i = i * 2 + 1;
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
	a.add(2);
	if(a.search(9)){
		cout<<"9 is in the BST."<<endl;
	}
	a.preordertraversal();
	cout<<"The minimum value in the tree is "<<a.minimum()<<endl;
	cout<<"The maximum value in the tree is "<<a.maximum()<<endl;
	a.deleteitem(11);
	a.preordertraversal();
	a.deleteitem(23);
	return 0;
}


