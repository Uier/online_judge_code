#include<iostream>
using namespace std;
int main()
{
    int h, n;
    cin >> h;
    while( h-- )
    {
        cin >> n;
        for (int i=0;i<n;i++)
        {
            if (i == n-3)
            {
                for (int a=0;a<i*2+1;a++)
                {
                    cout << '*';
                }
                cout << "****";
            }
            else
            {
                for (int j=1;j<n-i;j++)
                {
                    cout << ' ';
                }
                for (int k=0;k<i*2+1;k++)
                {
                    cout << '*';
                }
            }
            cout << endl;
        }
        for (int p=0;p<n-3;p++)
        {
            cout << "   ";
            for (int q=0;q<p;q++)
            {
                cout << ' ';
            }
            for (int r=0;r<(n-4-p)*2+1;r++)
            {
                cout << '*';
            }
            cout << endl;
        }
    }
    return 0;
}
