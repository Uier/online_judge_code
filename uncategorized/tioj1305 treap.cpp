#include <iostream>
#include <time.h>
#include <map>
using namespace std;
int cnt = 0;
map<int,bool> M;
struct node {
	int key, pri, sz;
	node *l, *r;
	node(int val) {
		key = val;
		pri = rand();
		sz = 1;
		l = r = NULL;
	}
	void pull() {
		sz = 1;
		if ( l )	sz += l->sz;
		if ( r )	sz += r->sz;
	}
	~node() {
		if ( l )	delete l;
		if ( r )	delete r;
	}
} *root;
node *merge(node *a, node *b) { // key a < b
	if ( !a )	return b;
	if ( !b )	return a;
	if ( a->pri > b->pri ) {
		a->r = merge(a->r,b);
		a->pull();
		return a;
	} else {
		b->l = merge(a,b->l);
		b->pull();
		return b;
	}
}
void split1(node *s, node *&a, node *&b, int k) {
	if ( !s ) {
		a = b = nullptr;
		return;
	}
	if ( s->key <= k ) {
		a = s;
		split1(s->r,a->r,b,k);
//		a->pull();
	} else {
		b = s;
		split1(s->l,a,b->l,k);
//		b->pull();
	}
	s->pull();
}
void split2(node *s, node *&a, node *&b, int k) {
	if ( !s ) {
		a = b = nullptr;
		return;
	}
	int lsz = 1;
	if ( s->l )	lsz += s->l->sz;
	if ( lsz <= k ) {
		a = s;
		split2(s->r,a->r,b,k-lsz);
//		a->pull();
	} else {
		b = s;
		split2(s->l,a,b->l,k);
//		b->pull();
	}
	s->pull();
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(NULL));
	int x;
	string s;
	while ( cin >> s && s[0] != 'e' && cin >> x ) {
		if ( s[0] == 'i' ) { // insert
			if ( M[x] )	continue;
			node *a, *b, *c;
			split1(root,a,c,x);
			b = new node(x);
			root = merge(merge(a,b),c);
			M[x] = 1;
			cnt++;
		} else if ( s[0] == 'r' ) { // remove
			if ( !M[x] ) continue;
			node *a, *b, *c;
			split1(root,a,b,x-1);
			split1(b,b,c,x);
			delete b;
			root = merge(a,c);
			M[x] = 0;
			cnt--;
		} else { // query rank k
			if ( x > cnt || x < 1 )	cout << "error\n";
			else {
				node *a, *b, *c;
				split2(root,a,b,x-1);
				split2(b,b,c,1);
				cout << b->key << '\n';
				root = merge(merge(a,b),c);
			}
		}
	}
	return 0;
}

