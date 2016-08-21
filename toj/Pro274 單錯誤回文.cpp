#include<iostream>
using namespace std;
int main()
{
    int n;
    string rs;
    cin >> n;
    while( n-- )
    {
    	int len=0, mid=0, fl=0, a=0, z=0;
        cin >> rs;
        len = rs.size();
        mid = len / 2;
        if ( len == 2 )
        {
        	if ( rs[0] == rs[1] )
        		cout << "YES" << endl;
        	else
        		cout << "NO" << endl;
        }
        else if ( len == 3 )
        {
			if ( rs[0] == rs[1] || rs[1] == rs[2] || rs[0] == rs[2] )
        		cout << "YES" << endl;
        	else
        		cout << "NO" << endl;
    	}
		else
        {
	        for ( int i=0; i<mid; i++ )
	        {
	        	len--;
	            if ( rs[i] != rs[len] )
	            {
	   	 		    if ( fl == 1 )
					{
	  	        		i = a;
	  	        		len = z;
	  	        		fl = 2;
	  	        		i--;
					}
					else if ( fl == 2 )
					{
						fl = 3;
						break;
					}
					else
					{
						fl = 1;
						a = i;
	  	        		z = len;
	  	        		len++;
	  	        	}
			    }
			    if ( i == len )
			    	break;
	        }
	        if ( fl == 3 )
	        	cout << "NO" << endl;
	        else
	        	cout << "YES" << endl;
	    } 
    }
    return 0;
}

