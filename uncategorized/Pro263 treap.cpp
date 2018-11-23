#include <iostream>
#include <stdlib.h>
#include <time.h>
#define maxn 100005
using namespace std;
int arr[maxn];
struct node;
node *mn;
struct node {
	node *l, *r;
	int pri, val, mx, sz;
	node(int v) {
		val = mx = v;
		pri = rand();
		l = r = mn;
		sz = 1;
	}
	void pull() {
		sz = l->sz + r->sz + 1;
		mx = max(max(l->mx,r->mx),val);
	}
	~node() {
		if ( l != mn )	delete l;
		if ( r != mn )	delete r;
	}
};
node *merge(node *a, node *b) { // key: a < b
	if ( a == mn )	return b;
	if ( b == mn )	return a;
	if ( a->pri > b->pri ) {
		a->r = merge(a->r,b);
		a->pull();
		return a;
	}
	b->l = merge(a,b->l);
	b->pull();
	return b;
}
void split(node *s, node *&a, node *&b, int k) {
	if ( s == mn ) {
		a = b = mn;
		return;
	}
	if ( s->l->sz < k ) {
		a = s;
		split(s->r,s->r,b,k-(s->l->sz+1));
	} else {
		b = s;
		split(s->l,a,s->l,k);
	}
	s->pull();
}
node *build(int l, int r) {
	if ( l == r )	return new node(arr[l]);
	int mid = l+r>>1;
	return merge(build(l,mid),build(mid+1,r));
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(0));
	int n, q, t, x, y;
	mn = new node(-2e9);
	mn->sz = 0;
	while ( cin >> n >> q ) {
		for ( int i=0; i<n; ++i )	cin >> arr[i];
		node *root = build(0,n-1);
		while ( q-- && cin >> t >> x ) {
			if ( t == 4 ) {
				node *a, *b, *c;
				split(root,a,b,x-1);
				split(b,b,c,1);
				delete b;
				root = merge(a,c);
			} else {
				cin >> y;
				if ( t == 1 ) {
					node *a, *b, *c;
					split(root,a,b,x-1);
					split(b,b,c,1);
					delete b;
					b = new node(y);
					root = merge(merge(a,b),c);
				} else if ( t == 2 ) {
					node *a, *b, *c;
					split(root,a,c,y);
					split(a,a,b,x-1);
					cout << b->mx << '\n';
					root = merge(merge(a,b),c);
				} else {
					node *a, *b, *c;
					split(root,a,b,x-1);
					c = new node(y);
					root = merge(merge(a,c),b);
				}
			}
		}
		delete root;
	}
	return 0;
}

