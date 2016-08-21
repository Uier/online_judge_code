#include<iostream>
#include <sstream>
using namespace std;
int main()
{
	int n;
	string s;
	while ( getline(cin,s) )
	{
		n=0;
		if ( s == "" )
			n=0;
		else if ( s[0] != ' ' )
			n=1;
		for ( int i=1; i<s.size(); i++ )
		{
			if ( (s[i] != ' ') && (s[i-1] == ' ') )
				n++;
		}
		cout << n << endl;
	} 
	/* 
	
	«a°aªºcode 
	
	long long t=0;
	string s;
	while(getline(cin,s)){
		t=0;
		istringstream iss(s);
		iss >> s;
		long long n;
		while(iss>>n)
		{
			t+=1;
		}
		if(t==0){
			cout << 0 <<endl;
		}else{
			cout << t+1 << endl;
		}
 
	} 
	*/ 
	return 0;
}

