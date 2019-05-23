#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxn 500005
typedef struct TrieNode {
	struct TrieNode *son[26];
	char val;
	int cnt;
	bool isEnd;
	struct TrieNode *fail_link;
} node;
typedef struct QueueData {
	node *cur;
	node *fa_fail;
} data;
node *init(char val) {
	node *root = (node*)malloc(sizeof(node));
	for(int i = 0; i < 26; i++)
		root->son[i] = NULL;
	root->val = val;
	root->cnt = 0;
	root->isEnd = 0;
	return root;
}
void insert(node *root, char *s) {
	for ( int i=0; s[i]!='\0'; ++i ) {
		if ( root->son[s[i]-'a'] == NULL )
			root->son[s[i]-'a'] = init(s[i]);
		root = root->son[s[i]-'a'];
	}
	root->isEnd = 1;
}
data Q[maxn];
void build_fail_link(node *root) {
	root->fail_link = root;
	int Ql = 0, Qr = 0;
	for ( int i=0; i<26; ++i ) {
		if ( root->son[i] ) {
			root->son[i]->fail_link = root;
			for ( int j=0; j<26; ++j ) {
				if ( root->son[i]->son[j] ) {
					Q[Qr].cur = root->son[i]->son[j];
					Q[Qr++].fa_fail = root;
				}
			}
		}
	}
	while ( Ql < Qr ) {
		node *cur = Q[Ql].cur;
		node *fa_fail = Q[(Ql++)%maxn].fa_fail;
		while ( !fa_fail->son[cur->val-'a'] ) {
			if ( fa_fail == root )	break;
			fa_fail = fa_fail->fail_link;
		}
		if ( fa_fail->son[cur->val-'a'] )
			cur->fail_link = fa_fail->son[cur->val-'a'];
		else
			cur->fail_link = root;
		for ( int i=0; i<26; ++i ) {
			if ( cur->son[i] ) {
				Q[Qr].cur = cur->son[i];
				Q[(Qr++)%maxn].fa_fail = cur->fail_link;
			}
		}
	}
}
void calc(node *root) {
	while ( root->val != '\0' ) {
		if ( root->isEnd )	root->cnt++;
		root = root->fail_link;
	}
}
void query(node *root, char *s) {
	for ( int i=0; s[i]!='\0'; ++i ) {
		if ( root->son[s[i]-'a'] ) {
			root = root->son[s[i]-'a'];
			calc(root);
		} else {
			if ( root->val == '\0' ) // root
				continue;
			else {
				root = root->fail_link;
				calc(root);
				--i;
			}
		}
	}
}
int mx_cnt, anspt;
char tmp[75], ans[155][75];
void rmv(node *root, int idx) {
	printf("val, cnt: %c %d\n", root->val, root->cnt);
	if ( root->cnt > mx_cnt ) {
		anspt = 0;
		for ( int i=0; i<idx; ++i )	ans[anspt][i] = tmp[i];
		ans[anspt++][idx] = '\0';
		mx_cnt = root->cnt;
	} else if ( root->cnt == mx_cnt ) {
		for ( int i=0; i<idx; ++i )	ans[anspt][i] = tmp[i];
		ans[anspt++][idx] = '\0';
	}
	for ( int i=0; i<26; ++i )
		if ( root->son[i] ) {
			tmp[idx] = 'a'+i;
			rmv(root->son[i], idx+1);
		}
	free(root);
}
char s[75], t[1000005];
int main() {
	int n;
	while ( scanf("%d", &n) && n ) {
		node *root = init('\0');
    	for ( int i=0; i<n; ++i ) {
        	scanf("%s", s);
        	insert(root,s);
        }
        build_fail_link(root);
        scanf("%s", t);
        query(root, t);
        mx_cnt = 0;
        anspt = 0;
        rmv(root,0);
        printf("%d\n", mx_cnt);
        for ( int i=0; i<anspt; ++i )
        	printf("%s\n", ans[i]);  
	}
	return 0;
}