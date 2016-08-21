#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    while ( cin >> n )
    {
        for ( int i=0; i<n; i++ )
        {
            for ( int j=0; j<n-i-1; j++ )
                cout << ' ';
            for ( int k=0; k<i*2+1; k++ )
                cout << (char)(65+i-abs(i-k));
            cout << endl;
        }
        for ( int i=n-2; i>=0; i-- )
        {
            for ( int k=0; k<n-i-1; k++ )
                cout << ' ';
            for ( int j=0; j<i*2+1; j++ )
                cout << (char)(65+i-abs(i-j));
            cout << endl;
        }
    }
    return 0;
}