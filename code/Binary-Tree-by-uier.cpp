#include <iostream>
using namespace std;
struct node {
	int data;
	node *left;
	node *right;
};
node *root;
void insert(node **R, int v) {
	if ( *R == NULL ) {
		node *tmp = new node;
		tmp->data = v;
		tmp->left = NULL;
		tmp->right = NULL;
		*R = tmp;
	}
	else if ( v < (*R)->data )
		insert(&(*R)->left,v);
	else if ( v > (*R)->data )
		insert(&(*R)->right,v);
}
void preorder(node *R) {
	if ( R == NULL )	return;
	cout << R->data << ' ';
	preorder(R->left);
	preorder(R->right);
}
void inorder(node *R) {
	if ( R == NULL )	return;
	inorder(R->left);
	cout << R->data << ' ';
	inorder(R->right);
}
void postorder(node *R) {
	if ( R == NULL )	return;
	postorder(R->left);
	postorder(R->right);
	cout << R->data << ' ';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	root = NULL;
	int n, d;
	cin >> n;
	while ( n-- ) {
		cin >> d;
		insert(&root,d);
	}
	cout << "preorder-----------\n";
	preorder(root);
	cout << "\ninorder-----------\n";
	inorder(root);
	cout << "\npostorder-----------\n";
	postorder(root);
	cout << '\n';
	return 0;
}

