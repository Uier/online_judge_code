#include <iostream>
#include <time.h>
using namespace std;
struct node {
	node *l, *r;
	int pri, val, sz, sum, ans, pre, suf, chg;
	bool rev_tag, chg_tag;
	node(int v) {
		val = sum = ans = pre = suf = v;
		pri = rand();
		l = r = nullptr;
		sz = 1;
		rev_tag = chg_tag = chg = 0;
	}
	void REV() {
		if ( this == nullptr )	return;
		swap(l,r);
		rev_tag = !rev_tag;
	}
	void CHG(int v) {
		if ( this == nullptr )	return;
		val = chg = v;
		sum = v*sz;
		ans = pre = suf = max(v,sum);
		chg_tag = true;
	}
	void pull() {
		sz = 1;
		sum = ans = pre = suf = val;
		if ( l != nullptr ) {
			sz += l->sz;
			sum += l->sum;
			ans = max(l->suf+pre,max(l->ans,ans));
			pre = max(l->pre,l->sum+pre);
			suf = max(suf,l->suf+sum);
		}
		if ( r != nullptr ) {
			sz += r->sz;
			sum += r->sum;
			ans = max(suf+r->pre,max(ans,r->ans));
			pre = max(pre,sum+r->pre);
			suf = max(suf+r->sum,r->suf);
		}
	}
	void push() {
		if ( rev_tag ) {
			l->REV();
			r->REV();
			rev_tag = !rev_tag; // false
		}
		if ( chg_tag ) {
			l->CHG(chg);
			r->CHG(chg);
			chg_tag = false;
		}
	}
	~node() {
		if ( l != nullptr )	delete l;
		if ( r != nullptr )	delete r;
	}
} *root = nullptr;
int SZ(node *p) {
	return (p == nullptr ? 0 : p->sz);
}
node *merge(node *a, node *b) {
	if ( a == nullptr )	return b;
	if ( b == nullptr )	return a;
	if ( a->pri > b->pri ) {
		a->push();
		a->r = merge(a->r,b);
		a->pull();
		return a;
	} else {
		b->push();
		b->l = merge(a,b->l);
		b->pull();
		return b;
	}
}
void split(node *p, node *&a, node *&b, int k) {
	if ( p == nullptr ) {
		a = b = nullptr;
		return;
	}
	p->push();
	if ( SZ(p->l) < k ) {
		a = p;
		split(p->r,p->r,b,k-(SZ(p->l)+1));
	} else {
		b = p;
		split(p->l,a,p->l,k);
	}
	p->pull();
}
int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	srand(time(NULL));
	int n, m, x, y, z;
	string s;
	cin >> n >> m;
	for ( int i=0; i<n; ++i ) {
		cin >> x;
		node *a = new node(x);
		root = merge(root,a);
	}
	while ( m-- && cin >> s ) {
		if ( s[0] == 'I' ) { // insert
			cin >> x >> y;
			while ( y-- && cin >> z ) {
				node *a, *b, *c;
				split(root,a,b,x-1);
				c = new node(z);
				root = merge(merge(a,c),b);
			}
		} else if ( s[0] == 'D' ) { // delete
			cin >> x >> y;
			node *a, *b, *c;
			split(root,a,b,x-1);
			split(b,b,c,1);
			delete b;
			root = merge(a,c); 
		} else if ( s[0] == 'M' && s[2] == 'K' ) { // make-same
			cin >> x >> y >> z;
			node *a, *b, *c;
			split(root,a,b,x-1);
			split(b,b,c,y);
			cout << "ok1?\n";
			b->CHG(z);
			cout << "ok2?\n";
			merge(a,merge(b,c));
			cout << "ok3?\n";
		} else if ( s[0] == 'R' ) { // reverse
			cin >> x >> y;
			node *a, *b, *c;
			split(root,a,b,x-1);
			split(b,b,c,y);
			cout << "ok1?\n";
			b->REV();
			cout << "ok2?\n";
			merge(a,merge(b,c));
			cout << "ok3?\n";
		} else if ( s[0] == 'G' ) { // get sum
			cin >> x >> y;
			node *a, *b, *c;
			split(root,a,b,x-1);
			split(b,b,c,y);
			cout << b->sum << '\n';
			merge(a,merge(b,c));
		} else { // get max interval
			cout << root->ans << '\n';
		}
	}
	return 0;
}