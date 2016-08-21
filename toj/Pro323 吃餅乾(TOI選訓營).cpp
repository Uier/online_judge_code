#include <bits/stdc++.h>
using namespace std;
int num[10000];

int lis(vector<int>& s)
{
    if ( s.size() == 0 )
        return 0;
    
    vector<int> v;
    v.push_back(s[0]);
    
    for ( int i=1; i<s.size(); i++ )
    {
        int a = s[i];
        if ( a > v.back() )
            v.push_back(a);
        else
            *lower_bound(v.begin(), v.end(), a) = a;
    }
    
    return v.size();
}

int main()
{
    int n, k;
    cin >> n >> k;
    for ( int i=0; i<n; i++ )
    {
        int a;
        cin >> a;
        num[a] = i;
    }
    while ( k-- )
    {
        vector<int> ad;
        ad.clear();
        for ( int i=0; i<n; i++ )
        {
            int a;
            cin >> a;
            ad.push_back(num[a]);
        }
        int res=0;
        res = lis(ad);
        cout << res << endl;
    }
    return 0;
}
