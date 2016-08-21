#include <iostream>
using namespace std;
int a=0;
bool odtrue[10];
void kill(int n)
{
	if ( n == 1 )
		return;
	if ( n%2 == 1 )
		odtrue[a++] = true;
	else
		odtrue[a++] = false;
	kill(n/2);
}
int main(int argc, char const *argv[])
{
	int n, ans=1;
	cin >> n;
	a = 0;
	for ( int i=0; i<10; i++ )
		odtrue[i] = 0;
	kill(n);
	for ( int i=a-1; i>=0; i-- )
	{
		if ( odtrue[i] )
			ans = ans*2+1;
		else
			ans = ans*2-1;
	}
	cout << ans << endl;
	return 0;
}