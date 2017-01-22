#include<iostream>
#include<cstring>
using namespace std;

int c[100000];
int prc[100000];
 
void change(int m, int p)
{
    memset(c, 0x7f, sizeof(c));
    c[0] = 0;

    for (int i = 0; i < p; ++i)
    {
        for (int j = prc[i]; j <= m; ++j)
            c[j] = min(c[j], c[j-prc[i]] + 1);
 	}
 	if ( c[m] == 2139062143 )
 		cout << -1 << endl;
 	else
    	cout << c[m] << endl;
}
int main()
{
	int n, m, i=0, kk=0;
	cin >> n;
	for ( int i=0 ; ; i++ )
	{
		cin >> prc[i];
		if ( prc[i] == 0 )
		{
			kk = i;
			break;
		}
	}
	change(n, kk);
}
