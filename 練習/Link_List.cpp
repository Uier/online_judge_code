#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

int main()
{
//	���J�s�`�I	Ex: a -> b ���Jc 
	node newnode;
	newnode.next = a.next;
	a.next = newnode;
//  �R���`�I	Ex: a -> b -> c �R��b 
	node *delnode = b;
	a.next = b.next; 
	delete delnode;
	
	int *a = new int;
	*a = 2;
	
	return 0;
}

