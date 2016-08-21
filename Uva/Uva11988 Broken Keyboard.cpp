#include<bits/stdc++.h>
using namespace std;

deque<char> dq;
stack<char> stk;

void stk_to_dq()
{
	while ( !stk.empty() )
	{
		dq.push_front(stk.top());
		stk.pop();
	}
}

int main()
{
	string s;
	int flag=-1;
	while ( getline(cin,s) )
	{
		dq.clear();
		flag=-1;
		for ( int i=0; i<s.size(); i++ )
		{
			if ( s[i] == '[' )
			{
				flag++;
				continue;
			}
			if ( s[i] == ']' )
			{
				stk_to_dq();
				flag=-1;
				continue;
			}
			if ( flag == -1 )
				dq.push_back(s[i]);  
			else if ( flag == 0 )
				stk.push(s[i]);
			else if ( flag > 0 )
			{
				stk_to_dq();
				stk.push(s[i]);
				flag = 0;
			}
			if ( (i == s.size()-1) && (!stk.empty()) )
				stk_to_dq();
		}
		for ( char a : dq )
			cout << a;
		cout << endl;
	}
	return 0;
}
