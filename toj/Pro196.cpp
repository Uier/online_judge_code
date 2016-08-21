#include <stdio.h>
using namespace std;
int n, q, w, s[100005], min=100000, max=0;
bool md[200010];
void ac()
{
	for (int i = min*2; i < max*2+1; ++i)
		md[i] = false;
	for (int i = 0; i < n; ++i)
	{
		for (int j = n-1; j > i; --j)
			md[s[i]+s[j]] = true;
		md[s[i]*2] = true;
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &s[i]);
		md[s[i]*2] = true;
		if ( s[i] < min )
			min = s[i];
		if ( s[i] > max )
			max = s[i];
	}
	ac();
	scanf("%d", &q);
	while ( q-- )
	{
		scanf("%d", &w);
		if ( md[w] )
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}