#include<iostream>
#include<sstream>
using namespace std;
int main()
{
	string s;
	while ( getline(cin,s) )
	{
		long long n, sum=0;
		string tp;
		istringstream iss(s);
		while ( iss >> tp )
		{
			int x=0;
			for(int i=0;i<tp.size();++i)
			{
				if ( (tp[i]>='0') && (tp[i]<='9') )
						
			}
		}
		cout << sum << endl;
	}
	return 0;
}

