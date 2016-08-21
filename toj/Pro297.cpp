#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, a;
    
    multiset<int> cld;
    cld.clear();
    
    while ( scanf("%d", &n) )
    {
        if ( n == 0 )
            break;
        else if ( n == -1 )
        {
            if ( cld.size() != 0 )
            {
                a = 0;
                a = *cld.begin();
                printf("%d ", a);	
                cld.erase(cld.find(a));	// erase(位址) 消一個
 		    //	cld.erase(a);			// erase(數值) 消全部    
            }
        }
        else if ( n == -2 )
        {
            if ( cld.size() != 0 )
            {
                a = 0;
                a = *cld.rbegin();
                printf("%d ", a);
                cld.erase(cld.find(a));
            //	cld.erase(a);
            }
        }
        else
            cld.insert(n);
    }
    cout << '\n';
    
    return 0;
}
