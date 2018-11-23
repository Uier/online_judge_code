#include <stdio.h>
#include <vector>
#include <algorithm>
#define maxn 100005
using namespace std;
int arr[maxn];
struct node {
	int val;
	node *l, *r;
	node() {
		val = 0;
		l = r = NULL;
	}
	void pull() {
		val = l->val + r->val;
	}
} *root[maxn];
void build(node *cur, int l, int r) {
	if ( l == r )	return;
	int mid = l+r>>1;
	cur->l = new node();
	cur->r = new node();
	build(cur->l,l,mid);
	build(cur->r,mid+1,r);
}
void modify(node *pre, node *cur, int l, int r, int x) {
	if ( l == r && l == x ) {
		cur->val = pre->val+1;
		return;
	}
	int mid = l+r>>1;
	if ( x <= mid ) {
		cur->l = new node();
		cur->r = pre->r;
		modify(pre->l,cur->l,l,mid,x);
	} else {
		cur->l = pre->l;
		cur->r = new node();
		modify(pre->r,cur->r,mid+1,r,x);
	}
	cur->pull();
}
int query(node *a, node *b, int l, int r, int k) {
	if ( l == r )	return l;
	int mid = l+r>>1, val = b->l->val - a->l->val;
	if ( val >= k )	return query(a->l,b->l,l,mid,k);
	else	return query(a->r,b->r,mid+1,r,k-val);
}
int main() {
	int n, q, l, r, k;
	scanf("%d %d", &n, &q);
	vector<int> v;
	for ( int i=0; i<n; ++i )	scanf("%d", arr+i), v.push_back(arr[i]);
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	for ( int i=0; i<=n; ++i )	root[i] = new node();
	build(root[0],0,n-1);
	for ( int i=0; i<n; ++i ) {
		arr[i] = lower_bound(v.begin(),v.end(),arr[i])-v.begin();
		modify(root[i],root[i+1],0,n-1,arr[i]);
	}
	while ( q-- ) {
		scanf("%d %d %d", &l, &r, &k);
		printf("%d\n", v[query(root[l-1],root[r],0,n-1,k)]);
	}
	return 0;
}

