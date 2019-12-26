#include "ArrayBST.h"
#include <iostream>

ArrayBST::ArrayBST(){
	elements[0] = 0;
}

void ArrayBST::preordertraversal(){
	
}

void ArrayBST::add(int data){
	if(this->elements[0]==0){
		elements[1]=data;
	}
	else{
		for(int i=1;i<=MAX_SIZE; ){
			if(data<this->elements[i]){
				i=2*i;
			}
			else{
				i=2*i+1;
			}
			if(this->elements[i]==0){
				this->elements[i]=data;
				break;
			}
		}
	}
	this->elements[0]=this->elements[0]+1;
}

bool ArrayBST::search(int data){
	//fgghf
	std::cout<<"saa";
}

int main(){
	ArrayBST a;
	a.add(5);
	a.add(7);
	return 0;
}
