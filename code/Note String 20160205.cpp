#include<sstream>
#include<iostream>
using namespace std;
int main()
{
//	########	S t r i n g 
/*	
#include<string>
	string s1;
	s1 = "123456";
	s1.substr(2,3); // = s[2]往後抓3個字元 
*/
//************************** 
	string s;
	while ( getline(cin, s) )
	{
		//stringstream ss;
		
		
		istringstream iss(s);
		int n;
		int sum=0;
		while ( iss >> n )
		{
			sum += n;
		}
		cout << sum << endl;
		//  讀進iss 

		ostringstream oss;
		oss << 33 << ' ' << "jdkfsd" << endl;
		cout << oss.str() << endl;
	}
		
//	Big Number
	
	return 0;
}

