#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while ( getline(cin, s) )
    {
        long long tmp[100], r=0;
        for ( int i=0; i<100; i++ )
            tmp[i] = 0;
        for ( int i=0; i<s.size(); i++ )
        {
            long long x=0, y=0;
            if (s[i] == '/')
            {
                for ( int j=i-1, k=0; s[j]!=' '&&j>=0; j--, k++ )
                {
                    int kk=k;
                    int a=1;
                    while ( kk-- )
                    {
                        a *= 10;
                    }
                    x += a*(s[j]-'0');
                    s[j] = ' ';
                }
                int p=i;
                while ( (s[p] != ' ')&&p<s.size() )
                {
                    p++;
                }
                if ( p == s.size()-1 )
                    p++;
                for ( int j=p-1, k=0; j>i; j--, k++ )
                {
                    int kk=k;
                    int a=1;
                    while ( kk-- )
                    {
                        a *= 10;
                    }
                    y += a*(s[j]-'0');
                    s[j] = ' ';
                }
                if ( x%y == 0 )
                    tmp[r++] = x/y;
                s[i] = ' ';
            }
        }
        stringstream ss(s);
        long long n, all=0;
        while ( ss >> n )
        {
            all += n;
        }
        for ( int i=0; i<r; i++ )
            all += tmp[i];
        cout << all%1000000007 << endl;
    }
    return 0;
}
