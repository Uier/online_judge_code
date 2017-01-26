#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

int main()
{
//	插入新節點	Ex: a -> b 插入c 
	node newnode;
	newnode.next = a.next;
	a.next = newnode;
//  刪除節點	Ex: a -> b -> c 刪除b 
	node *delnode = b;
	a.next = b.next; 
	delete delnode;
	
	int *a = new int;
	*a = 2;
	
	return 0;
}

