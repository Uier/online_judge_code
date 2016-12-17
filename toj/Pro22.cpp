#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pr;
int n;
bool noway;
pr a[1005];
vector<pr> s;
bool cmp(pr x, pr y) {
	if ( x.first != y.first )	return x.first < y.first;
	return x.second > y.second;
}
main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &a[i].first, &a[i].second);
	sort(a,a+n,cmp);
//	for (int i = 0; i < n; ++i)
//		printf("%d %d\n", a[i].first, a[i].second);
	s.push_back(a[0]);
	for (int i = 1; i < n; ++i) {
		if ( a[i].first - 1 > s.back().second ) {
			noway = true;
			break;
		}
		else if ( a[i].second > s.back().second ) {
			for (int j = s.size()-1; j > 0; --j)
				if ( a[i].first - 1 <= s[j-1].second )
					s.pop_back();
			s.push_back(a[i]);
		}
	}
	if ( noway )	puts("NO");
	else	printf("%d\n", s.size());
//	for (int i = 0; i < s.size(); ++i)
//		printf("%d %d\n", s[i].first, s[i].second);
	return 0;
}
